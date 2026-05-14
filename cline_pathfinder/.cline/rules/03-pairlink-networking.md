---
description: PairLink API essentials for Pathfinder
alwaysApply: true
---

# PairLink

## Dependencies (transitive)

PairLink pulls in **ArduinoJson** (v7) and **ArduinoWebsockets** — do not add separate client code unless explicitly requested.

## Config pattern

```cpp
PLConfig config;
plConfigSetLocalOnly(config, "YOUR_SSID", "YOUR_PASSWORD", "ws://192.168.x.x:8080/ws");
config.pairButtonPin = 0;
config.statusLedPin = 2;
pairLink.begin(config);
```

Adjust SSID, password, and WebSocket URL to placeholders or user values. **Never** use `localhost` for the ESP32.

## Channels and floats

- Register: `addPublishChannel("sensor.value")`, `addSubscribeChannel("sensor.value")` as needed.
- Publish: `pairLink.publish("sensor.value", value, intervalMs)` (typical throttle ~50 ms) or `publishImmediate` for edge events.
- Callbacks: `onChannel("sensor.value", fn)` / `onValue(...)` — handlers receive **float**.
- Booleans as floats: send **0.0f** / **1.0f**; interpret receive **> 0.5f** as true.

## Runtime

- **`pairLink.update()`** must run in `loop()` continuously.
- Use `pairLink.isPaired()` to branch local vs networked behavior when the sketch pattern requires it.

## Object name

- Always **`PairLink pairLink;`** (avoid the name `link`).

For extended API, error patterns, and Serial runtime config, see [`context-pairlink.md`](../../.context/context-pairlink.md).
