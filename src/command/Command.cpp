#include "Command.h"
#include "util/StringUtils.h"

#include <string>

bool improc::Command::shouldTrigger(const std::string& givenCommand) const
{
    std::string askedCommand = givenCommand;
    return equalsIgnoreCase(this->commandName, askedCommand);
}