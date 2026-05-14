#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <VL53L0X.h>
#include <Servo.h>

RTC_DS3231 rtc;
VL53L0X sensor;
Servo servo;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  rtc.begin();
  sensor.init();
  sensor.setTimeout(500);
  servo.attach(9);
}

void loop() {
  DateTime now = rtc.now();
  uint16_t mm = sensor.readRangeSingleMillimeters();
  bool window = (now.hour() >= 9 && now.hour() < 18);
  int angle = 0;
  if (window && mm < 400 && !sensor.timeoutOccurred()) {
    angle = map(constrain((int)mm, 50, 400), 50, 400, 180, 0);
  }
  servo.write(angle);
  delay(50);
}
