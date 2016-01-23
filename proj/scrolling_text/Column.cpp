#include "Column.h"

Column::Column()
{
  ownsVector = true;
  pixels = new vector<CRGB*>();
}

Column::Column(vector<CRGB*>* _pixels)
{
  ownsVector = false;
  pixels = _pixels;
}

Column::~Column()
{
  if (ownsVector)
  {
    pixels->clear();
    delete pixels;
  }
}

void Column::clear()
{
  for (int i = 0; i < pixels->size(); i++)
  {
    //vector<CRGB*> thePixels = *pixels;
    //CRGB* pPixel = thePixels[i];
    //pPixel->setRGB(0,0,0);
    pixels->at(i)->setRGB(0,0,0);
  }
}

void Column::draw(Column* other)
{
  Serial.println("draw");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
  if (size() != other->size()) {
    Serial.println("Size mismatch!");
    Serial.print("This Column size: ");
    Serial.print(size());
    Serial.print("Other Column Size: ");
    Serial.println(other->size());
    return;
  }

  for(int i = 0; i < size(); i++)
  {
    CRGB *thisPixel = getPixel(i);
    CRGB *otherPixel = other->getPixel(i);

    thisPixel->r = otherPixel->r;
    thisPixel->g = otherPixel->g;
    thisPixel->b = otherPixel->b;
  }
}

CRGB* Column::getPixel(int idx)
{
  return pixels->at(idx);
}

int Column::size()
{
  return pixels->size();
}
