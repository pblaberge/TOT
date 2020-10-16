#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "cpp/os/exec/exec.h"

namespace os {
namespace exec {

namespace {

class UnixCmd final : public Cmd {
 public:
  UnixCmd(std::string name, std::vector<std::string> args);

  ~UnixCmd() final;

  error::ptr Start() final;
  error::ptr Wait() final;
  error::ptr Run() final;

  std::pair<std::vector<std::uint8_t>, error::ptr> Output() final;
  std::pair<std::vector<std::uint8_t>, error::ptr> CombinedOutput() final;

  std::pair<io::ReadCloser::ptr, error::ptr> StderrPipe() final;
  std::pair<io::WriteCloser::ptr, error::ptr> StdinPipe() final;
  std::pair<io::ReadCloser::ptr, error::ptr> StdoutPipe() final;

 private:
  error::ptr startChild();
  error::ptr startParent();

  error::ptr setStdin();
  error::ptr setStdout();
  error::ptr setStderr();
  error::ptr setOtherFiles();

  pid_t pid;
};

UnixCmd::UnixCmd(std::string name_, std::vector<std::string> args_)
    : Cmd(), pid(0) {
  path = std::move(name_);
  args = std::move(args_);
}

UnixCmd::~UnixCmd() = default;

error::ptr UnixCmd::Start() {
  switch (int p = fork()) {
    case 0:
      startChild();
      // Does not return;
      return error::New("exec: startChild returned!");
    case -1:
      return error::New("exec: Could not fork");
    default:  // Parent
      pid = p;
      startParent();
      return nullptr;
  }
}

error::ptr UnixCmd::startParent() {
  stdin = nullptr;
  stdout = nullptr;
  stderr = nullptr;

  return nullptr;
}

error::ptr UnixCmd::Wait() {
  int status;
  waitpid(pid, &status, 0);
  return nullptr;
}

error::ptr UnixCmd::Run() {
  if (error::ptr e = Start(); e != nullptr) {
    return e;
  }

  if (error::ptr e = Wait(); e != nullptr) {
    return e;
  }
  return nullptr;
}

error::ptr UnixCmd::startChild() {
  if (error::ptr e = setStdin(); e != nullptr) {
    return e;
  }

  if (error::ptr e = setStdout(); e != nullptr) {
    return e;
  }

  if (error::ptr e = setStderr(); e != nullptr) {
    return e;
  }

  if (error::ptr e = setOtherFiles(); e != nullptr) {
    return e;
  }

  std::vector<char*> c_args;
  c_args.reserve(args.size() + 1);

  for (std::string& s : args) {
    c_args.emplace_back(s.data());
  }
  c_args.emplace_back(nullptr);

  if (env.has_value()) {
    std::vector<char*> c_env;
    c_env.reserve(env->size() + 1);
    for (std::string& s : *env) {
      c_env.emplace_back(s.data());
    }
    c_env.emplace_back(nullptr);

    execve(path.c_str(), c_args.data(), c_env.data());
    std::exit(-1);
  }
  execve(path.c_str(), c_args.data(), environ);
  std::exit(-1);
}

error::ptr UnixCmd::setStdin() {
  if (stdin) {
    dup2(stdin->Fd(), 0);
    stdin = nullptr;
  } else {
    dup2(DevNull->Fd(), 0);
  }
  return nullptr;
}

error::ptr UnixCmd::setStdout() {
  if (stdout) {
    dup2(stdout->Fd(), 1);
    stdout = nullptr;
  } else {
    dup2(DevNull->Fd(), 1);
  }
  return nullptr;
}

error::ptr UnixCmd::setStderr() {
  if (stderr) {
    dup2(stderr->Fd(), 2);
    stderr = nullptr;
  } else {
    dup2(DevNull->Fd(), 2);
  }
  return nullptr;
}

error::ptr UnixCmd::setOtherFiles() {
  for (std::size_t i = 0; i < extra_files.size(); ++i) {
    if (!extra_files[i]) {
      continue;
    }
    dup2(extra_files[i]->Fd(), i + 3);
    extra_files[i] = nullptr;
  }
  return nullptr;
}

std::pair<io::WriteCloser::ptr, error::ptr> UnixCmd::StdinPipe() {
  if (stdin != nullptr) {
    return {nullptr, error::New("exec: Stdin already set")};
  }

  if (pid != 0) {
    return {nullptr, error::New("exec: StdinPipe after process started")};
  }

  auto [pr, pw, err] = Pipe();
  if (err != nullptr) {
    return {nullptr, std::move(err)};
  }

  stdin = std::move(pr);
  return {std::move(pw), nullptr};
}

std::pair<io::ReadCloser::ptr, error::ptr> UnixCmd::StdoutPipe() {
  if (stdout != nullptr) {
    return {nullptr, error::New("exec: Stdout already set")};
  }
  if (pid != 0) {
    return {nullptr, error::New("exec: StdoutPipe after process started")};
  }
  auto [pr, pw, err] = Pipe();
  if (err != nullptr) {
    return {nullptr, std::move(err)};
  }

  stdout = std::move(pw);
  return {std::move(pr), nullptr};
}

std::pair<io::ReadCloser::ptr, error::ptr> UnixCmd::StderrPipe() {
  if (stderr != nullptr) {
    return {nullptr, error::New("exec: Stderr already set")};
  }
  if (pid != 0) {
    return {nullptr, error::New("exec: StderrPipe after process started")};
  }
  auto [pr, pw, err] = Pipe();
  if (err != nullptr) {
    return {nullptr, std::move(err)};
  }

  stderr = std::move(pw);
  return {std::move(pr), nullptr};
}

std::pair<std::vector<std::uint8_t>, error::ptr> UnixCmd::Output() {
  auto [stdout_p, err] = StdoutPipe();
  if (err != nullptr) {
    return {{}, std::move(err)};
  }

  if (err = Run(); err != nullptr) {
    return {{}, std::move(err)};
  }

  std::vector<std::uint8_t> rv;
  rv.resize(256);

  std::size_t i = 0;

  for (auto [n, err_r] = stdout_p->Read({rv.data() + i, rv.size() - i});
       (n > 0) || (err_r != nullptr);) {
    if (err_r != nullptr) {
      return {{}, std::move(err_r)};
    }

    i += n;
    if (i >= rv.size()) {
      rv.resize(rv.size() * 2);
    }
  }

  rv.resize(i);

  return {rv, nullptr};
}

std::pair<std::vector<std::uint8_t>, error::ptr> UnixCmd::CombinedOutput() {
  return {{}, nullptr};
}

}  // namespace

Cmd::Cmd() = default;
Cmd::~Cmd() = default;

Cmd::ptr Command(std::string name, std::vector<std::string> args) {
  return std::make_unique<UnixCmd>(std::move(name), std::move(args));
}

}  // namespace exec
}  // namespace os
