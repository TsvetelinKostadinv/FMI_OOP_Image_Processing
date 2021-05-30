#define TESTING

#ifdef TESTING
#define CATCH_CONFIG_MAIN
#include "catch2/catch_amalgamated.hpp"

#else

#include <cassert>
#include <iostream>
#include "command/Command.h"
#include "rlutil/rlutil.h"
#include "util/Printable.h"
#include "util/StringUtils.h"
#include "util/Util.h"

int main()
{
    RESET_COLOR_AFTER_SECTION({
        rlutil::setColor(14);
        std::cout << "Welcome to the Image processor!" << std::endl;
    });

    const improc::Command* cmd = new improc::NewCommand();
    if (cmd->shouldTrigger("New"))
    {
    }
    else
    {
        assert(false);
    }

    std::cout << "Help for command: " << *cmd << std::endl;

    waitkey;
    return 0;
}
#endif
