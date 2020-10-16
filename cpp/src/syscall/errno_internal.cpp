#include "cpp/src/syscall/errno_internal.hpp"

namespace {

constexpr std::int64_t LOCAL_eacces = EACCES;
constexpr std::int64_t LOCAL_eaddrinuse = EADDRINUSE;
constexpr std::int64_t LOCAL_eaddrnotavail = EADDRNOTAVAIL;
constexpr std::int64_t LOCAL_eafnosupport = EAFNOSUPPORT;
constexpr std::int64_t LOCAL_eagain = EAGAIN;
constexpr std::int64_t LOCAL_ealready = EALREADY;
constexpr std::int64_t LOCAL_ebade = EBADE;
constexpr std::int64_t LOCAL_ebadf = EBADF;
constexpr std::int64_t LOCAL_ebadfd = EBADFD;
constexpr std::int64_t LOCAL_ebadmsg = EBADMSG;
constexpr std::int64_t LOCAL_ebadr = EBADR;
constexpr std::int64_t LOCAL_ebadrqc = EBADRQC;
constexpr std::int64_t LOCAL_ebadslt = EBADSLT;
constexpr std::int64_t LOCAL_ebusy = EBUSY;
constexpr std::int64_t LOCAL_ecanceled = ECANCELED;
constexpr std::int64_t LOCAL_echild = ECHILD;
constexpr std::int64_t LOCAL_echrng = ECHRNG;
constexpr std::int64_t LOCAL_ecomm = ECOMM;
constexpr std::int64_t LOCAL_econnaborted = ECONNABORTED;
constexpr std::int64_t LOCAL_econnrefused = ECONNREFUSED;
constexpr std::int64_t LOCAL_econnreset = ECONNRESET;
constexpr std::int64_t LOCAL_edeadlk = EDEADLK;
constexpr std::int64_t LOCAL_edestaddrreq = EDESTADDRREQ;
constexpr std::int64_t LOCAL_edom = EDOM;
constexpr std::int64_t LOCAL_edquot = EDQUOT;
constexpr std::int64_t LOCAL_eexist = EEXIST;
constexpr std::int64_t LOCAL_efault = EFAULT;
constexpr std::int64_t LOCAL_efbig = EFBIG;
constexpr std::int64_t LOCAL_ehostdown = EHOSTDOWN;
constexpr std::int64_t LOCAL_ehostunreach = EHOSTUNREACH;
constexpr std::int64_t LOCAL_ehwpoison = EHWPOISON;
constexpr std::int64_t LOCAL_eidrm = EIDRM;
constexpr std::int64_t LOCAL_eilseq = EILSEQ;
constexpr std::int64_t LOCAL_einprogress = EINPROGRESS;
constexpr std::int64_t LOCAL_eintr = EINTR;
constexpr std::int64_t LOCAL_einval = EINVAL;
constexpr std::int64_t LOCAL_eio = EIO;
constexpr std::int64_t LOCAL_eisconn = EISCONN;
constexpr std::int64_t LOCAL_eisdir = EISDIR;
constexpr std::int64_t LOCAL_eisnam = EISNAM;
constexpr std::int64_t LOCAL_ekeyexpired = EKEYEXPIRED;
constexpr std::int64_t LOCAL_ekeyrejected = EKEYREJECTED;
constexpr std::int64_t LOCAL_ekeyrevoked = EKEYREVOKED;
constexpr std::int64_t LOCAL_elibacc = ELIBACC;
constexpr std::int64_t LOCAL_elibbad = ELIBBAD;
constexpr std::int64_t LOCAL_elibexec = ELIBEXEC;
constexpr std::int64_t LOCAL_elibmax = ELIBMAX;
constexpr std::int64_t LOCAL_elibscn = ELIBSCN;
constexpr std::int64_t LOCAL_eloop = ELOOP;
constexpr std::int64_t LOCAL_emediumtype = EMEDIUMTYPE;
constexpr std::int64_t LOCAL_emfile = EMFILE;
constexpr std::int64_t LOCAL_emlink = EMLINK;
constexpr std::int64_t LOCAL_emsgsize = EMSGSIZE;
constexpr std::int64_t LOCAL_emultihop = EMULTIHOP;
constexpr std::int64_t LOCAL_enametoolong = ENAMETOOLONG;
constexpr std::int64_t LOCAL_enetdown = ENETDOWN;
constexpr std::int64_t LOCAL_enetreset = ENETRESET;
constexpr std::int64_t LOCAL_enetunreach = ENETUNREACH;
constexpr std::int64_t LOCAL_enfile = ENFILE;
constexpr std::int64_t LOCAL_enoano = ENOANO;
constexpr std::int64_t LOCAL_enobufs = ENOBUFS;
constexpr std::int64_t LOCAL_enodata = ENODATA;
constexpr std::int64_t LOCAL_enodev = ENODEV;
constexpr std::int64_t LOCAL_enoent = ENOENT;
constexpr std::int64_t LOCAL_enoexec = ENOEXEC;
constexpr std::int64_t LOCAL_enokey = ENOKEY;
constexpr std::int64_t LOCAL_enolck = ENOLCK;
constexpr std::int64_t LOCAL_enolink = ENOLINK;
constexpr std::int64_t LOCAL_enomedium = ENOMEDIUM;
constexpr std::int64_t LOCAL_enomem = ENOMEM;
constexpr std::int64_t LOCAL_enomsg = ENOMSG;
constexpr std::int64_t LOCAL_enonet = ENONET;
constexpr std::int64_t LOCAL_enopkg = ENOPKG;
constexpr std::int64_t LOCAL_enoprotoopt = ENOPROTOOPT;
constexpr std::int64_t LOCAL_enospc = ENOSPC;
constexpr std::int64_t LOCAL_enosr = ENOSR;
constexpr std::int64_t LOCAL_enostr = ENOSTR;
constexpr std::int64_t LOCAL_enosys = ENOSYS;
constexpr std::int64_t LOCAL_enotblk = ENOTBLK;
constexpr std::int64_t LOCAL_enotconn = ENOTCONN;
constexpr std::int64_t LOCAL_enotdir = ENOTDIR;
constexpr std::int64_t LOCAL_enotempty = ENOTEMPTY;
constexpr std::int64_t LOCAL_enotrecoverable = ENOTRECOVERABLE;
constexpr std::int64_t LOCAL_enotsock = ENOTSOCK;
constexpr std::int64_t LOCAL_enotsup = ENOTSUP;
constexpr std::int64_t LOCAL_enotty = ENOTTY;
constexpr std::int64_t LOCAL_enotuniq = ENOTUNIQ;
constexpr std::int64_t LOCAL_enxio = ENXIO;
constexpr std::int64_t LOCAL_eoverflow = EOVERFLOW;
constexpr std::int64_t LOCAL_eownerdead = EOWNERDEAD;
constexpr std::int64_t LOCAL_eperm = EPERM;
constexpr std::int64_t LOCAL_epfnosupport = EPFNOSUPPORT;
constexpr std::int64_t LOCAL_epipe = EPIPE;
constexpr std::int64_t LOCAL_eproto = EPROTO;
constexpr std::int64_t LOCAL_eprotonosupport = EPROTONOSUPPORT;
constexpr std::int64_t LOCAL_eprototype = EPROTOTYPE;
constexpr std::int64_t LOCAL_erange = ERANGE;
constexpr std::int64_t LOCAL_eremchg = EREMCHG;
constexpr std::int64_t LOCAL_eremote = EREMOTE;
constexpr std::int64_t LOCAL_eremoteio = EREMOTEIO;
constexpr std::int64_t LOCAL_erestart = ERESTART;
constexpr std::int64_t LOCAL_erfkill = ERFKILL;
constexpr std::int64_t LOCAL_erofs = EROFS;
constexpr std::int64_t LOCAL_eshutdown = ESHUTDOWN;
constexpr std::int64_t LOCAL_esocktnosupport = ESOCKTNOSUPPORT;
constexpr std::int64_t LOCAL_espipe = ESPIPE;
constexpr std::int64_t LOCAL_esrch = ESRCH;
constexpr std::int64_t LOCAL_estale = ESTALE;
constexpr std::int64_t LOCAL_estrpipe = ESTRPIPE;
constexpr std::int64_t LOCAL_etime = ETIME;
constexpr std::int64_t LOCAL_etimedout = ETIMEDOUT;
constexpr std::int64_t LOCAL_etoomanyrefs = ETOOMANYREFS;
constexpr std::int64_t LOCAL_etxtbsy = ETXTBSY;
constexpr std::int64_t LOCAL_euclean = EUCLEAN;
constexpr std::int64_t LOCAL_eunatch = EUNATCH;
constexpr std::int64_t LOCAL_eusers = EUSERS;
constexpr std::int64_t LOCAL_exdev = EXDEV;
constexpr std::int64_t LOCAL_exfull = EXFULL;
constexpr std::int64_t LOCAL_e2big = E2BIG;
constexpr std::int64_t LOCAL_el2hlt = EL2HLT;
constexpr std::int64_t LOCAL_el2nsync = EL2NSYNC;
constexpr std::int64_t LOCAL_el3hlt = EL3HLT;
constexpr std::int64_t LOCAL_el3rst = EL3RST;

}  // namespace

#include "cpp/syscall.hpp"

namespace sys_call {
namespace internal {

#define ERRNO_CASE(X, Y) \
  case LOCAL_ ## X:          \
    return std::make_unique<Y>();

error::ptr err_from_errno() {
  switch (errno) {
    ERRNO_CASE(e2big, E2BIG)
    ERRNO_CASE(eacces, EACCES)
    ERRNO_CASE(eaddrinuse, EADDRINUSE)
    ERRNO_CASE(eaddrnotavail, EADDRNOTAVAIL)
    ERRNO_CASE(eafnosupport, EAFNOSUPPORT)
    ERRNO_CASE(eagain, EAGAIN)
    ERRNO_CASE(ealready, EALREADY)
    ERRNO_CASE(ebade, EBADE)
    ERRNO_CASE(ebadf, EBADF)
    ERRNO_CASE(ebadfd, EBADFD)
    ERRNO_CASE(ebadmsg, EBADMSG)
    ERRNO_CASE(ebadr, EBADR)
    ERRNO_CASE(ebadrqc, EBADRQC)
    ERRNO_CASE(ebadslt, EBADSLT)
    ERRNO_CASE(ebusy, EBUSY)
    ERRNO_CASE(ecanceled, ECANCELED)
    ERRNO_CASE(echild, ECHILD)
    ERRNO_CASE(echrng, ECHRNG)
    ERRNO_CASE(ecomm, ECOMM)
    ERRNO_CASE(econnaborted, ECONNABORTED)
    ERRNO_CASE(econnrefused, ECONNREFUSED)
    ERRNO_CASE(econnreset, ECONNRESET)
    ERRNO_CASE(edeadlk, EDEADLK)
    ERRNO_CASE(edestaddrreq, EDESTADDRREQ)
    ERRNO_CASE(edom, EDOM)
    ERRNO_CASE(edquot, EDQUOT)
    ERRNO_CASE(eexist, EEXIST)
    ERRNO_CASE(efault, EFAULT)
    ERRNO_CASE(efbig, EFBIG)
    ERRNO_CASE(ehostdown, EHOSTDOWN)
    ERRNO_CASE(ehostunreach, EHOSTUNREACH)
    ERRNO_CASE(ehwpoison, EHWPOISON)
    ERRNO_CASE(eidrm, EIDRM)
    ERRNO_CASE(eilseq, EILSEQ)
    ERRNO_CASE(einprogress, EINPROGRESS)
    ERRNO_CASE(eintr, EINTR)
    ERRNO_CASE(einval, EINVAL)
    ERRNO_CASE(eio, EIO)
    ERRNO_CASE(eisconn, EISCONN)
    ERRNO_CASE(eisdir, EISDIR)
    ERRNO_CASE(eisnam, EISNAM)
    ERRNO_CASE(ekeyexpired, EKEYEXPIRED)
    ERRNO_CASE(ekeyrejected, EKEYREJECTED)
    ERRNO_CASE(ekeyrevoked, EKEYREVOKED)
    ERRNO_CASE(el2hlt, EL2HLT)
    ERRNO_CASE(el2nsync, EL2NSYNC)
    ERRNO_CASE(el3hlt, EL3HLT)
    ERRNO_CASE(el3rst, EL3RST)
    ERRNO_CASE(elibacc, ELIBACC)
    ERRNO_CASE(elibbad, ELIBBAD)
    ERRNO_CASE(elibmax, ELIBMAX)
    ERRNO_CASE(elibscn, ELIBSCN)
    ERRNO_CASE(elibexec, ELIBEXEC)
    ERRNO_CASE(eloop, ELOOP)
    ERRNO_CASE(emediumtype, EMEDIUMTYPE)
    ERRNO_CASE(emfile, EMFILE)
    ERRNO_CASE(emlink, EMLINK)
    ERRNO_CASE(emsgsize, EMSGSIZE)
    ERRNO_CASE(emultihop, EMULTIHOP)
    ERRNO_CASE(enametoolong, ENAMETOOLONG)
    ERRNO_CASE(enetdown, ENETDOWN)
    ERRNO_CASE(enetreset, ENETRESET)
    ERRNO_CASE(enetunreach, ENETUNREACH)
    ERRNO_CASE(enfile, ENFILE)
    ERRNO_CASE(enoano, ENOANO)
    ERRNO_CASE(enobufs, ENOBUFS)
    ERRNO_CASE(enodata, ENODATA)
    ERRNO_CASE(enodev, ENODEV)
    ERRNO_CASE(enoent, ENOENT)
    ERRNO_CASE(enoexec, ENOEXEC)
    ERRNO_CASE(enokey, ENOKEY)
    ERRNO_CASE(enolck, ENOLCK)
    ERRNO_CASE(enolink, ENOLINK)
    ERRNO_CASE(enomedium, ENOMEDIUM)
    ERRNO_CASE(enomem, ENOMEM)
    ERRNO_CASE(enomsg, ENOMSG)
    ERRNO_CASE(enonet, ENONET)
    ERRNO_CASE(enopkg, ENOPKG)
    ERRNO_CASE(enoprotoopt, ENOPROTOOPT)
    ERRNO_CASE(enospc, ENOSPC)
    ERRNO_CASE(enosr, ENOSR)
    ERRNO_CASE(enostr, ENOSTR)
    ERRNO_CASE(enosys, ENOSYS)
    ERRNO_CASE(enotblk, ENOTBLK)
    ERRNO_CASE(enotconn, ENOTCONN)
    ERRNO_CASE(enotdir, ENOTDIR)
    ERRNO_CASE(enotempty, ENOTEMPTY)
    ERRNO_CASE(enotrecoverable, ENOTRECOVERABLE)
    ERRNO_CASE(enotsock, ENOTSOCK)
    ERRNO_CASE(enotsup, ENOTSUP)
    ERRNO_CASE(enotty, ENOTTY)
    ERRNO_CASE(enotuniq, ENOTUNIQ)
    ERRNO_CASE(enxio, ENXIO)
    ERRNO_CASE(eoverflow, EOVERFLOW)
    ERRNO_CASE(eownerdead, EOWNERDEAD)
    ERRNO_CASE(eperm, EPERM)
    ERRNO_CASE(epfnosupport, EPFNOSUPPORT)
    ERRNO_CASE(epipe, EPIPE)
    ERRNO_CASE(eproto, EPROTO)
    ERRNO_CASE(eprotonosupport, EPROTONOSUPPORT)
    ERRNO_CASE(eprototype, EPROTOTYPE)
    ERRNO_CASE(erange, ERANGE)
    ERRNO_CASE(eremchg, EREMCHG)
    ERRNO_CASE(eremote, EREMOTE)
    ERRNO_CASE(eremoteio, EREMOTEIO)
    ERRNO_CASE(erestart, ERESTART)
    ERRNO_CASE(erfkill, ERFKILL)
    ERRNO_CASE(erofs, EROFS)
    ERRNO_CASE(eshutdown, ESHUTDOWN)
    ERRNO_CASE(espipe, ESPIPE)
    ERRNO_CASE(esocktnosupport, ESOCKTNOSUPPORT)
    ERRNO_CASE(esrch, ESRCH)
    ERRNO_CASE(estale, ESTALE)
    ERRNO_CASE(estrpipe, ESTRPIPE)
    ERRNO_CASE(etime, ETIME)
    ERRNO_CASE(etimedout, ETIMEDOUT)
    ERRNO_CASE(etoomanyrefs, ETOOMANYREFS)
    ERRNO_CASE(etxtbsy, ETXTBSY)
    ERRNO_CASE(euclean, EUCLEAN)
    ERRNO_CASE(eunatch, EUNATCH)
    ERRNO_CASE(eusers, EUSERS)
    ERRNO_CASE(exdev, EXDEV)
    ERRNO_CASE(exfull, EXFULL)
    default:
      std::terminate();
  }
}

#undef ERRNO_CASE
}  // namespace internal
}  // namespace sys_call
