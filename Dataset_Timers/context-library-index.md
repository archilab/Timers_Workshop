# Library context — Timers Workshop / Folkwang_Timers

Diese Dateien liefern **offlinefähigen API-Kontext** für alle in `template-platformio.ini` (`lib_deps`) referenzierten Bibliotheken — Umfang analog zu **`context-library-adafruit-mpu6050.md`** (Methoden, Enums, typische Muster).

**Integration:** Siehe **[context-example-scripts.md](./context-example-scripts.md)** für Upload-Reihenfolge und Priorität.

| Datei | Bibliothek (PlatformIO) | Rolle im Workshop |
|-------|-------------------------|-------------------|
| [context-library-rtclib-ds3231.md](./context-library-rtclib-ds3231.md) | `adafruit/RTClib` | DS3231 Echtzeituhr (I²C **0x68**) |
| [context-library-vl53l0x-pololu.md](./context-library-vl53l0x-pololu.md) | `pololu/VL53L0X` | Time-of-Flight Distanz mm (I²C **0x29**) |
| [context-library-ssd1306.md](./context-library-ssd1306.md) | `Adafruit SSD1306` + GFX | 128×64 OLED (I²C **0x3C** / **0x3D**) |
| [context-library-adafruit-mpu6050.md](./context-library-adafruit-mpu6050.md) | `adafruit/Adafruit MPU6050` | IMU + Temperatur (I²C **0x69** im Workshop) |
| [context-library-adafruit-neopixel.md](./context-library-adafruit-neopixel.md) | `adafruit/Adafruit NeoPixel` | 12× WS2812B RGB, Datenpin **D6** |
| [context-library-adafruit-unified-sensor.md](./context-library-adafruit-unified-sensor.md) | `adafruit/Adafruit Unified Sensor` | `sensors_event_t` für MPU6050 |

**Workshop-Hardware (fest):** I²C **A4/A5**; NeoPixel **D6**; Servo **D9**; optional LED **D13**.

**Externe Referenz:** [RTClib](https://github.com/adafruit/RTClib) · [VL53L0X Pololu](https://github.com/pololu/vl53l0x-arduino) · [Adafruit SSD1306](https://learn.adafruit.com/monochrome-oled-breakouts) · [MPU6050](https://adafruit.github.io/Adafruit_MPU6050/html/) · [NeoPixel](https://adafruit.github.io/Adafruit_NeoPixel/html/)
