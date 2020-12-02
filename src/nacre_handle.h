#ifndef _NACRE_HANDLE_H_
#define _NACRE_HANDLE_H_

namespace nacre
{
    typedef std::function<void(void)> handle_type;

    class handle
    {
    public:
        handle() = default;
        handle(handle_type f);
        virtual ~handle() = default;
        
        void run();

    protected:
    private:
        const handle_type handle_;
    };
}

#endif
