#include <Adafruit_NeoPixel.h>
#define PIN 3
#define NUMPIXELS 16
uint8_t brightness = 10;
int way = 1;
int maxLed = 2;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int color = 0;
int colors[][3] = { { 255, 0, 0 }, { 0, 255, 0 }, { 0, 0, 255 } };


void setup() {
  pixels.begin();
  pixels.setBrightness(brightness);
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  pixels.clear();
  for (int i = 0; i < 3; i++) {
    pixels.setPixelColor(maxLed - i, colors[color][0], colors[color][1], colors[color][2]);
  }
  pixels.show();
  delay(500);
  showNext();
}

void showNext() {
  maxLed += way;
  if (maxLed == 16 && way == 1) {
    maxLed = 15;
    way = -1;
    color += 1;
  }
  if (maxLed == 1 && way == -1) {
    maxLed = 2;
    way = 1;
    color += 1;
  }
  if (color == 3) {
    color = 0;
  }
}