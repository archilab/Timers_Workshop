#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(6, 6, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(40);
  Serial.begin(115200);
}

void loop() {
  float v = random(0, 100) / 100.0f;
  uint8_t b = (uint8_t)(v * 255);
  for (int i = 0; i < 6; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, b));
  }
  strip.show();
  delay(200);
}
