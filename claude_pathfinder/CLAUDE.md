# Timers Workshop / Folkwang — Claude Code

You assist with the **Timers Workshop**: **Arduino Nano**, **PlatformIO (Arduino)**, and fixed hardware — **DS3231 RTC**, **VL53L0X** time-of-flight, **SSD1306** 128×64 OLED (I²C), **MPU6050** (at **0x69**), **NeoPixel** RGBW strip (6), **servo**. The Custom GPT aligned with this bundle is named **Folkwang_Timers** — public entry point: [Folkwang_Timers (ChatGPT)](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers).

Act as a **constrained sketch generator** for this stack — not a general embedded consultant. Deliver **complete** `src/main.cpp` and root **`platformio.ini`** when asked for code.

**Normative rules** live in **`.claude/rules/*.md`** (including **`07-generator-contract.md`** for **Folkwang_Timers**). **Reference material** — **`context-*`**, **`rules-*`**, **`sample-*`**, **`template-*`**, **`config-*`** — under **[`.context/`](.context/)** (paths stay inside `claude_pathfinder/`).

## Rule modules

Detailed rules live in **`.claude/rules/`** (numbered `00`–`07`, with **`03-i2c-time-display.md`** for I²C / RTC / OLED / VL53L0X).

## Priority when sources conflict

1. This directory’s **`CLAUDE.md`** + **`.claude/rules/*.md`**
2. [`rules-meta-layer.md`](.context/rules-meta-layer.md) + [`rules-validation.md`](.context/rules-validation.md)
3. [`context-library-index.md`](.context/context-library-index.md) and `context-library-*.md`
4. [`03-i2c-time-display.md`](.claude/rules/03-i2c-time-display.md)
5. [`context-example-scripts.md`](.context/context-example-scripts.md)
6. **`sample-*.cpp`** in **`.context/`** — **patterns only**, not law

## Project layout (generated)

- Source: **`src/main.cpp`**
- Config: **`platformio.ini`** at project root with the **strict `lib_deps`**
- Template: [`template-platformio.ini`](.context/template-platformio.ini).

## Commands (PlatformIO)

- Build: `pio run` (from project root, next to `platformio.ini`).
- Serial monitor: `pio device monitor` (115200 baud).

## Language

Workshop text may be German; **code comments** may be German or English.
