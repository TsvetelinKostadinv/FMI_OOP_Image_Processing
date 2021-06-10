#pragma once

#include <ostream>
#include <string>

namespace improc
{
// Defines a printable class
class Printable
{
public:
    // Returns the object in the form of a std::string
    virtual std::string toStr() const = 0;

    friend std::ostream& operator<<(std::ostream& os,
                                    const Printable& printable);
};
}  // namespace improc
