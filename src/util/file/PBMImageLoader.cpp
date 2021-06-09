#include "PBMImageLoader.h"

#include <fstream>
#include <sstream>

#include "error/ParseError.h"
#include "pixel/Pixel.h"

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
    std::ifstream ifs(filepath);
    if (!ifs)
    {
        throw std::runtime_error("Could not open file!");
    }
    std::vector<bool> data;

    std::string fstLine;
    std::getline(ifs, fstLine);
    if (fstLine.size() < 2)
    {
        throw std::runtime_error("Need file format descriptor");
    }
    do
    {
        if (fstLine[0] != '#')
        {
            std::string format = fstLine.substr(0, 2);
            if (format != "P1" && format != "p1")
            {
                throw std::runtime_error(
                    "Tried to load wrong file format with PBM loader!");
            }
        }
        else
        {
            std::getline(ifs, fstLine);
        }
    } while (true);

    std::string sizesLine;
    std::size_t width = 0;
    std::size_t height = 0;
    std::getline(ifs, sizesLine);

    do
    {
        if (sizesLine[0] != '#')
        {
            std::stringstream ss(sizesLine);
            std::string widthStr;
            ss >> widthStr;
            std::string rest;
            ss >> rest;
            while (rest[0] == '#')
            {
                std::getline(ifs, rest);
            }
            std::stringstream restSS(rest);
            std::string heightStr;
            restSS >> heightStr;

            try
            {
                width = std::stol(widthStr);
            }
            catch (std::invalid_argument&)
            {
                throw improc::ParseError("Could not parse the width!");
            }
            try
            {
                height = std::stol(heightStr);
            }
            catch (std::invalid_argument&)
            {
                throw improc::ParseError("Could not parse the height!");
            }
        }
        else
        {
            std::getline(ifs, fstLine);
        }
    } while (true);

    while (!ifs.eof())
    {
        if ()
    }
}
NetPBMImage<PixelPBM>* PBMImageLoaderTextMode::getLoadedImage() const
{
    return image;
}

}  // namespace improc