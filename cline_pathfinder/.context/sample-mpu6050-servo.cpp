#include <Arduino.h>
#include <PairLink.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <ESP32Servo.h>

PairLink pairLink;
Adafruit_MPU6050 mpu;
Servo servo;

void onActorValue(float value){
  servo.write(value*180.0f);
}

void setup(){
  Serial.begin(115200);
  servo.attach(12);
  mpu.begin();

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

  sensors_event_t a,g,temp;
  mpu.getEvent(&a,&g,&temp);

  float v = (a.acceleration.x + 10.0f)/20.0f;

  if(pairLink.isPaired()){
    pairLink.publish("sensor.value", v);
  } else {
    onActorValue(v);
  }
}
