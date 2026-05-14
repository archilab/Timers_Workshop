# PlatformIO

## Required includes (use only what the sketch needs)

```cpp
#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
```

## `lib_deps` (strict — keep in sync)

```
adafruit/RTClib@^2.1.4
pololu/VL53L0X@^1.3.1
adafruit/Adafruit SSD1306@^2.5.15
adafruit/Adafruit GFX Library@^1.11.11
adafruit/Adafruit MPU6050@^2.2.4
adafruit/Adafruit Unified Sensor@^1.1.15
adafruit/Adafruit NeoPixel@^1.12.5
```

**Servo** and **Wire** are provided by the Arduino framework — do not add separate `lib_deps` for them.

## Environment template

```ini
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
monitor_speed = 115200
lib_deps = ...
```

Copy from [`template-platformio.ini`](../../.context/template-platformio.ini) when creating new projects.
