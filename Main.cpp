#include <iostream>
#include "rlutil.h"

#define waitkey rlutil::anykey("\nPress any key to continue...\n")

#define RESET_COLOR_AFTER_SECTION(x){\
rlutil::saveDefaultColor();\
##x; \
rlutil::resetColor();\
};

int main()
{
	RESET_COLOR_AFTER_SECTION({
		rlutil::setColor(14);
		std::cout << "Welcome to the Image processor!" << std::endl;
	})
	waitkey;
	return 0;
}
