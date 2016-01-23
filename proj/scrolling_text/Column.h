#include "scrolling_text.h"

#ifndef COLUMN_H
#define COLUMN_H

class Column {
public:

  Column();
  Column(vector<CRGB*>* _pixels);
  ~Column();

  void clear();
  void draw(Column* other);
  CRGB* operator[](int idx);
  CRGB* getPixel(int idx);
  int size();
  void pushPixel(CRGB* _pixel) { pixels->push_back(_pixel); }

private:
  bool ownsVector;
  vector<CRGB*>* pixels;
};
#endif
