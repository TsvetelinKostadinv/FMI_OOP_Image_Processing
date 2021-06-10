#pragma once

#include <string>

#include "ImageLoaderWrapper.h"

namespace improc
{
// Loads a PBM image
class PBMImageLoader : public ImageLoaderWrapper<PixelPBM>
{
public:
    PBMImageLoader(const std::string& filepath);
    virtual void load() = 0;
    virtual NetPBMImage<PixelPBM>* getLoadedImage() const = 0;
    bool isCorrectFileFormat() const;

protected:
    virtual const std::string correctFileExtention() const;
};

// Loads a PBM iamge from a text based file
class PBMImageLoaderTextMode : public PBMImageLoader
{
public:
    PBMImageLoaderTextMode(const std::string& filepath);
    void load() override;
    NetPBMImage<PixelPBM>* getLoadedImage() const override;

protected:
};
}  // namespace improc
