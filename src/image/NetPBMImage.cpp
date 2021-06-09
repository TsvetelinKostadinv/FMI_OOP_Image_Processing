#include "NetPBMImage.h"
#include <stdexcept>

#include "pnm/pnm.hpp"

namespace improc
{
PBMImage::PBMImage(std::size_t width,
                   std::size_t height,
                   const pnm::image<pnm::bit_pixel>& data)
    : NetPBMImage(width, height)
{
    for (std::size_t i = 0; i < height; ++i)
    {
        for (std::size_t j = 0; j < width; ++j)
        {
            pixels.emplace_back(data.at(j, i).value);
        }
    }
}

const std::vector<PixelPBM>& improc::PBMImage::getPixels() const
{
    return pixels;
}

const PixelPBM& PBMImage::at(std::size_t x, std::size_t y) const
{
    if (x < 0 || y < 0 || x >= width || y >= height)
    {
        throw std::out_of_range("Requested index out of range");
    }
    return pixels[y * height + x];
}

const PixelPBM& PBMImage::at(std::size_t i) const
{
    if (pixels.size() <= i || i < 0)
    {
        throw std::out_of_range("Requested index out of range");
    }
    return pixels[i];
}
}  // namespace improc