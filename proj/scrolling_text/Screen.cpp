#include "Screen.h"

Screen::Screen(vector<Column*>* _columns)
{
  columns = _columns;
}

void Screen::clear()
{
  for (auto col: *columns)
  {
    col->clear();
  }
}

void Screen::scrollLeft()
{
  Serial.println("scrollingLeft: ");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
  int last_idx = columns->size()-1;

  for(int left = 0; left < last_idx; left++)
  {
    int right = left + 1;
    columns->at(left)->draw(columns->at(right));

  }
  columns->back()->clear();
  FastLED.show();
}

void Screen::push(Column* _column)
{
  Serial.println("Pushing!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
  scrollLeft();
  Serial.println("ScrollLeft complete!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
  columns->back()->draw(_column);
  Serial.println("Draw complete!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());

  FastLED.show();
  Serial.println("Done Pushing!");
}

void Screen::emptyLeft(int _delay)
{
  Serial.println("emptyingLeft!");
  for(int i = 0; i < columns->size(); i++) {
    scrollLeft();
    delay(_delay);
  }
  Serial.println("done emptying left!");
}

void Screen::scrollRight()
{
}

void Screen::scroll(Scrollable* _scrollable, int _delay)
{
  Serial.println("Calling SCROLL");
  while(!_scrollable->done())
  {
    Serial.println("Inside while loop in Scroll");

    push(_scrollable->next());
    delay(_delay);
  }
  emptyLeft(_delay);
  Serial.println("Done with SCROLL");
}

void Screen::scrollMany(vector<Scrollable*> _scrollables, int _delay, int _numSpaces)
{
  for (auto scrollable: _scrollables)
  {
    scroll(scrollable,_delay);
    delay(_delay);
    for (int i = 0; i < _numSpaces; i++)
    {
      scrollLeft();
      delay(_delay);
    }
  }
  emptyLeft(_delay);
}
