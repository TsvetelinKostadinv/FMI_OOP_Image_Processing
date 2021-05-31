#pragma once

#include <string>

namespace improc
{
// Compares the 2 strings ignoring the case of the letters, so
// equalsIgnoreCase("AbCDefg", "ABCDEFG") == true
bool equalsIgnoreCase(const std::string& fst, const std::string& scd);

// Checks if the supplied string is a valid hex number.
// The empty string is NOT a valid hex number
bool isValidHexadecimalNumber(const std::string& str);

}  // namespace improc