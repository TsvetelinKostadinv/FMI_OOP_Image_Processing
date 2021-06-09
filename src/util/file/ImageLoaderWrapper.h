#pragma once

#include <string>

#include "image/NetPBMImage.h"

namespace improc
{
template <typename PixelType,
          typename = std::enable_if<std::is_base_of<Pixel, PixelType>::value>>
class ImageLoaderWrapper
{
public:
    ImageLoaderWrapper(const std::string& filepath)
        : filepath(filepath), loaded(false), image(nullptr)
    {
    }

    ~ImageLoaderWrapper() { delete image; }

    virtual void load() = 0;

    virtual NetPBMImage<PixelType>* getLoadedImage() const = 0;

    bool isLoaded() const { return loaded; };

protected:
    std::string filepath;
    bool loaded;
    NetPBMImage<PixelType>* image;
};
}  // namespace improc
