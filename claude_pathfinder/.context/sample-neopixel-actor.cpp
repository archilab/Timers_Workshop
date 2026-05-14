#include <Arduino.h>
#include <PairLink.h>
#include <Adafruit_NeoPixel.h>

PairLink pairLink;
Adafruit_NeoPixel strip(6,14,NEO_GRBW + NEO_KHZ800);

void onActorValue(float value){
  int b = value * 255;
  for(int i=0;i<6;i++){
    strip.setPixelColor(i, strip.Color(0,0,b));
  }
  strip.show();
}

void setup(){
  strip.begin();
  Serial.begin(115200);

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
  float v = random(100)/100.0f;

  if(pairLink.isPaired()){
    pairLink.publish("sensor.value", v);
  } else {
    onActorValue(v);
  }
}
