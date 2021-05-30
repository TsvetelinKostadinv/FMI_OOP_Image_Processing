#pragma once

#include <iostream>
#include <string>
#include "util/Printable.h"

namespace improc
{
class Command : public virtual Printable
{
public:
    Command(const std::string& commandName) : commandName(commandName) {}
    Command(const char* commandName) : commandName(commandName) {}

    bool shouldTrigger(const std::string& givenCommand) const;

    const std::string& getCommandName() const { return commandName; }

    virtual void run(std::istream& is) const = 0;
    virtual const std::string& toStr() const = 0;

protected:
    const std::string commandName;
};

class NewCommand : public virtual Command
{
public:
    NewCommand() : Command("NEW") {}

    void run(std::istream& is) const override
    {
        std::string str;
        is >> str;
    }

    const std::string& toStr() const override
    {
        static const std::string help = "NEW <dimWidth> <dimHeight>";
        return help;
    }

private:
};
}  // namespace improc