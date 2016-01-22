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

void Screen::scrollLeft()
{
  int last_idx = columns.size()-1;
  for(int left = 0; left < last_idx; left++)
  {
    int right = left + 1;
    columns[left]->draw(columns[right]);

  }
  columns[last_idx]->clear();
}

void Screen::scrollRight()
{
}
