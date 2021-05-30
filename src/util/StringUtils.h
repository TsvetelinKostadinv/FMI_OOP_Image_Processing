#pragma once

#include <string>

namespace improc
{
// Compares the 2 strings ignoring the case of the letters, so
// equalsIgnoreCase("AbCDefg", "ABCDEFG") == true
bool equalsIgnoreCase(const std::string& fst, const std::string& scd);
}  // namespace improc