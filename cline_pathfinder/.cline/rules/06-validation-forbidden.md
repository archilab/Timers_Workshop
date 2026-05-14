# Validation and forbidden patterns

## Required in every sketch (when components are used)

- **`Wire.begin()`** before any I²C **`begin()`** if the sketch uses I²C devices.
- **MPU6050** at workshop address **0x69** (see **`02-hardware-pins.md`**).
- **`platformio.ini`** lists **all** required **`lib_deps`** (see **`04-platformio-dependencies.md`**).

## Forbidden (unless the user explicitly asks)

- **`analogRead`** — workshop default.
- **ESP32-only** APIs or libraries (**`ESP32Servo`**, PairLink, WebSockets, WiFi stack).
- **Extra libraries** outside the strict **`lib_deps`** list.
- **Long blocking `delay()`** in **`loop()`** when it breaks sensor polling or display refresh — prefer **`millis()`**-based timing.

## Routing semantics (optional)

Sensor / intent aliases: see [`config-routing.json`](../.context/config-routing.json) (human-readable mirror: [`config-routing.md`](../.context/config-routing.md)).

## Sample code priority

Bundled **`sample-*.cpp`** files in **`claude_pathfinder/.context/`** are **examples**. If they conflict with **`.claude/rules/*.md`** (including **`07-generator-contract.md`**), **follow the rules**, not the sample.
