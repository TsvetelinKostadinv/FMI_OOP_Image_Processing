#include <iomanip>
#include <sstream>

#include "Pixel.h"
#include "util/StringUtils.h"

namespace improc
{
Pixel::Pixel() {}

std::string PixelPPM::toStr() const
{
    std::stringstream stream;
    stream << '#';
    for (short i = 0; i < 3; ++i)
    {
        stream << std::setfill('0') << std::setw(6) << channelValues[i];
    }
    return stream.str();
}

PixelPPM::PixelPPM() : r(0), g(0), b(0) {}

PixelPPM::PixelPPM(unsigned short r, unsigned short g, unsigned short b)
    : r(r), g(g), b(b)
{
}

PixelPPM::PixelPPM(unsigned short channelValues[3])
{
    for (short i = 0; i < 3; ++i)
    {
        this->channelValues[i] = channelValues[i];
    }
}

void PixelPPM::parse(const std::string& str)
{
    if (str[0] != '#')
    {
        throw std::invalid_argument("The first character should be '#'");
    }

    std::string pixelDataStr = str.substr(1);

    if (!isValidHexadecimalNumber(pixelDataStr))
    {
        throw std::invalid_argument(
            "The pixel data should be a hexadecimal value");
    }
    if (pixelDataStr.length() != 6)
    {
        throw std::invalid_argument(
            "The pixel data should be in the fromat RRGGBB, where each letter "
            "is a hexadecimal symbol");
    }
    short rPixelData = std::stoi(pixelDataStr.substr(0, 2), nullptr, 16);
    short gPixelData = std::stoi(pixelDataStr.substr(2, 2), nullptr, 16);
    short bPixelData = std::stoi(pixelDataStr.substr(4, 2), nullptr, 16);
    this->r = rPixelData;
    this->g = gPixelData;
    this->b = bPixelData;
}

void PixelPBM::parse(const std::string& str)
{
    if (str == "1")
    {
        value = true;
    }
    else if (str == "0")
    {
        value = false;
    }
    else
    {
        throw std::invalid_argument(
            "Could not initialize PBM pixel with value: " + str);
    }
}

std::string PixelPBM::toStr() const
{
    return "" + value;
}

PixelPBM::PixelPBM() : value(false) {}

PixelPBM::PixelPBM(bool value) : value(value) {}

void PixelPGM::parse(const std::string& str)
{
    int parsed = -1;
    try
    {
        int parsed = std::stoi(str);
    }
    catch (std::invalid_argument&)
    {
        throw std::invalid_argument(
            "Could not parse number, has to be in the range 0-255");
    }
    if (parsed < 0 || parsed >= 256)
    {
        throw std::invalid_argument(
            "Could not parse number, has to be in the range 0-255");
    }
}
std::string PixelPGM::toStr() const
{
    return std::to_string(value);
}
PixelPGM::PixelPGM() : value(0) {}
PixelPGM::PixelPGM(unsigned short value) : value(value) {}
}  // namespace improc