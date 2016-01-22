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
  FastLED.show();
}

void Screen::push(Column* _column)
{
  scrollLeft();
  int last_idx = columns.size()-1;
  columns[last_idx]->draw(_column);
  FastLED.show();
}

void Screen::emptyLeft(int _delay)
{
  for(int i = 0; i < columns.size(); i++) {
    scrollLeft();
    delay(_delay);
  }
}

void Screen::scrollRight()
{
}

void Screen::scroll(Scrollable _scrollable, int _delay)
{
  push(_scrollable.next());
  delay(_delay);
  push(_scrollable.next());
  delay(_delay);
  emptyLeft(_delay);
}
