# Validation — Timers Workshop

Required (when the sketch uses the relevant hardware):

- `Wire.begin()` before I²C `begin()` calls
- MPU6050 at **0x69** (see `02-hardware-pins.md`)
- `platformio.ini` / `template-platformio.ini` includes **all** required `lib_deps`

Forbidden:

- `analogRead` (unless user explicitly requests)
- PairLink / WiFi / WebSocket / ESP32-only servo libraries
