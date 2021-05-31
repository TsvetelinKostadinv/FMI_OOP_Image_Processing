#pragma once
#include <cstddef>
#include <string>

#include "util/Printable.h"

namespace improc
{
class Pixel : public Printable
{
public:
    Pixel();
    virtual ~Pixel() = default;

    // Accepts a string in the form '#' followed by a hexadecimal number between
    // the lower and upper bounds of the pixel type
    virtual void parse(const std::string& str) = 0;

    virtual std::string toStr() const = 0;

private:
};

/*using PixelPBM = Pixel<0, 1>;
using PixelPGM = Pixel<0, 0xf>;*/
class PixelPPM : public virtual Pixel
{
public:
    union
    {
        short channelValues[3];
        struct
        {
            short r, g, b;
        };
    };

    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPPM();
    PixelPPM(short r, short g, short b);
    PixelPPM(short channelValues[3]);
};
}  // namespace improc
