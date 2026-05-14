#include <Arduino.h>
#include <PairLink.h>
#include <Wire.h>
#include <Adafruit_APDS9960.h>
#include <ESP32Servo.h>

PairLink pairLink;
Adafruit_APDS9960 apds;
Servo servo;

float incoming = 0.0f;

void onSensor(float v){
  incoming = v;
}

void setup(){
  Serial.begin(115200);
  servo.attach(12);

  apds.begin();
  apds.enableGesture(true);

  PLConfig config;
  plConfigSetLocalOnly(config, "nextreality_net", "hololens", "ws://192.168.1.14:8080/ws");
  config.pairButtonPin=0;
  config.statusLedPin=2;

  pairLink.begin(config);

  pairLink.addPublishChannel("sensor.value");
  pairLink.addSubscribeChannel("sensor.value");
  pairLink.onChannel("sensor.value", onSensor);
}

void loop(){
  pairLink.update();

  float local = 0.0f;
  uint8_t g = apds.readGesture();
  if(g) local = 1.0f;

  if(pairLink.isPaired()){
    float combined = (local + incoming) * 0.5;
    pairLink.publish("sensor.value", combined);
    servo.write(combined * 180.0f);
  } else {
    servo.write(local * 180.0f);
  }
}
