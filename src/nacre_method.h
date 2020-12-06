#ifndef _NACRE_METHOD_H_
#define _NACRE_METHOD_H_

namespace nacre
{
    enum http_method
    {
        GET,
        POST
    };

    class method
    {
    public:

        template<typename Method>
        method(Method && _value)
            : value(magic_enum::enum_cast<http_method>(_value).value())
        {
        }

        const bool operator<(const method& other) const;

        const http_method value;
    };
}

#endif
