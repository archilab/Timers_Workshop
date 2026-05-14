---
description: Validation checklist and forbidden patterns
alwaysApply: true
---

# Validation and forbidden patterns

## Required in every PairLink sketch

- `pairLink.update()` in `loop()`.
- `pairLink.isPaired()` when logic depends on pairing (typical pattern).
- `"sensor.value"` publish and subscribe registered if the sketch uses that channel.
- `platformio.ini` includes **all** required `lib_deps` (see `04-platformio-dependencies.md`).

## Forbidden (unless user explicitly asks)

- **`analogRead`** — workshop meta rule.
- **`actor.value`** — invalid channel naming for this workshop.
- Extra **libraries** not in the strict list.
- **Blocking** long `delay()` in the main loop when it breaks PairLink timing or gesture sampling — prefer non-blocking patterns.

## Routing semantics (optional)

Sensor aliases for intent: see [`config-routing.json`](../../.context/config-routing.json) (`gesture` → APDS9960, `motion` → MPU6050, `distance` → APDS9960 proximity, `light`/`lux`/`color`/`als` → APDS9960 ALS, `temperature`/`temp` → MPU6050; default fallback `gesture`).

## Sample code priority

Bundled `sample-*.cpp` files in **`cline_pathfinder/.context/`** are **examples**. If they ever conflict with **`.cline/rules/*.md`** (including **`07-generator-contract.md`**), **follow the rules**, not the sample.
