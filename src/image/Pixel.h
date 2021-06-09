#pragma once
#include <cstddef>
#include <string>

#include "util/Printable.h"

namespace improc
{
struct Pixel : public Printable
{
    Pixel();
    virtual ~Pixel() = default;

    // Accepts a string in the form '#' followed by a hexadecimal number between
    // the lower and upper bounds of the pixel type
    virtual void parse(const std::string& str) = 0;

    virtual std::string toStr() const = 0;
};

struct PixelPBM : public virtual Pixel
{
    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPBM();
    PixelPBM(bool value);

    bool value;
};

struct PixelPGM : public virtual Pixel
{
    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPGM();
    PixelPGM(unsigned short value);

    unsigned short value;
};

struct PixelPPM : public virtual Pixel
{
    union
    {
        unsigned short channelValues[3];
        struct
        {
            unsigned short r, g, b;
        };
    };

    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPPM();
    PixelPPM(unsigned short r, unsigned short g, unsigned short b);
    PixelPPM(unsigned short channelValues[3]);
};
}  // namespace improc
