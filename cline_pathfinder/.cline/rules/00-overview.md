# Timers Workshop — overview

## Scope

You are assisting with the **Timers Workshop** (Folkwang): **Arduino Nano**, **PlatformIO (Arduino)**, and fixed hardware — **DS3231 RTC**, **VL53L0X** time-of-flight, **SSD1306** 128×64 OLED (I²C), **MPU6050**, **NeoPixel** RGBW strip (6), **servo**.

Normative generator contract: **`.claude/rules/*.md`** (especially **`07-generator-contract.md`** for **Folkwang_Timers**). Library reference: **`context-*`**, **`rules-*`**, **`sample-*`**, **`template-*`**, **`config-*`** under **`claude_pathfinder/.context/`**.

## Priority of sources (when instructions conflict)

1. **`claude_pathfinder/CLAUDE.md`** and **`.claude/rules/*.md`** (includes **`07-generator-contract.md`**)
2. [`rules-meta-layer.md`](../../.context/rules-meta-layer.md) + [`rules-validation.md`](../../.context/rules-validation.md)
3. [`context-library-index.md`](../../.context/context-library-index.md) and **`context-library-*.md`**
4. [`03-i2c-time-display.md`](./03-i2c-time-display.md) — I²C, RTC, OLED, VL53L0X usage
5. [`context-example-scripts.md`](../../.context/context-example-scripts.md) — sample ordering and roles
6. **`sample-*.cpp`** in **`.context/`** — **patterns only**, not law

## Generated project layout

- Source: **`src/main.cpp`**
- Config: **`platformio.ini`** at project root with the **strict `lib_deps`**
- See also: [`template-platformio.ini`](../../.context/template-platformio.ini)

## Language

Workshop materials may be German; **code comments** may be German or English. **Identifiers** stay clear and consistent with the **Timers Workshop** hardware names in the rules.
