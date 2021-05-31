#pragma once

#include <stdexcept>

#include "catch2/catch_amalgamated.hpp"

#include "CommandTestsHelper.h"
#include "command/Command.h"

TEST_CASE("NEW command construction", "[NEW-command]")
{
    SECTION("New command throws on empty string")
    {
        REQUIRE_THROWS_AS(improc::NewCommand(""), std::invalid_argument);
    }
    SECTION("New command throws on too few/too many args")
    {
        REQUIRE_THROWS_AS(improc::NewCommand("123"), std::invalid_argument);
        REQUIRE_THROWS_AS(improc::NewCommand("123 123"), std::invalid_argument);
        REQUIRE_THROWS_AS(improc::NewCommand("123 123 123 123"),
                          std::invalid_argument);
        REQUIRE_THROWS_AS(improc::NewCommand("123 123 123 123 123"),
                          std::invalid_argument);
    }
    SECTION("New command throws on non integral args 1 and 2")
    {
        REQUIRE_THROWS_AS(
            improc::NewCommand("this-is-not-an-integer 123 #ffffff"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(
            improc::NewCommand("123 this-is-not-an-integer #ffffff"),
            std::invalid_argument);
        REQUIRE_THROWS_AS(
            improc::NewCommand("123 this-is-not-an-integer ffffff"),
            std::invalid_argument);
    }
}

TEST_CASE("NEW command triggering", "[NEW-command]")
{
    improc::NewCommand cmd("123	  123						#ffffff");
    SECTION("Triggers on right string")
    {
        testCommandShouldTrigger(cmd, "new");
        testCommandShouldTrigger(cmd, "neW");
        testCommandShouldTrigger(cmd, "nEw");
        testCommandShouldTrigger(cmd, "nEW");
        testCommandShouldTrigger(cmd, "New");
        testCommandShouldTrigger(cmd, "NeW");
        testCommandShouldTrigger(cmd, "NEw");
        testCommandShouldTrigger(cmd, "NEW");
    }
    SECTION("Doesn't trigger on empty")
    {
        testCommandShouldNotTrigger(cmd, "");
    }
    SECTION("Doesn't trigger on other command")
    {
        testCommandShouldNotTrigger(cmd, "dither");
        testCommandShouldNotTrigger(cmd, "show");
        testCommandShouldNotTrigger(cmd, "display");
    }
}