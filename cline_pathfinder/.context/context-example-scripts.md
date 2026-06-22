# Example scripts — Custom GPT integration (Timers Workshop)

**Pfad:** `Dataset_Timers/` (Knowledge für **Folkwang_Timers**). Normativer Vertrag: **`Arduino_Nano_MasterPrompt.md`** / **`system-prompt.txt`**; im Repo zusätzlich **`claude_pathfinder/.claude/rules/07-generator-contract.md`** plus **`00`–`06`**.

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
| **`sample-neopixel-actor.cpp`** | NeoPixel D10 Demo |

## Konventionen

- Ausgabe im generierten Projekt: **`src/main.cpp`** + **`platformio.ini`**
- **I²C:** `Wire.begin()` (Nano **A4/A5**)

## Upload-Reihenfolge (Knowledge „Folkwang_Timers“)

1. **`Arduino_Nano_MasterPrompt.md`** oder **`system-prompt.txt`** (wenn nicht schon in ChatGPT-Anweisungen)
2. `rules-meta-layer.md`, `rules-validation.md`
3. `context-library-index.md` + alle `context-library-*.md`
4. `template-platformio.ini`
5. `sample-*.cpp`, `config-routing.json` (zuletzt)

*(Für Claude/Cline im Repo: `.claude/rules/07-generator-contract.md` + `00`–`06` + `03-i2c-time-display.md`.)*

## `config-routing`

Siehe **`config-routing.json`** (Spiegel: [`config-routing.md`](./config-routing.md)).
