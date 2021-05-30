#include "StringUtils.h"

#include <algorithm>
#include <cctype>
#include <string>

static bool charsEqualIgnoreCase(const char ch1, const char ch2)
{
    return ch1 == ch2 || std::toupper(ch1) == std::toupper(ch2);
}

bool improc::equalsIgnoreCase(const std::string& fst, const std::string& scd)
{
    return fst.size() == fst.size() &&
           std::equal(fst.begin(), fst.end(), scd.begin(), scd.end(),
                      &charsEqualIgnoreCase);
}