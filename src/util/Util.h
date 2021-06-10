#pragma once

#define waitkey rlutil::anykey("\nPress any key to continue...\n")

#define RESET_COLOR_AFTER_SECTION(x) \
    {                                \
        rlutil::saveDefaultColor();  \
        ##x;                         \
        rlutil::resetColor();        \
    };