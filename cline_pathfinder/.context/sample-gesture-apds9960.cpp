#include <Arduino.h>
#include <PairLink.h>
#include <Wire.h>
#include <Adafruit_APDS9960.h>

PairLink pairLink;
Adafruit_APDS9960 apds;

void onActorValue(float value){
  analogWrite(2, value*255);
}

void setup(){
  Serial.begin(115200);
  apds.begin();
  apds.enableGesture(true);

  PLConfig config;
    plConfigSetLocalOnly(config, "nextreality_net", "hololens", "ws://192.168.1.14:8080/ws");
  config.pairButtonPin = 0;
  config.statusLedPin = 2;

  pairLink.begin(config);
  pairLink.addPublishChannel("sensor.value");
  pairLink.addSubscribeChannel("sensor.value");
  pairLink.onChannel("sensor.value", onActorValue);
}

void loop(){
  pairLink.update();
  float v = 0.0f;

  uint8_t g = apds.readGesture();
  if(g) v = 1.0f;

  if(pairLink.isPaired()){
    pairLink.publish("sensor.value", v);
  } else {
    onActorValue(v);
  }
}
