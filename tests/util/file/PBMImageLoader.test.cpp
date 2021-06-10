#include "catch2/catch_amalgamated.hpp"
#include "image/NetPBMImage.h"
#include "util/file/PBMImageLoader.h"

#include <iostream>
#include "util/ConsoleDrawing.h"

TEST_CASE("Should load successfully a file", "[PMBLoader]")
{
    SECTION("j.pbm 6x10")
    {
        std::uint8_t pixels[] = {
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            1, 0, 0, 0, 1, 0,  //
            0, 1, 1, 1, 0, 0,  //
            0, 0, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0,
        };

        improc::PBMImageLoaderTextMode loader("./tests/resources/j.pbm");
        REQUIRE_NOTHROW(loader.load());

        improc::NetPBMImage<improc::PixelPBM>* image = loader.getLoadedImage();

        for (std::size_t i = 0; i < image->getTotalPixelCount(); ++i)
        {
            REQUIRE((bool) pixels[i] == image->at(i).value);
        }
    }

    SECTION("j_comments.pbm 6x10")
    {
        std::uint8_t pixels[] = {
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            0, 0, 0, 0, 1, 0,  //
            1, 0, 0, 0, 1, 0,  //
            0, 1, 1, 1, 0, 0,  //
            0, 0, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0,
        };

        improc::PBMImageLoaderTextMode loader(
            "./tests/resources/j_comments.pbm");
        REQUIRE_NOTHROW(loader.load());

        improc::NetPBMImage<improc::PixelPBM>* image = loader.getLoadedImage();

        for (std::size_t i = 0; i < image->getTotalPixelCount(); ++i)
        {
            REQUIRE((bool) pixels[i] == image->at(i).value);
        }
    }

    SECTION("j.pbm 8x10")
    {
        std::uint8_t pixels[] = {
            0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 1, 0, 0, 0,  //
            1, 0, 0, 0, 1, 0, 0, 0,  //
            0, 1, 1, 1, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 0, 0,
        };

        improc::PBMImageLoaderTextMode loader("./tests/resources/j_8x10.pbm");
        REQUIRE_NOTHROW(loader.load());

        improc::NetPBMImage<improc::PixelPBM>* image = loader.getLoadedImage();
        for (std::size_t i = 0; i < image->getTotalPixelCount(); ++i)
        {
            REQUIRE((bool) pixels[i] == image->at(i).value);
        }
    }
    SECTION("j.pbm 10x10")
    {
        std::uint8_t pixels[] = {
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 1, 0, 0, 0, 1, 0, 0, 0,  //
            0, 0, 0, 1, 1, 1, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  //
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };

        improc::PBMImageLoaderTextMode loader("./tests/resources/j_10x10.pbm");
        REQUIRE_NOTHROW(loader.load());

        improc::NetPBMImage<improc::PixelPBM>* image = loader.getLoadedImage();

        for (std::size_t i = 0; i < image->getTotalPixelCount(); ++i)
        {
            REQUIRE((bool) pixels[i] == image->at(i).value);
        }

        for (std::size_t i = 0; i < image->getTotalPixelCount(); ++i)
        {
            if (i % 10 == 0)
                std::cout << std::endl;
            improc::draw(image->at(i));
        }
    }
}