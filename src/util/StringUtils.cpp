#include "StringUtils.h"
#include "Log.h"

#include <algorithm>
#include <cctype>
#include <string>

/**
   Compares 2 chars ignoring the case, i.e charsEqualIgnoreCase('a', 'A') ==
   true
*/
static bool charsEqualIgnoreCase(const char ch1, const char ch2)
{
    return ch1 == ch2 || std::toupper(ch1) == std::toupper(ch2);
}

/**
    Compares the 2 strings ignoring the case of the letters, so
    equalsIgnoreCase("AbCDefg", "ABCDEFG") == true
*/
bool improc::equalsIgnoreCase(const std::string& fst, const std::string& scd)
{
    return fst.size() == fst.size() &&
           std::equal(fst.begin(), fst.end(), scd.begin(), scd.end(),
                      &charsEqualIgnoreCase);
}