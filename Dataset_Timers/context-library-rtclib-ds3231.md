# RTClib — DS3231 (Timers Workshop)

**PlatformIO:** `adafruit/RTClib`  
**Include:** `#include <RTClib.h>`

## Typical usage

```cpp
RTC_DS3231 rtc;

void setup() {
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("DS3231 not found");
  }
  // Optional once: rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();
  // now.year(), month(), day(), hour(), minute(), second(), unixtime()
}
```

## Notes

- DS3231 default I²C address **0x68** (same chip family address as MPU6050 — workshop uses **MPU at 0x69**).
- Lost power: time may reset unless battery backed; document for participants.
