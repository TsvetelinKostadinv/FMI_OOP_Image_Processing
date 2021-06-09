#include "PBMImageLoader.h"

#include <fstream>
#include <sstream>

#include "error/ParseError.h"
#include "image/Pixel.h"
#include "pnm/pnm.hpp"

//#include <iomanip>
//#include <iostream>
//#include <bitset>

namespace improc
{
PBMImageLoader::PBMImageLoader(const std::string& filepath)
    : ImageLoaderWrapper(filepath)
{
    if (!isCorrectFileFormat())
    {
        throw std::invalid_argument(
            "The type of file must match the type of image!");
    }
}

bool PBMImageLoader::isCorrectFileFormat() const
{
    std::size_t dotIndex = filepath.find_last_of('.');
    try
    {
        return filepath.substr(dotIndex + 1) == correctFileExtention();
    }
    catch (std::out_of_range&)
    {
        // either npos, or the index is outside,
        // either way, it is not valid
        return false;
    }
}

const std::string PBMImageLoader::correctFileExtention() const
{
    return "pbm";
}

PBMImageLoaderTextMode::PBMImageLoaderTextMode(const std::string& filepath)
    : PBMImageLoader(filepath)
{
}

void PBMImageLoaderTextMode::load()
{
    try
    {
        pnm::image<pnm::bit_pixel> loaded = pnm::read_pbm_ascii(filepath);
        image = new PBMImage(loaded.width(), loaded.height(), loaded);
    }
    catch (std::runtime_error& e)
    {
        throw improc::ParseError(
            std::string("Could not parse file. Inner exception: ") + e.what());
    }
}
NetPBMImage<PixelPBM>* PBMImageLoaderTextMode::getLoadedImage() const
{
    return image;
}

}  // namespace improc