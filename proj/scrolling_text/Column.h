#include "scrolling_text.h"

#ifndef COLUMN_H
#define COLUMN_H

class Column {
  public:

  Column(vector<CRGB*>* _pixels);
  Column(vector<CRGB*>& _pixels);

  vector<CRGB*>* getPixels();
  void clear();
  void draw(Column* other);
  CRGB* operator[](int idx);
  int size();

  private:
  vector<CRGB*>* pixels;
};
#endif
