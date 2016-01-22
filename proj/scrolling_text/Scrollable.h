#include "scrolling_text.h"

#ifndef SCROLLABLE_H
#define SCROLLABLE_H

class Scrollable {
public:
    Scrollable(vector<Column*> _columns);

    Column* next();
    bool done() { return idx_state >= columns.size(); }
    void reset() { idx_state = 0; }
    Column* operator[](int idx) { return columns[idx]; }
    Column* get(int idx) { return columns[idx]; }

private:
    vector<Column*> columns;
    int idx_state = 0;
};
#endif
