# Libraries & Referenzen — Timers Workshop

Verwendet wird der **Arduino Nano** (ATmega328P) mit **PlatformIO** (`nanoatmega328`, `atmelavr`). Custom GPT: **Folkwang_Timers**.

**Verschaltung:** [01 Komponenten · Verkabelung](./README.md#verkabelung) und [`claude_pathfinder/.claude/rules/02-hardware-pins.md`](../claude_pathfinder/.claude/rules/02-hardware-pins.md).

---

## Arduino-Bibliotheken (PlatformIO `lib_deps`)

| Bibliothek | Zweck | Registry / GitHub |
|------------|--------|-------------------|
| **RTClib** | DS3231 | [adafruit/RTClib](https://github.com/adafruit/RTClib) |
| **VL53L0X** (Pololu) | Time-of-Flight Distanz | [pololu/vl53l0x-arduino](https://github.com/pololu/vl53l0x-arduino) |
| **Adafruit SSD1306** + **GFX** | OLED 128×64 | [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) |
| **Adafruit MPU6050** | IMU + Temperatur | [Adafruit MPU6050](https://github.com/adafruit/Adafruit_MPU6050) |
| **Adafruit Unified Sensor** | `sensors_event_t` | [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor) |
| **Adafruit NeoPixel** | WS2812B (Workshop: 12-LED-Ring RGB); Library deckt auch SK6812 RGBW ab | [Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) |

**Servo** und **Wire** sind in der Arduino-Framework-Installation enthalten.

Vollständige `lib_deps`-Liste: [`claude_pathfinder/.context/template-platformio.ini`](../claude_pathfinder/.context/template-platformio.ini) *(Datei ggf. laut [`NON_MARKDOWN_MIGRATION_CHECKLIST.md`](../NON_MARKDOWN_MIGRATION_CHECKLIST.md) aktualisieren)*.

---

## Datenblätter & Guides (Auswahl)

| Komponente | Link |
|------------|------|
| Arduino Nano | [arduino.cc · Nano](https://docs.arduino.cc/hardware/nano) |
| DS3231 | [Maxim DS3231](https://www.analog.com/media/en/technical-documentation/data-sheets/DS3231.pdf) |
| VL53L0X | [ST VL53L0X](https://www.st.com/resource/en/datasheet/vl53l0x.pdf) |
| SSD1306 | [Solomon Systech SSD1306](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf) |
| MPU-6050 | [TDK InvenSense](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/) |
| WS2812B / NeoPixel | [Adafruit Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide) |
| PlatformIO | [docs.platformio.org](https://docs.platformio.org/) |
