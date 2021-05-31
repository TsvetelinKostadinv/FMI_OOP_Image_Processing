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

static bool isValidHexSymbol(const char ch)
{
    return ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F') ||
           ('0' <= ch && ch <= '9');
}

bool improc::isValidHexadecimalNumber(const std::string& str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!isValidHexSymbol(str[i]))
        {
            return false;
        }
    }

    return str.length() != 0;
}
