#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_NeoPixel.h>

VL53L0X sensor;
constexpr uint16_t kNeoPixelCount = 12;
constexpr uint8_t kNeoPixelPin = 6;
Adafruit_NeoPixel strip(kNeoPixelCount, kNeoPixelPin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  strip.begin();
  strip.setBrightness(60);
  if (!sensor.init()) {
    Serial.println(F("VL53L0X init failed"));
    while (1) delay(10);
  }
  sensor.setTimeout(500);
}

void loop() {
  uint16_t mm = sensor.readRangeSingleMillimeters();
  if (sensor.timeoutOccurred()) mm = 4000;
  float v = constrain(1.0f - (mm / 800.0f), 0.0f, 1.0f);
  uint8_t b = (uint8_t)(v * 255);
  for (uint16_t i = 0; i < kNeoPixelCount; i++) {
    strip.setPixelColor(i, strip.Color(b, b, b));
  }
  strip.show();
  delay(50);
}
