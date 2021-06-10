#pragma once
#include <cstddef>
#include <string>

#include "util/Printable.h"

namespace improc
{
// The base class for all pixels
struct Pixel : public Printable
{
    Pixel();
    virtual ~Pixel() = default;

    // Parses the pixel in-place
    virtual void parse(const std::string& str) = 0;

    virtual std::string toStr() const = 0;
};

struct PixelPGM;
struct PixelPPM;

// A simple pixel - either on or off, 1 or 0, true or false
struct PixelPBM : public virtual Pixel
{
    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPBM();
    PixelPBM(bool value);

    // Converts to PGM pixel
    PixelPGM toPGMPixel() const;
    // Converts to PPM pixel
    PixelPPM toPPMPixel() const;

    explicit operator PixelPGM() const;
    explicit operator PixelPPM() const;

    bool value;
};

struct PixelPGM : public virtual Pixel
{
    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPGM();
    PixelPGM(unsigned short value);

    // Converts to PBM pixel
    PixelPBM toPBMPixel(int& outError) const;
    // Converts to PPM pixel
    PixelPPM toPPMPixel() const;

    explicit operator PixelPPM() const;

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

    // Accepts a string in the form '#' followed by a hexadecimal number between
    // the lower and upper bounds of the pixel type
    void parse(const std::string& str) override;
    std::string toStr() const override;
    PixelPPM();
    PixelPPM(unsigned short r, unsigned short g, unsigned short b);
    PixelPPM(unsigned short channelValues[3]);
};
}  // namespace improc
