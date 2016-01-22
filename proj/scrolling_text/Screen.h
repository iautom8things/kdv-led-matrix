#include "scrolling_text.h"
#include "Scrollable.h"

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
public:
    Screen(vector<Column*> _columns);

    void clear();
    void scrollLeft();
    void emptyLeft(int _delay);
    void scrollRight();

    void scroll(Scrollable _scrollable, int _delay);
    void push(Column* _column);

private:
    vector<Column*> columns;
};
#endif
