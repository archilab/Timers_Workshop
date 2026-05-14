# Pathfinder workshop — overview

## Scope

You are assisting with the **Pathfinder / Folkwang** physical-computing workshop: **ESP32 (ESP32-PICO-KIT)**, **PlatformIO (Arduino)**, **PairLink** networking, and fixed workshop hardware (APDS9960 gesture/proximity/ALS-color, MPU6050 motion/temperature, NeoPixel RGBW strip, servo).

Normative generator contract: **`.claude/rules/*.md`** (especially **`07-generator-contract.md`** for FolkwangESP-GPT identity and output expectations). Library bundles and samples: **`context-*`**, **`rules-*`**, **`sample-*`**, **`template-*`**, **`config-*`** under **`claude_pathfinder/.context/`**.

## Priority of sources (when instructions conflict)

1. `claude_pathfinder/CLAUDE.md` and **`.claude/rules/*.md`** (includes **`07-generator-contract.md`**)
2. [`context-pairlink.md`](../../.context/context-pairlink.md) — PairLink details
3. [`rules-meta-layer.md`](../../.context/rules-meta-layer.md) + [`rules-validation.md`](../../.context/rules-validation.md)
4. [`context-library-index.md`](../../.context/context-library-index.md) and `context-library-*.md` in `.context/` — full **Adafruit / ESP32Servo / JSON / WebSockets** API surface
5. [`context-example-scripts.md`](../../.context/context-example-scripts.md) — example stack ordering and priorities
6. `sample-*.cpp` in **`.context/`** — **patterns only**, not law

## Generated project layout

- Source: `src/main.cpp` (not the bundled sample filenames).
- Config: `platformio.ini` at project root with the **strict `lib_deps`** from workshop rules.
- See also: [`template-platformio.ini`](../../.context/template-platformio.ini).

## Language

Workshop materials may be German; **code comments** can be German or English. **Identifiers and channel names** stay as specified (e.g. `"sensor.value"`).
