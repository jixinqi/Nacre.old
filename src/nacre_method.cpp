#include "nacre.h"

nacre::method::method(http_method _value)
    : value{ _value }
{
}

const bool nacre::method::operator<(const method& other) const
{
    return value < other.value;
}
