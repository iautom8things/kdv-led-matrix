#include "Scrollable.h"

Scrollable::~Scrollable()
{
  Serial.println("Deconning Scrollable!");
  for(int i = 0; i < columns.size(); i++)
  {
    Serial.println("Deleting Column of Scrollable");
    delete columns[i];
  }

  if (ownsColors)
  {
    Serial.println("Owns Colors!");
    delete fgColor;
    delete bgColor;
  }
  Serial.println("DONE Deconning Scrollable!");
}

Column* Scrollable::next()
{
  Serial.print("Calling next with idx_state: ");
  Serial.print(idx_state);
  Serial.print(" and col size: ");
  Serial.println(columns.size());
  Serial.flush();

  Column* result = columns[idx_state];
  idx_state++;
  Serial.print("idx_stat is now: ");
  Serial.println(idx_state);

  Serial.println("done with NEXT!");
  return result;
}

void Scrollable::setPattern(int _matrix[])
{
  Serial.println("Setting Pattern!");
  //    int pattern[] = {
  //      0,0,0,
  //      0,1,0,
  //      1,0,1,
  //      1,1,1,
  //      1,0,1,
  //      1,0,1,
  //    };
  //int numDots = 18;
  //int numCols = 3;
  //columns.clear();

  //for (int i = 0; i < numCols; i++)
  //{
  //  columns.push_back(new Column());
  //}

  //for (int i = 0; i < numDots; i++)
  //{
  //  CRGB* color = (pattern[i] != 0) ? getFGColor() : getBGColor();
  //  columns[numDots%numCols]->pushPixel(color);
  //}

  Column* c1 = new Column();
  c1->pushPixel(getBGColor());
  c1->pushPixel(getBGColor());
  c1->pushPixel(getFGColor());
  c1->pushPixel(getFGColor());
  c1->pushPixel(getFGColor());
  c1->pushPixel(getFGColor());
  columns.push_back(c1);

  Column* c2 = new Column();
  c2->pushPixel(getBGColor());
  c2->pushPixel(getFGColor());
  c2->pushPixel(getBGColor());
  c2->pushPixel(getFGColor());
  c2->pushPixel(getBGColor());
  c2->pushPixel(getBGColor());
  columns.push_back(c2);

  Column* c3 = new Column();
  c3->pushPixel(getBGColor());
  c3->pushPixel(getBGColor());
  c3->pushPixel(getFGColor());
  c3->pushPixel(getFGColor());
  c3->pushPixel(getFGColor());
  c3->pushPixel(getFGColor());
  columns.push_back(c3);

  Serial.println("Done Setting Pattern!");
}
