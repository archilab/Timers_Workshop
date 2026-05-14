# Sensors and actuators (concise)

Full API: [`context-library-index.md`](../../.context/context-library-index.md).

## DS3231 (RTClib)

- **`RTC_DS3231 rtc;`** → **`Wire.begin()`** then **`rtc.begin()`**.
- Read **`DateTime now = rtc.now();`** for wall-clock fields and scheduling logic.

## VL53L0X (Pololu)

- **`VL53L0X sensor;`** → **`sensor.init()`** after **`Wire.begin()`**; set **`sensor.setTimeout(...)`**.
- **`readRangeSingleMillimeters()`** for distance; map to brightness, thresholds, or text on the OLED.

## SSD1306 OLED (128×64)

- **`Adafruit_SSD1306`** + **`display.begin(SSD1306_SWITCHCAPVCC, 0x3C)`** (or **0x3D**).
- Clear / set cursor / print / **`display.display()`**.

## MPU6050 + Unified Sensor

- **`Adafruit_MPU6050 mpu;`** → after **`Wire.begin()`**, call **`mpu.begin(0x69, &Wire, 0)`** (workshop address with **AD0 → VCC**).
- Read: **`sensors_event_t a, g, temp;`** → **`mpu.getEvent(&a, &g, &temp);`**
- Acceleration **`a.acceleration.{x,y,z}`** (m/s²); gyro **`g.gyro.*`** (rad/s); **temperature** **`temp.temperature`** (°C).

## NeoPixel (RGBW)

- **`Adafruit_NeoPixel strip(6, 6, NEO_GRBW + NEO_KHZ800);`**
- **`strip.begin();`** then **`setPixelColor`** / **`show()`**.

## Servo (Arduino)

- **`#include <Servo.h>`** → **`Servo servo;`** → **`servo.attach(9);`** → **`servo.write(angle);`** (0–180).

## Default narrative (workshop meta)

- Prefer **time + distance + display** framing (RTC, VL53L0X, OLED) unless the user specifies MPU6050 or servo-led motion.
