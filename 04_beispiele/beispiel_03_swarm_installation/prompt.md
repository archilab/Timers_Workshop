Erzeuge ein vollständiges PlatformIO-Projekt für **Arduino Nano** (Timers Workshop):

- **DS3231** für die aktuelle Stunde (Fenster z. B. 9–18 Uhr).
- **VL53L0X** für Distanz in mm; bei gültiger Messung unter ca. 400 mm und innerhalb des Zeitfensters: **Servo** auf **D9** auf einen Winkel mappen (näher = größerer Winkel); außerhalb: 0°.
- `Wire.begin()`, strikte `lib_deps`, kein PairLink.

Gib `src/main.cpp` und `platformio.ini` aus.
