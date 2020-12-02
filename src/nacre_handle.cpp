#include "nacre.h"

nacre::handle::handle(handle_type f)
: handle_{ f }
{
}

void nacre::handle::run()
{
    handle_();
}
