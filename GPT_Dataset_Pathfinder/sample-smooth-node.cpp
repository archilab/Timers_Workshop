#include <Arduino.h>
#include <PairLink.h>
#include <Wire.h>
#include <Adafruit_APDS9960.h>

PairLink pairLink;
Adafruit_APDS9960 apds;

float incoming = 0.0f;
float smooth = 0.0f;

void onSensor(float v){
  incoming = v;
}

void setup(){
  Serial.begin(115200);

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
    smooth = smooth * 0.9 + incoming * 0.1;
    pairLink.publish("sensor.value", smooth);
    analogWrite(2, smooth * 255);
  } else {
    analogWrite(2, local * 255);
  }
}
