#include "scrolling_text.h"

#ifndef SCROLLABLEFACTORY_H
#define SCROLLABLEFACTORY_H

class ScrollableFactory {
public:
    ScrollableFactory() {}

    vector<Scrollable> fromString(string _text);
    Scrollable getScrollable(const char _char);
};
#endif
