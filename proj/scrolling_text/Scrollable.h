#include "scrolling_text.h"

#ifndef SCROLLABLE_H
#define SCROLLABLE_H

class Scrollable {
public:
    Scrollable()
    {
      colHeight = 6;
      fgColor = new CRGB(0,255,0);
      bgColor = new CRGB(0,0,0);
      ownsColors = true;
    }

    Scrollable(int _colHeight)
    {
      colHeight = _colHeight;
      fgColor = new CRGB(0,255,0);
      bgColor = new CRGB(0,0,0);
      ownsColors = true;
    }

    Scrollable(int _colHeight, CRGB* _fgColor, CRGB* _bgColor)
    {
      colHeight = _colHeight;
      fgColor = _fgColor;
      bgColor = _bgColor;
      ownsColors = false;
    }
    ~Scrollable();

    bool done () {
      bool isDone = idx_state >= columns.size() ;

      Serial.println("Scrollable is done?");
      if (isDone) {
        Serial.println("yes");
      } else {
        Serial.println("no");
      }

      return isDone;
    }

    void reset () {
      Serial.println("Resetting Scrollable");
      idx_state = 0;
    }

    Column* operator[] (int idx) {
      Serial.print("requesting column at idx: ");
      Serial.println(idx);
      return columns[idx];
    }

    Column* get (int idx) {
      Serial.print("getting column at idx: ");
      Serial.println(idx);

      return columns[idx];
    }

    int getColHeight () {
      Serial.println("Getting Col Height");
      return colHeight;
    }

    CRGB* getFGColor () {
      Serial.println("Getting FG color");
      return fgColor;
    }
    CRGB* getBGColor () {
      Serial.println("Getting BG color");
      return bgColor;
    }

    void setColHieght (int _height) { colHeight = _height; }
    void setFGColor (CRGB* _color) { fgColor = _color; }
    void setBGColor (CRGB* _color) { bgColor = _color; }

    Column* next ();
    void setPattern (int _matrix[]);

protected:
    vector<Column*> columns;
    int colHeight;
    CRGB* fgColor;
    CRGB* bgColor;
    bool ownsColors;

private:
    int idx_state = 0;
};
#endif
