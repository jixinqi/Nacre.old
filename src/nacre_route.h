#ifndef _NACRE_ROUTE_H_
#define _NACRE_ROUTE_H_

namespace nacre
{
    class route
    {
    public:
        route() = default;
        virtual ~route() = default;

    protected:
    private:
    };
    
    class route_manager : public manager<uri, route>
    {
    public:
        route_manager() = default;
        virtual ~route_manager() = default;

    protected:
    private:
    };
}

#endif
