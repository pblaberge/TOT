#pragma once

#include <string>
#include <memory>

class error
{
public:
    using ptr = std::unique_ptr<error>;

    error();
    virtual ~error();

    virtual std::string Error() = 0;

    static ptr New(std::string);

    template<typename T>
    static bool Is(error * e)
    {
        if (T* p = dynamic_cast<T*>(e)) {
            return true;
        }
        return false;
    }

    template<typename T>
    static bool Is(error::ptr const& e)
    {
        if (T* p = dynamic_cast<T*>(e.get())) {
            return true;
        }
        return false;
    }

};
