#pragma once

#include <string>

#include "ImageLoaderWrapper.h"

namespace improc
{
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

class PBMImageLoaderTextMode : public PBMImageLoader
{
public:
    PBMImageLoaderTextMode(const std::string& filepath);
    void load() override;
    NetPBMImage<PixelPBM>* getLoadedImage() const override;

protected:
};
}  // namespace improc
