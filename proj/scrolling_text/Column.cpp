#include "Column.h"

Column::Column(vector<CRGB*>* _pixels)
{
  pixels = _pixels;
}

Column::Column(vector<CRGB*>& _pixels)
{
  pixels = &_pixels;
}

vector<CRGB*>* Column::getPixels ()
{
  return pixels;
}

void Column::clear ()
{
  for (int i = 0; i < pixels->size(); i++)
  {
    vector<CRGB*> thePixels = *pixels;
    CRGB* pPixel = thePixels[i];
    pPixel->setRGB(0,0,0);
  }
}

void Column::draw(Column* other)
{
  Column otherColumn = *other;
  vector<CRGB*> thisPixels = *pixels;
  for(int i = 0; i < otherColumn.size(); i++)
  {
    *(thisPixels[i]) = *(otherColumn[i]);
  }
}

CRGB* Column::operator[](int idx)
{
  vector<CRGB*> thePixels = *pixels;
  return thePixels[idx];
}

int Column::size()
{
  return pixels->size();
}
