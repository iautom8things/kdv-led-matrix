#include "Screen.h"

Screen::Screen(vector<Column*> _columns)
{
  columns = _columns;
}

void Screen::clear()
{
  for (auto col: columns)
  {
    col->clear();
  }
}
