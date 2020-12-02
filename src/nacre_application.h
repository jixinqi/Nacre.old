#ifndef _NACRE_APPLICATION_H_
#define _NACRE_APPLICATION_H_

namespace nacre
{
    class application
    {
    public:
        application() = default;
        virtual ~application() = default;

        manager<uri, route> routes;

    protected:
    private:
    };
}

#endif
