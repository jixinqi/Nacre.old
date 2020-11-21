#ifndef _NACRE_APPLICATION_H_
#define _NACRE_APPLICATION_H_

namespace nacre
{
    class application
    {
    public:
        application() = default;
        virtual ~application() = default;

        route_manager routes;

    protected:
    private:
    };
}

#endif
