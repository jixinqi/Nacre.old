#ifndef _NACRE_ROUTE_H_
#define _NACRE_ROUTE_H_

namespace nacre
{
    class route : public manager<method, handle>
    {
    public:
        virtual ~route() = default;
        using manager<method, handle>::manager;

    protected:
    private:
    };
}

#endif
