# Pololu VL53L0X — Vollständiger API-Kontext

**PlatformIO:** `pololu/VL53L0X`  
**Include:** `#include <VL53L0X.h>`  
**Default-I²C-Adresse:** **0x29** (7-Bit). Mehrere Sensoren: **`setAddress()`** nach **`init()`** mit unterschiedlichen Adressen und XSHUT-Logik (siehe Pololu-Doku).

Quellen: [VL53L0X.h](https://github.com/pololu/vl53l0x-arduino/blob/master/VL53L0X.h), [VL53L0X.cpp](https://github.com/pololu/vl53l0x-arduino/blob/master/VL53L0X.cpp), [Pololu VL53L0X Board](https://www.pololu.com/product/2490)

---

## 1. Objekt & Bus

| Element | Beschreibung |
|---------|----------------|
| `VL53L0X()` | Konstruktor; ruft noch **kein** `init`. |
| `void setBus(TwoWire * bus)` | I²C-Bus setzen (Standard **`&Wire`**). Vor **`init()`** setzen, falls nicht `Wire`. |
| `TwoWire * getBus()` | aktuellen Bus lesen |
| `void setAddress(uint8_t new_addr)` | **7-Bit-Adresse** ändern (nach erfolgreichem `init` üblich). |
| `uint8_t getAddress()` | aktuelle Adresse |
| `uint8_t last_status` | Status der **letzten** I²C-Transaktion (plattformabhängig; Debugging). |

---

## 2. Initialisierung

| Methode | Beschreibung |
|--------|----------------|
| `bool init(bool io_2v8 = true)` | Sensor **konfigurieren** (Referenzkalibrierung, Sequence-Timeouts, VCSEL-Perioden, etc.). **`io_2v8`**: bei **2V8**-I/O-Level **`true`** (viele Module mit Level-Shifter / 3V3-Logik: Datenblatt / Board prüfen — oft **`true`** Standard). Rückgabe **`false`** bei Fehler (kein Sensor, I²C-Problem). |

**Ablauf:** `Wire.begin();` → optional `setBus` → `sensor.init()` → `setTimeout(...)`.

---

## 3. Distanzmessung

| Methode | Beschreibung |
|--------|----------------|
| `uint16_t readRangeSingleMillimeters()` | **Eine** Messung (Single-shot); Rückgabe **Millimeter**. Bei Fehler / Timeout oft **`8190`** oder **`8191`** (Library-Konventionen — im Code mit `timeoutOccurred()` kombinieren). |
| `void startContinuous(uint32_t period_ms = 0)` | Kontinuierlicher Modus; **`period_ms == 0`** = schnellstmöglich (so schnell wie Timing-Budget erlaubt). |
| `void stopContinuous()` | Kontinuierlichen Modus beenden |
| `uint16_t readRangeContinuousMillimeters()` | Wert im Continuous-Modus lesen (nach `startContinuous`). |

---

## 4. Timeout & Fehler

| Methode | Beschreibung |
|--------|----------------|
| `void setTimeout(uint16_t timeout)` | **Millisekunden** für I²C-/Mess-Wartezeit (Default **0** = ohne explizites Timeout in älterem Verhalten; sinnvoll z. B. **500**). |
| `uint16_t getTimeout()` | gesetzter Timeout |
| `bool timeoutOccurred()` | **`true`**, wenn letzte Operation wegen Timeout abgebrochen wurde |

**Workshop-Empfehlung:** immer **`setTimeout(500)`** (oder vergleichbar) und **`timeoutOccurred()`** auswerten.

---

## 5. Messbudget & Signalqualität

Die interne State Machine nutzt **Pre-Range** und **Final-Range** mit VCSEL-Perioden und Timeout-Makros.

| Methode | Beschreibung |
|--------|----------------|
| `bool setMeasurementTimingBudget(uint32_t budget_us)` | Gesamtzeitbudget pro Messung in **Mikrosekunden** (mindestens ca. **20 ms** für volle Genauigkeit laut Pololu-Doku; kleinere Werte = schneller, ungenauer). |
| `uint32_t getMeasurementTimingBudget()` | aktuelles Budget |
| `bool setSignalRateLimit(float limit_Mcps)` | Mindest-Rücksignalrate (**MCPS**), um schwache Messungen zu verwerfen. |
| `float getSignalRateLimit()` | aktuelles Limit |
| `bool setVcselPulsePeriod(vcselPeriodType type, uint8_t period_pclks)` | VCSEL-Pulsperioden für **`VcselPeriodPreRange`** oder **`VcselPeriodFinalRange`** (PCLKs; fortgeschritten — Datenblatt/ST API). |
| `uint8_t getVcselPulsePeriod(vcselPeriodType type)` | auslesen |

---

## 6. Register-Zugriff (Low-Level)

Für Treiber-Portierungen / Sonderfälle:

| Methode | Beschreibung |
|--------|----------------|
| `void writeReg(uint8_t reg, uint8_t value)` | 8-Bit Register |
| `void writeReg16Bit(uint8_t reg, uint16_t value)` | 16-Bit |
| `void writeReg32Bit(uint8_t reg, uint32_t value)` | 32-Bit |
| `uint8_t readReg(uint8_t reg)` | 8-Bit lesen |
| `uint16_t readReg16Bit(uint8_t reg)` | 16-Bit |
| `uint32_t readReg32Bit(uint8_t reg)` | 32-Bit |
| `void writeMulti(uint8_t reg, uint8_t const * src, uint8_t count)` | Burst schreiben |
| `void readMulti(uint8_t reg, uint8_t * dst, uint8_t count)` | Burst lesen |

Öffentliches **`enum regAddr`** listet Registerkonstanten (z. B. `SYSRANGE_START`, `RESULT_RANGE_STATUS`, `I2C_SLAVE_DEVICE_ADDRESS`, …) — entspricht weitgehend der ST **VL53L0X** API.

---

## 7. Messbereich & Physik (Kurz)

- Typischer **max.** nutzbarer Bereich ca. **2 m** (modul-/Umgebungsabhängig); sehr dunkle / winkelige Ziele verkürzen die Reichweite.  
- **Mindestabstand** ca. einige Zentimeter — darunter ungültige oder springende Werte.  
- **Kreuztalk** und **Cover-Glass** beeinflussen Kalibrierung — bei professionellen Setups `setMeasurementTimingBudget` und ggf. ST API Kalibrierungsroutinen (nicht alle in dieser schlanken Library exponiert).

---

## 8. Workshop-Hinweise

- **`readRangeSingleMillimeters()`** in **`loop()`** nicht mit **sehr kurzem** `setTimeout` und **sehr großem** Timing-Budget kombinieren — sonst häufig Timeouts.  
- **Continuous-Modus:** weniger Latenz pro ausgelesenem Wert, aber konstante I²C-Last; für **OLED**-Updates ggf. **Single-shot** + `millis()`-Takt einfacher.  
- **Mehrere VL53:** nur mit **XSHUT**-Pins oder separatem Bus sinnvoll adressierbar; im Standardworkshop **ein** Sensor.

---

## Abhängigkeiten

**Wire** (Arduino), keine weiteren Arduino-Library-Pflichten außerhalb der Pololu-Bibliothek.
