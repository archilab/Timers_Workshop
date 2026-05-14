#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint16_t kNeoPixelCount = 12;
constexpr uint8_t kNeoPixelPin = 6;
Adafruit_NeoPixel strip(kNeoPixelCount, kNeoPixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(40);
  Serial.begin(115200);
}

void loop() {
  float v = random(0, 100) / 100.0f;
  uint8_t b = (uint8_t)(v * 255);
  for (uint16_t i = 0; i < kNeoPixelCount; i++) {
    strip.setPixelColor(i, strip.Color(b, b, b));
  }
  strip.show();
  delay(200);
}
