# Pololu VL53L0X (Timers Workshop)

**PlatformIO:** `pololu/VL53L0X`  
**Include:** `#include <VL53L0X.h>`

## Typical usage

```cpp
VL53L0X sensor;

void setup() {
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);
}

void loop() {
  uint16_t mm = sensor.readRangeSingleMillimeters();
  if (sensor.timeoutOccurred()) { /* handle */ }
}
```

## Notes

- Default I²C address **0x29**.
- Use **single-shot** or timed reads; avoid blocking the whole loop for long periods.
