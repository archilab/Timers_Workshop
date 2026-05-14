# Library context — Folkwang Pathfinder / FolkwangESP-GPT

Diese Dateien liefern **offlinefähigen API- und Nutzungskontext** für alle in `template-platformio.ini` (`lib_deps`) referenzierten Bibliotheken. Sie ergänzen `context-pairlink.md` und die **Beispiel-Sketches** (`sample-*.cpp`).

**Beispiel-Integration:** Welche Rolle die Samples, `template-platformio.ini`, `rules-meta-layer.md` und `config-routing.json` im Custom GPT haben und **welche Datei Vorrang** hat, steht in **[context-example-scripts.md](./context-example-scripts.md)** — dort auch empfohlene Upload-Reihenfolge.

**Zweck:** Der Custom GPT soll dieselben Includes, Konstruktoren und typischen Aufrufe reproduzieren können, **ohne** zur Laufzeit auf Web-Dokumentation angewiesen zu sein. Die jeweiligen `context-library-*.md` beschreiben **die vollständige öffentliche API-Oberfläche** der Upstream-Bibliotheken (Methoden, Enums, relevante Konstanten) — nicht nur die im Workshop genutzte Teilmenge; praktische Hinweise bleiben am Ende der Sensor-/Aktor-Dateien.

| Datei | Bibliothek (PlatformIO) | Rolle im Workshop |
|-------|-------------------------|-------------------|
| [context-library-adafruit-apds9960.md](./context-library-adafruit-apds9960.md) | `adafruit/Adafruit APDS9960 Library` | Gesten, Nähe, Umgebungslicht / Farbe (ALS, I²C) |
| [context-library-adafruit-mpu6050.md](./context-library-adafruit-mpu6050.md) | `adafruit/Adafruit MPU6050` | Beschleunigung, Gyro, Temperatur (I²C) |
| [context-library-adafruit-neopixel.md](./context-library-adafruit-neopixel.md) | `adafruit/Adafruit NeoPixel@^1.12.5` | RGBW-LED-Streifen (GPIO-Daten) |
| [context-library-esp32servo.md](./context-library-esp32servo.md) | `madhephaestus/ESP32Servo@^3.0.8` | Servo (PWM) |
| [context-library-adafruit-unified-sensor.md](./context-library-adafruit-unified-sensor.md) | `adafruit/Adafruit Unified Sensor@^1.1.15` | `sensors_event_t` für MPU6050 |
| [context-library-arduinojson.md](./context-library-arduinojson.md) | `bblanchon/ArduinoJson@^7.2.2` | JSON (PairLink-intern / falls nötig) |
| [context-library-arduinowebsockets.md](./context-library-arduinowebsockets.md) | `gilmaimon/ArduinoWebsockets@^0.5.4` | WebSocket-Transport (PairLink-Abhängigkeit) |
| [context-pairlink.md](./context-pairlink.md) | `https://github.com/archilab/Pairlink-library` | Netzwerk, Kanäle, `pairLink.update()` |

**Workshop-Hardware (fest):** I²C `SDA = GPIO 21`, `SCL = GPIO 22`; NeoPixel-Daten `GPIO 14` (6× RGBW, `NEO_GRBW` + `NEO_KHZ800`); Servo-Signal `GPIO 12`; Boot/Pair `GPIO 0`; Status-LED `GPIO 2`.

**Offizielle Doxygen / Hersteller (extern, nur Referenz):**  
[Adafruit APDS9960](https://adafruit.github.io/Adafruit_APDS9960/html/) · [Adafruit MPU6050](https://adafruit.github.io/Adafruit_MPU6050/html/) · [Adafruit NeoPixel](https://adafruit.github.io/Adafruit_NeoPixel/html/) · [ESP32Servo](https://madhephaestus.github.io/ESP32Servo/) · [ArduinoJson v7](https://arduinojson.org/v7/) · [ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets)
