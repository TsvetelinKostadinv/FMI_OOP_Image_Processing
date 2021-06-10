#include "ConsoleDrawing.h"

#include <iostream>
#include <stdexcept>

#include "rlutil/rlutil.h"
#include "util/Util.h"

static const char* squareString = "  ";

namespace improc
{
void draw(const PixelPPM& pix)
{
    throw std::runtime_error("Unimplemented");
}

void draw(const PixelPGM& pix)
{
    throw std::runtime_error("Unimplemented");
}
void draw(const PixelPBM& pix)
{
    RESET_COLOR_AFTER_SECTION({
        rlutil::setBackgroundColor(pix.value ? rlutil::WHITE : rlutil::BLACK);
        std::cout << squareString;
    })
}
}  // namespace improc