#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(20, 6, 10,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_RGB);

const uint16_t colors[] = {
  matrix.Color(96, 15, 151), matrix.Color(6, 188, 64), matrix.Color(248, 182, 25) };
const uint8_t num_colors = sizeof(colors)/sizeof(colors[0]);

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(100);
  matrix.setTextColor(colors[0]);
}


int x    = matrix.width();
int pass = 0;

String sayings[] = {
  "SPANK ME MISTER",
  "KREWE OF CHAD",
  "KDV XXX",
  "DONT TREAD ON MY TARP BRO",
  "KREWE OF SPANK",
};
uint8_t say_idx = 0;
const uint8_t num_sayings = sizeof(sayings)/sizeof(sayings[0]);

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return matrix.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return matrix.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return matrix.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*1; j++) { // 1 cycle of all colors on wheel
    for(i=0; i< matrix.numPixels(); i++) {
      matrix.setPixelColor(i, Wheel(((i * 256 / matrix.numPixels()) + j) & 255));
    }
    matrix.show();
    delay(wait);
  }
}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<matrix.numPixels(); i++) {
      matrix.setPixelColor(i, Wheel((i+j) & 255));
    }
    matrix.show();
    delay(wait);
  }
}

void print_string (String string) {
  int scroll_length = -6*string.length();
  matrix.print(string);
  if(--x < scroll_length) {
    x = matrix.width();
    rainbow(20);
    say_idx = random(num_sayings);
  }
  matrix.show();
  delay(100);
}

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 1);
  print_string(sayings[say_idx]);
}
