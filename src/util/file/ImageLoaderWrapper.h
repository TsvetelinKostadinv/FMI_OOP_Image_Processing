#pragma once

#include <string>

#include "image/NetPBMImage.h"

namespace improc
{
// A wrapper around some library functionality that will load the images
template <typename PixelType>
class ImageLoaderWrapper
{
    static_assert(std::is_base_of<Pixel, PixelType>::value,
                  "The PixelType must extend the Pixel class");

public:
    ImageLoaderWrapper(const std::string& filepath)
        : filepath(filepath), loaded(false), image(nullptr)
    {
    }

    ~ImageLoaderWrapper() { delete image; }

    // Loads the image from the supplied filepath
    virtual void load() = 0;

    virtual NetPBMImage<PixelType>* getLoadedImage() const = 0;

    bool isLoaded() const { return loaded; };

protected:
    std::string filepath;
    bool loaded;
    NetPBMImage<PixelType>* image;
};
}  // namespace improc
