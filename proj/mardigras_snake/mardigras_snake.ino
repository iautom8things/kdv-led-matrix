// ArrayOfLedArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with, only this time they're going
// to be all parts of an array of arrays.

#include "FastLED.h"

#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 120
CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 10
  FastLED.addLeds<WS2811, 10>(leds[0], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11
  FastLED.addLeds<WS2811, 11>(leds[1], NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12
  FastLED.addLeds<WS2811, 12>(leds[2], NUM_LEDS_PER_STRIP);

}

void loop() {
  // This outer loop will go over each strip, one at a time
  for(int x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
    for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      int iback2 = ((NUM_LEDS_PER_STRIP+i)-2) % NUM_LEDS_PER_STRIP;
      int iback = ((NUM_LEDS_PER_STRIP+i)-1) % NUM_LEDS_PER_STRIP;
      int iforward2 = (i+2) % NUM_LEDS_PER_STRIP;
      int iforward = (i+1) % NUM_LEDS_PER_STRIP;
      leds[x][iback2] = CRGB::Green;
      leds[x][iback] = CRGB::Yellow;
      leds[x][i] = CRGB::Violet;
      leds[x][iforward] = CRGB::Yellow;
      leds[x][iforward2] = CRGB::Violet;
      FastLED.show();
      //leds[x][iback] = CRGB::Black;
      //leds[x][i] = CRGB::Black;
      //leds[x][iforward] = CRGB::Black;
      delay(100);
    }
  }
}
