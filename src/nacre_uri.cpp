#include "nacre.h"

const bool nacre::uri::operator<(const uri& other) const
{
    return value < other.value;
}
