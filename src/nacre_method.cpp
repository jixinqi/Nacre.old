#include "nacre.h"

const bool nacre::method::operator<(const method& other) const
{
    return value < other.value;
}

