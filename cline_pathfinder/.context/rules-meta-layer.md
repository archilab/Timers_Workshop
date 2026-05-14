# Meta layer — Timers Workshop

Rules:

- default input narrative = **DS3231 time** + **VL53L0X distance** + **SSD1306** as needed
- MPU6050 may drive sketches from acceleration, gyro, or on-chip **temperature** °C (`getEvent` third event) when the user asks
- NEVER use `analogRead` unless explicitly requested
- enforce **strict** `platformio.ini` / `lib_deps` from workshop rules
- **no** PairLink, WiFi, or WebSocket code
