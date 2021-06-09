#pragma once
#include <cstddef>
#include <vector>

#include "pixel/Pixel.h"

namespace improc
{
template <typename PixelType,
          typename = std::enable_if<std::is_base_of<Pixel, PixelType>::value>>
class NetPBMImage
{
public:
    NetPBMImage(std::size_t width, std::size_t height)
        : width(width), height(height)
    {
    }

    virtual ~NetPBMImage() = default;

    virtual const std::vector<PixelType>& getPixels() const = 0;

protected:
    std::size_t width;
    std::size_t height;
};

class PBMImage : public NetPBMImage<PixelPBM>
{
public:
    PBMImage(std::size_t width,
             std::size_t height,
             const std::vector<bool>& data);

    const std::vector<PixelPBM>& getPixels() const override;

protected:
    std::vector<PixelPBM> pixels;
};
}  // namespace improc
