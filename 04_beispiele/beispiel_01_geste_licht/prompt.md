Erzeuge ein vollständiges PlatformIO-Projekt für den **Timers Workshop** (Arduino Nano):

- Lese die Uhrzeit von einer **DS3231** (I²C).
- Zeige Stunden, Minuten und Sekunden auf einem **SSD1306** 128×64 OLED (I²C, Adresse 0x3C) in lesbarer Größe.
- Nutze `Wire.begin()` und die strikten `lib_deps` des Workshops.
- Kein WiFi, kein PairLink.

Gib `src/main.cpp` und `platformio.ini` aus.
