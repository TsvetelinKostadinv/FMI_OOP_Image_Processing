#include "NetPBMImage.h"
#include <stdexcept>

namespace improc
{
PBMImage::PBMImage(std::size_t width,
                   std::size_t height,
                   const std::vector<bool>& data)
    : NetPBMImage(width, height)
{
    for (std::size_t i = 0; i < data.size(); ++i)
    {
        pixels.push_back(data[i]);
    }
}

const std::vector<PixelPBM>& improc::PBMImage::getPixels() const
{
    return pixels;
}
}  // namespace improc