#ifndef _NACRE_ENVIRONMENT_H_
#define _NACRE_ENVIRONMENT_H_

namespace nacre
{
    class environment
    {
    public:
        environment() = default;
        virtual ~environment() = default;

        manager<std::string, application> apps;

    protected:
    private:
    };
}

#endif

