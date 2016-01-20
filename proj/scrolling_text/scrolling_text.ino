#include "Column.h"

#define HEIGHT 6
#define WIDTH 20
#define NUM_LEDS 120
#define PIN_OUT 10

CRGB leds[NUM_LEDS];

vector<Column*> columns;

void setup() {
  FastLED.addLeds<WS2811, PIN_OUT>(leds, NUM_LEDS);

  for(int c = 0; c < WIDTH; c++) {
    vector<CRGB*> *column = new vector<CRGB*>();
    for(int r = 0; r < HEIGHT; r++) {
      if (r % 2 != 0) {
        column->push_back(&(leds[(1+r)*WIDTH-(c+1)]));
      } else {
        column->push_back(&(leds[r*WIDTH+c]));
      }
    }
    columns.push_back(new Column(column));
  }
  leds[19] = CRGB::Red;
  leds[20] = CRGB::Blue;
  leds[59] = CRGB::Violet;
  leds[60] = CRGB::Green;
}

void loop() {

    for(int right = WIDTH-1; right > 0; right--) {
      int left = (WIDTH+right-1) % WIDTH;
      vector<CRGB*> from = columns[right]->getPixels();
      vector<CRGB*>   to = columns[left]->getPixels();
      for(int i = 0; i < HEIGHT; i++) {
        *to[i] = *from[i];
      }
      FastLED.show();
      columns[right]->clear();
      FastLED.show();
      delay(100);
    }
      int left = 19;
      int right = 0;
      vector<CRGB*> from = columns[right]->getPixels();
      vector<CRGB*>   to = columns[left]->getPixels();
      for(int i = 0; i < HEIGHT; i++) {
        *to[i] = *from[i];
      }
      FastLED.show();
      columns[right]->clear();
      FastLED.show();
      delay(100);
    
}
