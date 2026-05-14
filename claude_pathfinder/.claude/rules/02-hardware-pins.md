# Hardware and pins (Arduino Nano)

## Board

- **Board:** Arduino Nano (ATmega328P, classic 5V)
- **PlatformIO:** `board = nanoatmega328` under `platform = atmelavr`
- **Serial monitor:** `monitor_speed = 115200`

## I²C bus (shared)

- **SDA:** **A4**
- **SCL:** **A5**
- Call **`Wire.begin()`** in `setup()` before any I²C device `begin()`.

## I²C addresses (workshop convention)

| Device        | Address | Notes |
|---------------|---------|--------|
| **DS3231**    | **0x68** | RTC (RTClib `RTC_DS3231`) |
| **MPU6050**   | **0x69** | **AD0 pin tied to VCC** so it does not clash with the DS3231 at 0x68 |
| **VL53L0X**   | **0x29** | Time-of-flight (default) |
| **SSD1306**   | **0x3C** | 128×64 OLED (use **0x3D** only if your module silkscreen says 0x3D) |

## Fixed GPIO (do not invent other pins without user request)

| Function        | Pin   | Notes |
|-----------------|-------|--------|
| NeoPixel data   | **6** | 6× RGBW strip, `NEO_GRBW + NEO_KHZ800` |
| Servo signal    | **9** | `Servo::attach(9)` |
| On-board LED    | **13**| Optional heartbeat / debug |

## NeoPixel strip

- Count: **6** pixels.
- Constructor: `Adafruit_NeoPixel strip(6, 6, NEO_GRBW + NEO_KHZ800);`

## Servo

- Use Arduino **`Servo`** library (built-in with Arduino framework), **not** ESP32-specific servo libraries.
