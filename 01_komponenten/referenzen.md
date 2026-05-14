# Libraries & Referenzen

Alle im Workshop verwendeten Bibliotheken, ihre Quellen und weiterführende Dokumentation auf einen Blick. Verwendet wird das **ESP32-PICO-KIT** (Espressif Entwicklungsboard mit ESP32-PICO-D4 SiP), PlatformIO Board-ID: `pico32`.

**Physische Verschaltung:** Steckplatine und Gesamt-Schaltplan → [01 Komponenten · Verkabelung](./README.md#verkabelung).

---

## PairLink — Das Kernprotokoll

| | |
|---|---|
| **GitHub** | [github.com/archilab/Pairlink-library](https://github.com/archilab/Pairlink-library) |
| **Zweck** | Bidirektionale WebSocket-Kopplung zwischen ESP32-Geräten über `sensor.value` |
| **`lib_deps` Eintrag** | `https://github.com/archilab/Pairlink-library` |

PairLink ist eine eigenentwickelte Bibliothek des Workshops. Sie abstrahiert das gesamte Netzwerk-Protokoll hinter drei Funktionen: `begin()`, `update()`, `publish()` / `onChannel()`.

---

## Arduino-Bibliotheken (via PlatformIO)

### ArduinoWebsockets

| | |
|---|---|
| **GitHub** | [github.com/gilmaimon/ArduinoWebsockets](https://github.com/gilmaimon/ArduinoWebsockets) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/gilmaimon/ArduinoWebsockets) |
| **Zweck** | WebSocket-Client-Implementierung, Unterbau für PairLink |
| **`lib_deps` Eintrag** | `gilmaimon/ArduinoWebsockets@^0.5.4` |

### ArduinoJson

| | |
|---|---|
| **GitHub** | [github.com/bblanchon/ArduinoJson](https://github.com/bblanchon/ArduinoJson) |
| **Dokumentation** | [arduinojson.org](https://arduinojson.org) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/bblanchon/ArduinoJson) |
| **Zweck** | JSON-Serialisierung für PairLink-Nachrichten |
| **`lib_deps` Eintrag** | `bblanchon/ArduinoJson@^7.2.2` |

### Adafruit APDS9960 Library

| | |
|---|---|
| **GitHub** | [github.com/adafruit/Adafruit_APDS9960](https://github.com/adafruit/Adafruit_APDS9960) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/adafruit/Adafruit%20APDS9960%20Library) |
| **Zweck** | Gesten, Nähe (Proximity), Umgebungslicht und Farbkanäle (ALS/RGB, Lux, Farbtemperatur) mit dem APDS9960 |
| **`lib_deps` Eintrag** | `adafruit/Adafruit APDS9960 Library` |

### Adafruit MPU6050

| | |
|---|---|
| **GitHub** | [github.com/adafruit/Adafruit_MPU6050](https://github.com/adafruit/Adafruit_MPU6050) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/adafruit/Adafruit%20MPU6050) |
| **Zweck** | Beschleunigung, Gyroscope und Temperatur vom MPU6050 |
| **`lib_deps` Eintrag** | `adafruit/Adafruit MPU6050` |

### Adafruit Unified Sensor

| | |
|---|---|
| **GitHub** | [github.com/adafruit/Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/adafruit/Adafruit%20Unified%20Sensor) |
| **Zweck** | Abstraktionsschicht für alle Adafruit-Sensormodule |
| **`lib_deps` Eintrag** | `adafruit/Adafruit Unified Sensor@^1.1.15` |

### Adafruit NeoPixel

| | |
|---|---|
| **GitHub** | [github.com/adafruit/Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/adafruit/Adafruit%20NeoPixel) |
| **Zweck** | Steuerung von WS2812B / SK6812 RGBW LEDs |
| **`lib_deps` Eintrag** | `adafruit/Adafruit NeoPixel@^1.12.5` |

### ESP32Servo

| | |
|---|---|
| **GitHub** | [github.com/madhephaestus/ESP32Servo](https://github.com/madhephaestus/ESP32Servo) |
| **PlatformIO Registry** | [registry.platformio.org](https://registry.platformio.org/libraries/madhephaestus/ESP32Servo) |
| **Zweck** | Servo-Steuerung ohne Timer-Konflikte auf dem ESP32 |
| **`lib_deps` Eintrag** | `madhephaestus/ESP32Servo@^3.0.8` |

---

## Vollständige `platformio.ini`

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
lib_deps =
    https://github.com/archilab/Pairlink-library
    gilmaimon/ArduinoWebsockets@^0.5.4
    bblanchon/ArduinoJson@^7.2.2
    adafruit/Adafruit APDS9960 Library
    adafruit/Adafruit Unified Sensor@^1.1.15
    adafruit/Adafruit NeoPixel@^1.12.5
    adafruit/Adafruit MPU6050
    madhephaestus/ESP32Servo@^3.0.8
```

---

## Hardware Datasheets

| Komponente | Datenblatt |
|---|---|
| **ESP32-PICO-KIT** Getting Started Guide | [docs.espressif.com · Pico-Kit](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/hw-reference/esp32/get-started-pico-kit.html) |
| ESP32-PICO-KIT Schaltplan v4.1 | [dl.espressif.com · PDF](https://dl.espressif.com/dl/schematics/esp32-pico-kit-v4_schematic.pdf) |
| ESP32-PICO-D4 Datenblatt (Chip) | [espressif.com · PDF](https://www.espressif.com/sites/default/files/documentation/esp32-pico-d4_datasheet_en.pdf) |
| ESP32 Technical Reference Manual | [espressif.com · PDF](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf) |
| APDS-9960 | [Broadcom APDS-9960 Datasheet · PDF](https://docs.broadcom.com/doc/AV02-4191EN) |
| MPU-6050 | [TDK InvenSense MPU-6050 Datasheet · PDF](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) |
| WS2812B (NeoPixel) | [WS2812B Datasheet · PDF](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) |
| SG90 Servo | [SG90 Datasheet · PDF](https://www.electronicoscaldas.com/datasheet/MG90S_Tower-Pro.pdf) |

---

## Weiterführende Guides

| Thema | Ressource |
|---|---|
| NeoPixel Überguide (Adafruit) | [learn.adafruit.com/adafruit-neopixel-uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide) |
| MPU6050 Guide (Adafruit) | [learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro) |
| APDS9960 Guide (Adafruit) | [learn.adafruit.com/adafruit-apds9960-breakout](https://learn.adafruit.com/adafruit-apds9960-breakout) |
| ESP32 Arduino Getting Started | [randomnerdtutorials.com/esp32-arduino](https://randomnerdtutorials.com/getting-started-with-esp32/) |
| PlatformIO Dokumentation | [docs.platformio.org](https://docs.platformio.org/en/latest/) |
| I²C auf dem ESP32 | [docs.espressif.com/arduino-esp32/wire](https://docs.espressif.com/projects/arduino-esp32/en/latest/api/i2c.html) |
