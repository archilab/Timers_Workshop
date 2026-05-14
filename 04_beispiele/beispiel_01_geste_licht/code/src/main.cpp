#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_APDS9960.h>
#include <Adafruit_NeoPixel.h>
#include <PairLink.h>

PairLink pairLink;
Adafruit_APDS9960 apds;
Adafruit_NeoPixel pixels(6, 14, NEO_GRBW + NEO_KHZ800);

float incomingValue = 0.0f;

float clamp01(float v) {
  if (v < 0.0f) return 0.0f;
  if (v > 1.0f) return 1.0f;
  return v;
}

float readGestureValue() {
  uint8_t gesture = apds.readGesture();

  if (gesture == APDS9960_UP) return 0.25f;
  if (gesture == APDS9960_DOWN) return 0.50f;
  if (gesture == APDS9960_LEFT) return 0.75f;
  if (gesture == APDS9960_RIGHT) return 1.00f;

  return 0.0f;
}

void showGestureColor(float value) {
  value = clamp01(value);

  uint32_t color = pixels.Color(0, 0, 0, 0);

  if (value > 0.12f && value < 0.38f) {
    color = pixels.Color(0, 0, 255, 0);
  } else if (value >= 0.38f && value < 0.63f) {
    color = pixels.Color(0, 255, 0, 0);
  } else if (value >= 0.63f && value < 0.88f) {
    color = pixels.Color(255, 0, 0, 0);
  } else if (value >= 0.88f) {
    color = pixels.Color(0, 0, 0, 255);
  }

  for (int i = 0; i < 6; i++) {
    pixels.setPixelColor(i, color);
  }
  pixels.show();
}

void onSensorValue(float value) {
  incomingValue = clamp01(value);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);

  pixels.begin();
  pixels.clear();
  pixels.show();

  if (!apds.begin()) {
    Serial.println("APDS9960 not found. Check SDA=21, SCL=22, 3V3 and GND.");
  } else {
    apds.enableGesture(true);
    Serial.println("APDS9960 gesture sensor ready.");
  }

  PLConfig config;
  plConfigSetLocalOnly(config, "nextreality_net", "hololens", "ws://192.168.1.14:8080/ws");
  config.pairButtonPin = 0;
  config.statusLedPin  = 2;

  pairLink.begin(config);
  pairLink.addPublishChannel("sensor.value");
  pairLink.addSubscribeChannel("sensor.value");
  pairLink.onChannel("sensor.value", onSensorValue);
}

void loop() {
  pairLink.update();

  float localValue = readGestureValue();

  if (pairLink.isPaired()) {
    pairLink.publish("sensor.value", localValue);
    showGestureColor(incomingValue);
  } else {
    showGestureColor(localValue);
  }
}
