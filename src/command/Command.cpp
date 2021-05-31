#include "Command.h"
#include "util/StringUtils.h"

#include <string>
namespace improc
{
bool Command::shouldTrigger(const std::string& givenCommand) const
{
    std::string askedCommand = givenCommand;
    return equalsIgnoreCase(this->commandName, askedCommand);
}
}  // namespace improc
