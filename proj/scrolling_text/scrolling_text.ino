#include "scrolling_text.h"

#define HEIGHT 6
#define WIDTH 20
#define NUM_LEDS 120
#define PIN_OUT 10

CRGB leds[NUM_LEDS];

vector<Column*> columns;

Screen *pScreen;

void setup() {
  FastLED.addLeds<WS2811, PIN_OUT>(leds, NUM_LEDS);

  // create vector of columns
  for(int c = 0; c < WIDTH; c++) {
    vector<CRGB*> *column = new vector<CRGB*>();
    for(int r = 0; r < HEIGHT; r++) {
      // handle snaking leds
      if (r % 2 != 0) {
        column->push_back(&(leds[(1+r)*WIDTH-(c+1)]));
      } else {
        column->push_back(&(leds[r*WIDTH+c]));
      }
    }
    columns.push_back(new Column(column));
  }

  // seed some initial colors on the far right
  leds[19] = CRGB::Red;
  leds[20] = CRGB::Blue;
  leds[59] = CRGB::Violet;
  leds[60] = CRGB::Green;
  leds[99] = CRGB::Brown;
  leds[100]= CRGB::Orange;

  pScreen = new Screen(columns);
}

void loop() {

  // FIXME: there's something wrong with my edge case that causes it not to cycle
  // go from right to left copying all of one column to the next
  //for(int right = WIDTH-1; right > 0; right--) {
  //  int left = (WIDTH+right-1) % WIDTH;
  //  vector<CRGB*> from = columns[right]->getPixels();
  //  vector<CRGB*>   to = columns[left]->getPixels();
  //  for(int i = 0; i < HEIGHT; i++) {
  //    *to[i] = *from[i];
  //  }
  //  FastLED.show();
  //  columns[right]->clear();
  //  FastLED.show();
  //  delay(100);
  //}

  //// TODO: remove me
  //// since above doesn't restart, force a restart by copying far left column to far right
  //int left = 19;
  //int right = 0;
  //vector<CRGB*> from = columns[right]->getPixels();
  //vector<CRGB*>   to = columns[left]->getPixels();
  //for(int i = 0; i < HEIGHT; i++) {
  //  *to[i] = *from[i];
  //}
  //FastLED.show();
  //columns[right]->clear();
  //FastLED.show();
  //delay(500);

  //pScreen->clear();
  //FastLED.show();
  //delay(500);
  // seed some initial colors on the far right
  for (int i = 0; i < 19; i++)
  {
    leds[i] = CRGB::Yellow;
  }
  leds[19] = CRGB::Red;
  leds[20] = CRGB::Blue;
  leds[59] = CRGB::Violet;
  leds[60] = CRGB::Green;
  leds[99] = CRGB::Brown;
  leds[100]= CRGB::Orange;
  FastLED.show();
  delay(500);
  Column lastColumn = *columns[19];
  for (int i = 0; i < lastColumn.size(); i++) {
    *lastColumn[i] = CRGB::Red;
    FastLED.show();
    delay(500);
  }

  for(int i = 0; i < 20; i++)
  {
    pScreen->scrollLeft();
    FastLED.show();
    delay(500);
  }


  pScreen->clear();
  FastLED.show();
  delay(500);
  leds[19] = CRGB::Blue;
  leds[20] = CRGB::Blue;
  leds[59] = CRGB::Blue;
  leds[60] = CRGB::Blue;
  leds[99] = CRGB::Blue;
  leds[100]= CRGB::Blue;
  FastLED.show();
  delay(500);
}
