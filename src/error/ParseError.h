#pragma once

#include <stdexcept>
#include <string>

namespace improc
{
class ParseError : public std::logic_error
{
public:
    explicit ParseError(const std::string& msg) : std::logic_error(msg) {}

    explicit ParseError(const char* msg) : std::logic_error(msg) {}
};
}  // namespace improc
