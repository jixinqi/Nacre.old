#ifndef _NACRE_URI_H_
#define _NACRE_URI_H_

namespace nacre
{
    class uri
    {
    public:
        uri() = delete;

        template<typename Value_T>
        uri(Value_T && _value);
        
        const bool operator<(const uri& other) const;
        
        const std::string value;

    protected:
    private:
    };
}

template<typename Value_T>
nacre::uri::uri(Value_T && _value)
: value(std::forward<std::string>(_value))
{
}

#endif
