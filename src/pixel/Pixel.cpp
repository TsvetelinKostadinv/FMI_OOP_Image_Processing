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

PixelPPM::PixelPPM(short r, short g, short b) : r(r), g(g), b(b) {}

PixelPPM::PixelPPM(short channelValues[3])
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

}  // namespace improc