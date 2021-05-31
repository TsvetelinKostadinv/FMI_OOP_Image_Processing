#include "catch2/catch_amalgamated.hpp"
#include "util/StringUtils.h"

// ---- Equals ignore case tests ----

TEST_CASE("equalsIgnoreCase on empty strings", "[equalsIgnoreCase]")
{
    REQUIRE(improc::equalsIgnoreCase("", ""));
}

TEST_CASE("equalsIgnoreCase ignores case", "[equalsIgnoreCase]")
{
    REQUIRE(improc::equalsIgnoreCase("ASD", "asd"));
    REQUIRE(improc::equalsIgnoreCase("Test", "tEsT"));
}

TEST_CASE("equalsIgnoreCase with numbers", "[equalsIgnoreCase]")
{
    REQUIRE(improc::equalsIgnoreCase("123", "123"));
    REQUIRE(improc::equalsIgnoreCase("asd123", "AsD123"));
    REQUIRE(improc::equalsIgnoreCase("1A2S3D", "1a2s3d"));
}

// ---- Is valid hexadecimal number tests ----

TEST_CASE("isValidHexadecimalNumber on empty strings",
          "[isValidHexadecimalNumber]")
{
    REQUIRE(!improc::isValidHexadecimalNumber(""));
}

TEST_CASE("Valid hex numbers(one digit)", "[isValidHexadecimalNumber]")
{
    std::string number = "_";
    for (char i = '0'; i <= '9'; ++i)
    {
        number[0] = i;
        REQUIRE(improc::isValidHexadecimalNumber(number));
    }
    for (char i = 'A'; i <= 'F'; ++i)
    {
        number[0] = i;
        REQUIRE(improc::isValidHexadecimalNumber(number));
    }
}

TEST_CASE("Valid hex numbers(valid numbers)", "[isValidHexadecimalNumber]")
{
    REQUIRE(improc::isValidHexadecimalNumber("123"));
    REQUIRE(improc::isValidHexadecimalNumber("1A2B3C4D5E6F"));
}

TEST_CASE("Valid hex numbers(invalid numbers)", "[isValidHexadecimalNumber]")
{
    REQUIRE_FALSE(improc::isValidHexadecimalNumber("12C31A23B123G"));
    REQUIRE_FALSE(improc::isValidHexadecimalNumber("ASD"));
    REQUIRE_FALSE(improc::isValidHexadecimalNumber("TEST"));
}

TEST_CASE("Valid hex numbers(mixed case)", "[isValidHexadecimalNumber]")
{
    REQUIRE(improc::isValidHexadecimalNumber("FfFf"));
    REQUIRE(improc::isValidHexadecimalNumber("12A12A"));
}

TEST_CASE("Valid hex numbers(leading zeros)", "[isValidHexadecimalNumber]")
{
    REQUIRE(improc::isValidHexadecimalNumber("000123"));
    REQUIRE(improc::isValidHexadecimalNumber("000001f3F"));
}
