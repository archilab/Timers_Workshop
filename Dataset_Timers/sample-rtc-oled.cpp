#include <Arduino.h>
#include <Wire.h>
#include <stdio.h>
#include <RTClib.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
RTC_DS3231 rtc;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println(F("DS3231 missing"));
    while (1) delay(10);
  }
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1) delay(10);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  DateTime now = rtc.now();
  char line[12];
  snprintf(line, sizeof(line), "%02u:%02u:%02u", now.hour(), now.minute(), now.second());
  display.clearDisplay();
  display.setCursor(0, 16);
  display.println(line);
  display.setTextSize(1);
  display.setCursor(0, 48);
  display.println(F("Timers"));
  display.display();
  display.setTextSize(2);
  delay(500);
}
