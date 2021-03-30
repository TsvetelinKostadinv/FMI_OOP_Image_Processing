#include <iostream>
#include "command/Command.h"
#include "rlutil.h"
#include "util/Printable.h"
#include "util/StringUtils.h"

#define waitkey rlutil::anykey("\nPress any key to continue...\n")

#define RESET_COLOR_AFTER_SECTION(x) \
    {                                \
        rlutil::saveDefaultColor();  \
        ##x;                         \
        rlutil::resetColor();        \
    };

int main()
{
    RESET_COLOR_AFTER_SECTION({
        rlutil::setColor(14);
        std::cout << "Welcome to the Image processor!" << std::endl;
    });

    const improc::Command* cmd = new improc::NewCommand();
    INFO("Command name of new: |%s|\n", cmd->getCommandName().c_str());

    LOG("Testing trigger:\n");
    if (cmd->shouldTrigger("New"))
    {
        LOG("Should trigger\n");
    }
    else
    {
        LOG("Should not trigger\n");
    }
    LOG("---\n");

    std::cout << "Help for command: " << *cmd << std::endl;

    waitkey;
    return 0;
}
