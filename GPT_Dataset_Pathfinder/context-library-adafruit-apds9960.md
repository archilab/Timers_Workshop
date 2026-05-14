# Adafruit APDS9960 Library — Vollständiger API-Kontext

**PlatformIO:** `adafruit/Adafruit APDS9960 Library`  
**Include:** `#include <Adafruit_APDS9960.h>`  
**I²C-Adresse:** `APDS9960_ADDRESS` = `0x39`  
**Bus:** Workshop nutzt `Wire` mit SDA=GPIO 21, SCL=GPIO 22 (beliebiger `TwoWire*` an `begin()` übergebbar).

Quellen: Upstream-Header [Adafruit_APDS9960.h](https://github.com/adafruit/Adafruit_APDS9960/blob/master/Adafruit_APDS9960.h), [Doxygen](https://adafruit.github.io/Adafruit_APDS9960/html/class_adafruit___a_p_d_s9960.html)

---

## 1. Gerät ein/aus

| Methode | Beschreibung |
|--------|----------------|
| `boolean begin(uint16_t iTimeMS = 10, apds9960AGain_t = APDS9960_AGAIN_4X, uint8_t addr = APDS9960_ADDRESS, TwoWire *theWire = &Wire)` | I²C init, Sensor konfigurieren |
| `void enable(boolean en = true)` | Gesamtes Gerät / Basis-Enable |
| `~Adafruit_APDS9960()` | Destruktor |

---

## 2. ALS / Color (Umgebungslicht & Farbkanäle)

Der Chip liefert **Clear** sowie **R/G/B**-Kanäle (kein echter „Abstand“ in Metern — **distanzähnlich** ist vielmehr **Proximity** unten).

| Methode | Beschreibung |
|--------|----------------|
| `void setADCIntegrationTime(uint16_t iTimeMS)` | Integrationszeit |
| `float getADCIntegrationTime()` | Auslesen |
| `void setADCGain(apds9960AGain_t gain)` | ADC-Gain |
| `apds9960AGain_t getADCGain()` | Werte: `APDS9960_AGAIN_1X`, `4X`, `16X`, `64X` |
| `void enableColor(boolean en = true)` | Farb-/ALS-Messung aktivieren |
| `bool colorDataReady()` | Daten bereit |
| `void getColorData(uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c)` | Rohwerte R,G,B und **Clear** (c) |
| `uint16_t calculateColorTemperature(uint16_t r, uint16_t g, uint16_t b)` | Farbtemperatur aus RGB |
| `uint16_t calculateLux(uint16_t r, uint16_t g, uint16_t b)` | Beleuchtungsstärke (Lux) |
| `void enableColorInterrupt()` / `void disableColorInterrupt()` | Interrupt bei ALS/Color |
| `void setIntLimits(uint16_t l, uint16_t h)` | ALS-Interrupt-Schwellen |
| `void clearInterrupt()` | Interrupt-Flags löschen (gemeinsam mit Nähe) |

---

## 3. Proximity (Nähe / „Distanz“-Ersatz)

**Nähe** ist ein **8-Bit-Wert** (typ. höher = Objekt näher, je nach LED/Gain). Kein Zentimeter-Maß in der Library — **Kalibrierung** anwendungsspezifisch.

| Methode | Beschreibung |
|--------|----------------|
| `void enableProximity(boolean en = true)` | Proximity-Engine |
| `void setProxGain(apds9960PGain_t gain)` | `APDS9960_PGAIN_1X` … `8X` |
| `apds9960PGain_t getProxGain()` | |
| `void setProxPulse(apds9960PPulseLen_t pLen, uint8_t pulses)` | Puls-Länge (`APDS9960_PPULSELEN_4US` … `32US`) + Anzahl |
| `uint8_t readProximity()` | Rohwert |
| `void enableProximityInterrupt()` / `void disableProximityInterrupt()` | |
| `void setProximityInterruptThreshold(uint8_t low, uint8_t high, uint8_t persistence = 4)` | Schwellen + Persistenz |
| `bool getProximityInterrupt()` | Status |

**LED-Strom / Boost (wirkt auf Proximity & Gesten-LED):**

- `void setLED(apds9960LedDrive_t drive, apds9960LedBoost_t boost)`  
  - Drive: `APDS9960_LEDDRIVE_100MA` … `12MA`  
  - Boost: `APDS9960_LEDBOOST_100PCNT` … `300PCNT`

---

## 4. Gesture (Gesten)

| Methode | Beschreibung |
|--------|----------------|
| `void enableGesture(boolean en = true)` | |
| `bool gestureValid()` | Geste im FIFO gültig |
| `void setGestureDimensions(uint8_t dims)` | z. B. `APDS9960_DIMENSIONS_ALL`, `UP_DOWN`, `LEFT_RIGHT` |
| `void setGestureFIFOThreshold(uint8_t thresh)` | `APDS9960_GFIFO_1` … `16` (FIFO-Tiefe für IRQ) |
| `void setGestureGain(uint8_t gain)` | `APDS9960_GGAIN_1` … `8` |
| `void setGestureProximityThreshold(uint8_t thresh)` | Eintritt in Gesture-Modus |
| `void setGestureOffset(uint8_t offset_up, offset_down, offset_left, offset_right)` | Richtungs-Offsets |
| `uint8_t readGesture()` | Rückgabe `0` = keine; sonst: |
| `void resetCounts()` | interne Zähler |

**Rückgabe-Konstanten** `readGesture()`:

- `APDS9960_UP` = `0x01`
- `APDS9960_DOWN` = `0x02`
- `APDS9960_LEFT` = `0x03`
- `APDS9960_RIGHT` = `0x04`

`readGesture()` kann **kurz blockieren** (Wartezeit im Treiber).

---

## 5. Register & Low-Level (Referenz)

Im Header sind **I²C-Register-Adressen** als Enum (`APDS9960_ENABLE`, `APDS9960_PDATA`, `APDS9960_GFIFO_*`, …) dokumentiert — für normale Arduino-Nutzung **nicht** direkt nötig; die Klasse kapselt Lese-/Schreibzugriffe.

---

## 6. Workshop-Hinweis

- **Nähe:** `enableProximity(true)` + `readProximity()` + optional Normalisierung auf 0.0–1.0.  
- **Gesten:** `enableGesture(true)`; `readGesture()`.  
- **Licht/Farbe/Lux/Farbtemperatur:** `enableColor(true)`, `getColorData`, `calculateLux` / `calculateColorTemperature`.  
- **Interrupts:** optional über INT-Pin am Breakout (nicht jeder Workshop-Aufbau verkabelt INT).

---

## Abhängigkeiten

- `Wire.h`, Adafruit BusIO (`Adafruit_I2CDevice`)
