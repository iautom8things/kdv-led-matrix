#include "scrolling_text.h"

#ifndef COLOREDSCROLLABLE_H
#define COLOREDSCROLLABLE_H

class ColoredScrollable : public Scrollable {
public:

private:
    int colHeight;
    CRGB* fgColor;
    CRGB* bgColor;
    bool ownsColors;
};
#endif
