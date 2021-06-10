#pragma once

#include "image/Pixel.h"

namespace improc
{
// Draws the PPM pixel
void draw(const PixelPPM&);
// Draws the PGM pixel
void draw(const PixelPGM&);
// Draws the PBM pixel
void draw(const PixelPBM&);
}  // namespace improc