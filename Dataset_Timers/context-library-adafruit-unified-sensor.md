# Adafruit Unified Sensor — Vollständiger Kontext

**PlatformIO:** `adafruit/Adafruit Unified Sensor@^1.1.15`  
**Include:** `#include <Adafruit_Sensor.h>`

Quelle: [Adafruit_Sensor.h](https://github.com/adafruit/Adafruit_Sensor/blob/master/Adafruit_Sensor.h)

---

## 1. Basisklasse `Adafruit_Sensor`

Virtuelle Schnittstelle für alle „Unified“-Treiber:

| Methode | Beschreibung |
|--------|----------------|
| `virtual bool getEvent(sensors_event_t*)` | Messwert als Event |
| `virtual void getSensor(sensor_t*)` | Sensor-Metadaten (Name, Range, Auflösung, …) |
| `virtual void enableAutoRange(bool)` | optional |
| `virtual int setRange(int)` | optional |
| `virtual int getRange(void)` | optional |

---

## 2. `sensor_t` (Metadaten)

Enthält u. a.: `name`, `version`, `sensor_id`, `type`, `max_value`, `min_value`, `resolution`, `min_delay` — für Anzeige/Kalibrierung.

---

## 3. `sensors_type_t` (Auswahl)

 u. a.:

- `SENSOR_TYPE_ACCELEROMETER`, `GYROSCOPE`, `MAGNETIC_FIELD`, `ORIENTATION`
- `SENSOR_TYPE_LIGHT`, `PROXIMITY`, `PRESSURE`, `AMBIENT_TEMPERATURE`, `OBJECT_TEMPERATURE`
- `SENSOR_TYPE_COLOR`, `VOLTAGE`, `CURRENT`, `RELATIVE_HUMIDITY`
- weitere (TVOC, PM, CO2, …) — je nach Treiber

---

## 4. `sensors_event_t` — **union** (ein Event, viele mögliche Bedeutungen)

Gemeinsamer Kopf:

- `version`, `sensor_id`, `type`, `timestamp` (ms)

**Union-Inhalt** (je nach Sensor nur **ein** Zweck relevant):

| Feld | Einheit / Bedeutung |
|------|---------------------|
| `float data[4]` | generisch |
| `sensors_vec_t acceleration` | m/s² (`x,y,z` oder `v[3]`) |
| `sensors_vec_t magnetic` | µT |
| `sensors_vec_t orientation` | Grad (roll/pitch/heading) |
| `sensors_vec_t gyro` | rad/s |
| `float temperature` | °C |
| `float distance` | cm (Proximity-Treiber) |
| `float light` | lux |
| `float pressure` | hPa |
| `float relative_humidity` | % |
| `float current` | mA |
| `float voltage` | V |
| `sensors_color_t color` | Farbe (RGB / rgba) |
| … | weitere Umwelt-/Gas-Felder im Header |

**`sensors_vec_t`:** enthält `x,y,z` **oder** `roll,pitch,heading`, union mit `v[3]`, plus `status`.

**Konstanten:** u. a. `SENSORS_GRAVITY_EARTH`, `SENSORS_DPS_TO_RADS`, `SENSORS_RADS_TO_DPS`, `SENSORS_PRESSURE_SEALEVELHPA`, …

---

## 5. MPU6050 in diesem Workshop

`Adafruit_MPU6050::getEvent(&accel, &gyro, &temp)` füllt **drei** Events:

- `accel.type` → Beschleunigung, `accel.acceleration.*`
- `gyro.type` → Gyro, `gyro.gyro.*`
- `temp.type` → Temperatur, `temp.temperature`

---

## 6. Timers Workshop

Unified Sensor wird im **Timers Workshop** primär mit dem **MPU6050** (`getEvent` → Accel, Gyro, Temperatur) genutzt. RTC, ToF und OLED nutzen **eigene** Bibliotheks-APIs — siehe die jeweiligen `context-library-*.md`.
