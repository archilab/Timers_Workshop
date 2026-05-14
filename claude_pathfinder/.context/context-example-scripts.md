# Example scripts — Custom GPT integration (Timers Workshop)

**Pfad:** `claude_pathfinder/.context/`. Normative contract: **`../.claude/rules/07-generator-contract.md`** (**Folkwang_Timers**) plus **`00`–`06`**.

Die **`sample-*.cpp`** sind **Muster**; Regeln und **`context-library-*.md`** haben Vorrang.

## Priorität

1. **`.claude/rules/*.md`**
2. **`rules-meta-layer.md`** + **`rules-validation.md`**
3. **`context-library-index.md`** → **`context-library-*.md`**
4. **`03-i2c-time-display.md`**
5. **`sample-*.cpp`** + **`template-platformio.ini`**
6. **`config-routing.json`** (Alias → Sensor)

## Datei-Katalog

| Datei | Inhalt |
|--------|--------|
| **`sample-rtc-oled.cpp`** | DS3231 + SSD1306 Uhrzeit |
| **`sample-vl53-neopixel.cpp`** | VL53L0X → NeoPixel-Helligkeit |
| **`sample-time-window-actuator.cpp`** | RTC-Fenster + Distanz → Servo |
| **`sample-mpu6050-servo.cpp`** | MPU6050 @0x69 → Servo D9 |
| **`sample-neopixel-actor.cpp`** | NeoPixel D6 Demo |

## Konventionen

- Ausgabe im generierten Projekt: **`src/main.cpp`** + **`platformio.ini`**
- **I²C:** `Wire.begin()` (Nano **A4/A5**)

## Upload-Reihenfolge (Knowledge „Folkwang_Timers“)

1. `../.claude/rules/07-generator-contract.md` + `00`–`06` + `03-i2c-time-display.md`
2. `rules-meta-layer.md`, `rules-validation.md`
3. `context-library-index.md` + alle `context-library-*.md`
4. `context-example-scripts.md`
5. `config-routing.json`
6. `template-platformio.ini` + `sample-*.cpp`

## `config-routing`

Siehe **`config-routing.json`** (Spiegel: [`config-routing.md`](./config-routing.md)).
