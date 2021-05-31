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
    std::size_t rPixelData = std::stoul(pixelDataStr.substr(0, 2), nullptr, 16);
    std::size_t gPixelData = std::stoul(pixelDataStr.substr(2, 2), nullptr, 16);
    std::size_t bPixelData = std::stoul(pixelDataStr.substr(4, 2), nullptr, 16);
    this->r = rPixelData;
    this->g = gPixelData;
    this->b = bPixelData;
}

}  // namespace improc