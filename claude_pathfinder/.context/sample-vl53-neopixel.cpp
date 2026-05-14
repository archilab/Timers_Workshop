#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_NeoPixel.h>

VL53L0X sensor;
Adafruit_NeoPixel strip(6, 6, NEO_GRBW + NEO_KHZ800);

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
  for (int i = 0; i < 6; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0, b));
  }
  strip.show();
  delay(50);
}
