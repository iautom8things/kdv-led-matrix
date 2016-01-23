#include "scrolling_text.h"

#define HEIGHT 6
#define WIDTH 20
#define NUM_LEDS 120
#define PIN_OUT 10

CRGB leds[NUM_LEDS];

vector<Column*>* columns = new vector<Column*>();

Screen *pScreen;
int loop_count = 0;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, PIN_OUT>(leds, NUM_LEDS);

  // create vector of columns
  for(int c = 0; c < WIDTH; c++) {
    vector<CRGB*>* column = new vector<CRGB*>();
    for(int r = 0; r < HEIGHT; r++) {
      // handle snaking leds
      if (r % 2 != 0) {
        column->push_back(&(leds[(1+r)*WIDTH-(c+1)]));
      } else {
        column->push_back(&(leds[r*WIDTH+c]));
      }
    }
    columns->push_back(new Column(column));
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
  Serial.println(loop_count++);
  Serial.print("Free memory: ");
  Serial.println(freeMemory());
  delay(1000);

  CRGB* fgColor = new CRGB(0,255,0);
  CRGB* bgColor = new CRGB(0,0,0);

  Column* c1 = new Column();
  c1->pushPixel(bgColor);
  c1->pushPixel(bgColor);
  c1->pushPixel(fgColor);
  c1->pushPixel(fgColor);
  c1->pushPixel(fgColor);
  c1->pushPixel(fgColor);
  pScreen->push(c1);
  Serial.println("Push complete!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());

  Column* c2 = new Column();
  c2->pushPixel(bgColor);
  c2->pushPixel(fgColor);
  c2->pushPixel(bgColor);
  c2->pushPixel(fgColor);
  c2->pushPixel(bgColor);
  c2->pushPixel(bgColor);
  pScreen->push(c2);
  Serial.println("Push complete!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());

  Column* c3 = new Column();
  c3->pushPixel(bgColor);
  c3->pushPixel(bgColor);
  c3->pushPixel(fgColor);
  c3->pushPixel(fgColor);
  c3->pushPixel(fgColor);
  c3->pushPixel(fgColor);
  pScreen->push(c3);
  Serial.println("Push complete!");
  Serial.print("Free memory: ");
  Serial.println(freeMemory());

  delay(100);

  free(c1);
  free(c2);
  free(c3);

  free(fgColor);
  free(bgColor);
}
