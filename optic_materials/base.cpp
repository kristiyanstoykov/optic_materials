#include "base.h"

std::ostream& operator<<(std::ostream& os, const Base& base)
{
    return base.print(os);
}

std::istream& operator>>(std::istream& is, Base& base)
{
    return base.input(is);
}