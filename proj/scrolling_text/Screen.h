#include "scrolling_text.h"

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
    Screen(vector<Column*> _columns);

    void clear();

private:
    vector<Column*> columns;
};
#endif
