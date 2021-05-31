#include "Printable.h"
#include <ostream>

namespace improc
{
std::ostream& operator<<(std::ostream& os, const Printable& printable)
{
    os << printable.toStr();
    return os;
}
}  // namespace improc
