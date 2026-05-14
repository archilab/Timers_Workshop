---
description: Fixed GPIO and board for Pathfinder workshop
alwaysApply: true
---

# Hardware and pins

## Board

- **Board:** ESP32-PICO-KIT (Espressif), chip **ESP32-PICO-D4**
- **PlatformIO:** `board = esp32dev` (or equivalent `pico32` / esp32dev in docs)
- **Monitor:** `monitor_speed = 115200`

## Fixed connections (do not invent other pins)

| Function | GPIO | Notes |
|----------|------|--------|
| Pairing / BOOT button | **0** | `config.pairButtonPin = 0` |
| On-board status LED | **2** | `config.statusLedPin = 2` |
| Servo signal | **12** | `Servo::attach(12)` |
| NeoPixel data | **14** | 6× RGBW, `NEO_GRBW + NEO_KHZ800` |
| I²C SDA | **21** | APDS9960 + MPU6050 shared bus |
| I²C SCL | **22** | |

## I²C

- Call `Wire.begin(21, 22)` in `setup()` before sensor `begin()` when using APDS9960 or MPU6050.

## NeoPixel strip

- Count: **6** pixels.
- Constructor pattern: `Adafruit_NeoPixel strip(6, 14, NEO_GRBW + NEO_KHZ800);`
