#include "Column.h"

Column::Column(vector<CRGB*>* _pixels)
{
  pixels = *_pixels;
}

Column::Column(vector<CRGB*>& _pixels)
{
  pixels = _pixels;
}

vector<CRGB*>& Column::getPixels ()
{
  return pixels;
}

void Column::clear ()
{
  for (int i = 0; i < pixels.size(); i++) {
    pixels[i]->setRGB(0,0,0);
  }
}
