#pragma once

#include <string>

#include "catch2//catch_amalgamated.hpp"
#include "command/Command.h"

inline void testCommandShouldTrigger(const improc::Command& cmd,
                                     const std::string& activationStr)
{
    REQUIRE(cmd.shouldTrigger(activationStr));
}

inline void testCommandShouldNotTrigger(const improc::Command& cmd,
                                        const std::string& activationStr)
{
    REQUIRE(!cmd.shouldTrigger(activationStr));
}