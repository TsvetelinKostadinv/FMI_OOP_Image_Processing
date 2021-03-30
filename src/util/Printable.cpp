#include "Printable.h"
#include <ostream>

std::ostream& improc::operator<<(std::ostream& os, const improc::Printable& printable)
{
    os << printable.toStr();
    return os;
}