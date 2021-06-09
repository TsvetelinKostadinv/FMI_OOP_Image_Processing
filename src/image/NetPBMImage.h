#pragma once
#include <cstddef>
#include <vector>

#include "pixel/Pixel.h"
#include "pnm/pnm.hpp"

namespace improc
{
// We have the pnm::image class, however we want to demonstrate some of our own
// skill, so we write wrappers with additional functionality
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

    // Linear indexation
    virtual const PixelPBM& at(std::size_t i) const = 0;
    // 2D indexation
    virtual const PixelType& at(std::size_t x, std::size_t y) const = 0;

    inline std::size_t getWidth() const { return width; }
    inline std::size_t getHeight() const { return height; }
    inline std::size_t getTotalPixelCount() const { return width * height; }

protected:
    std::size_t width;
    std::size_t height;
};

class PBMImage : public NetPBMImage<PixelPBM>
{
public:
    PBMImage(std::size_t width,
             std::size_t height,
             const pnm::image<pnm::bit_pixel>& data);

    const std::vector<PixelPBM>& getPixels() const;
    const PixelPBM& at(std::size_t x, std::size_t y) const override;
    const PixelPBM& at(std::size_t i) const override;

protected:
    std::vector<PixelPBM> pixels;
};
}  // namespace improc
