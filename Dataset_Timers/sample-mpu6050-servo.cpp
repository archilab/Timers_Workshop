#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>

Adafruit_MPU6050 mpu;
Servo servo;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  servo.attach(9);
  if (!mpu.begin(0x69, &Wire, 0)) {
    Serial.println(F("MPU6050 not found (AD0 -> VCC for 0x69)"));
    while (1) delay(10);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float v = constrain((a.acceleration.x + 10.0f) / 20.0f, 0.0f, 1.0f);
  servo.write((int)(v * 180.0f));
  delay(20);
}
