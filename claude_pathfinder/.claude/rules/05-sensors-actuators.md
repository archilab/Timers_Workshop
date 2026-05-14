# Sensors and actuators (concise)

Full API: [`context-library-index.md`](../../.context/context-library-index.md).

## APDS9960 (gesture / proximity / light & color)

- `Adafruit_APDS9960 apds;` → `apds.begin()`, then `enableProximity(true)` / `enableGesture(true)` as needed.
- Gestures: `uint8_t g = apds.readGesture();` → constants `APDS9960_UP`, `DOWN`, `LEFT`, `RIGHT` (or 0).
- Proximity: `readProximity()` — 8-bit raw; map to 0.0–1.0 in application logic.
- Light / color (ALS): `enableColor(true)`; when `colorDataReady()`, `getColorData(&r,&g,&b,&c)` then `calculateLux(r,g,b)` and/or `calculateColorTemperature(r,g,b)`; normalize for `sensor.value` as needed.

## MPU6050 + Unified Sensor

- `Adafruit_MPU6050 mpu;` → `mpu.begin()` after `Wire.begin(21,22)`.
- Read: `sensors_event_t a, g, temp;` → `mpu.getEvent(&a, &g, &temp);`
- Acceleration: `a.acceleration.{x,y,z}` (m/s²); gyro: `g.gyro.*` (rad/s); **temperature:** `temp.temperature` (°C).

## NeoPixel (RGBW)

- `Adafruit_NeoPixel strip(6, 14, NEO_GRBW + NEO_KHZ800);`
- `strip.begin();` then `strip.setPixelColor(...)` / `strip.show();`
- RGBW: `setPixelColor(i, r, g, b, w)` with values 0–255.

## ESP32Servo

- `Servo servo;` → `servo.attach(12);` → `servo.write(angle);` with angle 0–180 or map from 0.0–1.0.

## Default sensor (workshop meta)

- Prefer **APDS9960 gesture** as default input narrative unless the user specifies MPU6050 or another sensor.
