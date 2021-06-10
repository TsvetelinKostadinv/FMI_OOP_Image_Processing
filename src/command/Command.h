#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "image/Pixel.h"
#include "util/Printable.h"

namespace improc
{
// The base class for all commands
class Command : public virtual Printable
{
public:
    // Creates
    Command(const std::string& commandName, const std::string& args)
        : commandName(commandName)
    {
        std::stringstream ss(args);
        while (!ss.eof())
        {
            std::string nextCommand;
            ss >> nextCommand;
            argv.push_back(nextCommand);
        }
        argc = argv.size();
    }
    virtual ~Command() {}

    // Checks whether the command should be triggered on receiving the given
    // string
    bool shouldTrigger(const std::string& givenCommand) const;

    // Returns the command name
    const std::string& getCommandName() const { return commandName; }

    // Returns the parameters vector
    const std::vector<std::string>& getParams() const { return argv; }

    // Returns the number of arguments
    std::size_t getCommandCount() const { return argc; }

    // Runs the command
    virtual void run() const = 0;

    // Prints it in a human readable fashion
    virtual std::string toStr() const = 0;

protected:
    std::string commandName;
    std::size_t argc;
    std::vector<std::string> argv;
};

// The new command, used to generate a new file
class NewCommand : public virtual Command
{
public:
    // Constructs a new command with the given text as parameters
    NewCommand(const std::string& text) : Command("NEW", text)
    {
        if (argc != 3)
        {
            throw std::invalid_argument(
                "The expected args are: <width> <height> <pixelColour>");
        }
        try
        {
            width = stoull(argv[0]);
        }
        catch (std::invalid_argument&)
        {
            throw std::invalid_argument(
                "The argument passed as width must be an integer value");
        }
        try
        {
            height = stoull(argv[1]);
        }
        catch (std::invalid_argument&)
        {
            throw std::invalid_argument(
                "The argument passed as height must be an integer value");
        }
        try
        {
            fillCol.parse(argv[2]);
        }
        catch (std::invalid_argument&)
        {
            throw std::invalid_argument(
                "The argument passed as fill colour must be a hexadecimal "
                "value in the form #RRGGBB");
        }
    }

    void run() const override {}

    std::string toStr() const override
    {
        return commandName + ' ' + std::to_string(width) + ' ' +
               std::to_string(height) + ' ' + fillCol.toStr();
    }

private:
    unsigned long long width;
    unsigned long long height;
    PixelPPM fillCol;
};
}  // namespace improc