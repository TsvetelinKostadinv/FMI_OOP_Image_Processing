#pragma once

#include "catch2/catch_amalgamated.hpp"

#include "CommandTestsHelper.h"
#include "command/Command.h"

TEST_CASE("NEW command triggering", "[NEW-command]")
{
    improc::NewCommand cmd;
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