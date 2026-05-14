Erzeuge ein vollständiges PlatformIO-Projekt für **Arduino Nano** (Timers Workshop):

- **MPU6050** an I²C-Adresse **0x69** (`mpu.begin(0x69, &Wire, 0)`), nach `Wire.begin()`.
- Lese Beschleunigung, mappe X sinnvoll auf **0–180°** für einen **Servo** an **Pin 9** (`Servo.h`).
- Strikte Workshop-`lib_deps`, kein ESP32Servo, kein PairLink.

Gib `src/main.cpp` und `platformio.ini` aus.
