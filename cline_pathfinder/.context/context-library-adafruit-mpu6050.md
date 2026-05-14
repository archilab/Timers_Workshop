# Adafruit MPU6050 Library — Vollständiger API-Kontext

**PlatformIO:** `adafruit/Adafruit MPU6050`  
**Includes:** `#include <Adafruit_MPU6050.h>` · `#include <Adafruit_Sensor.h>` · `#include <Wire.h>`  
**Timers Workshop:** MPU6050 wird an **I²C-Adresse `0x69`** betrieben (**AD0 → VCC**), damit der **DS3231** `0x68` nutzen kann.  
**Standard-Upstream:** `MPU6050_I2CADDR_DEFAULT` = `0x68` (AD0 low) · **`bool begin(uint8_t i2c_addr, TwoWire *wire, ...)`** mit **`0x69`** verwenden.  
**WHO_AM_I:** `MPU6050_DEVICE_ID` = `0x68`

Quelle: Upstream [Adafruit_MPU6050.h](https://github.com/adafruit/Adafruit_MPU6050/blob/master/Adafruit_MPU6050.h), [Doxygen](https://adafruit.github.io/Adafruit_MPU6050/html/class_adafruit___m_p_u6050.html)

---

## 1. Initialisierung & Messung (Haupt-API)

| Methode | Beschreibung |
|--------|----------------|
| `bool begin(uint8_t i2c_addr = MPU6050_I2CADDR_DEFAULT, TwoWire *wire = &Wire, int32_t sensorID = 0)` | Sensor starten |
| `bool getEvent(sensors_event_t *accel, sensors_event_t *gyro, sensors_event_t *temp)` | **Ein** Aufruf liefert Beschleunigung, Gyro und **Temperatur** (Unified Sensor) |

**Nach `getEvent`:**  
- `accel->acceleration.{x,y,z}` in **m/s²**  
- `gyro->gyro.{x,y,z}` in **rad/s**  
- `temp->temperature` in **°C** (On-Chip-Temperatursensor des MPU6050)

---

## 2. Messbereiche & Digitalfilter

**Beschleunigung** (`setAccelerometerRange` / `getAccelerometerRange`):

- `MPU6050_RANGE_2_G`, `4_G`, `8_G`, `16_G`

**Gyroskop** (`setGyroRange` / `getGyroRange`):

- `MPU6050_RANGE_250_DEG`, `500_DEG`, `1000_DEG`, `2000_DEG` (°/s)

**Tiefpass (DLPF)** — `setFilterBandwidth` / `getFilterBandwidth`:

- `MPU6050_BAND_260_HZ`, `184_HZ`, `94_HZ`, `44_HZ`, `21_HZ`, `10_HZ`, `5_HZ`

**Hochpass (Accel)** — `setHighPassFilter` / `getHighPassFilter`:

- `MPU6050_HIGHPASS_DISABLE`, `5_HZ`, `2_5_HZ`, `1_25_HZ`, `0_63_HZ`, `UNUSED`, `HOLD`

**Abtastrate:** `setSampleRateDivisor` / `getSampleRateDivisor` (bezogen auf interne Gyro-Rate; siehe Datenblatt)

---

## 3. Takt & Betriebsmodi

| Methode | Beschreibung |
|--------|----------------|
| `void setClock(mpu6050_clock_select_t)` / `mpu6050_clock_select_t getClock()` | Interne Clock: `MPU6050_INTR_8MHz`, `PLL_GYROX/Y/Z`, `PLL_EXT_32K`, `PLL_EXT_19MHz`, `MPU6050_STOP` |
| `bool enableSleep(bool enable)` | Sleep-Modus |
| `bool enableCycle(bool enable)` | Cycle-Modus (Wake-Periodik) |
| `void setCycleRate(mpu6050_cycle_rate_t rate)` / `getCycleRate()` | `MPU6050_CYCLE_1_25_HZ` … `40_HZ` |

---

## 4. Achsen-Standby & Reset

| Methode | Beschreibung |
|--------|----------------|
| `bool setGyroStandby(bool x, bool y, bool z)` | Gyro-Achsen einzeln standby |
| `bool setAccelerometerStandby(bool x, bool y, bool z)` | Accel-Achsen |
| `bool setTemperatureStandby(bool enable)` | **Temperatur**-Messung aus |
| `void reset(void)` | Chip-Reset |

---

## 5. Interrupts & Bewegungserkennung

| Methode | Beschreibung |
|--------|----------------|
| `void setInterruptPinPolarity(bool active_low)` | INT-Pin-Polarität |
| `void setInterruptPinLatch(bool held)` | Latch-Verhalten |
| `void setMotionInterrupt(bool active)` | Motion-IRQ aktivieren |
| `void setMotionDetectionThreshold(uint8_t thr)` | Schwellwert |
| `void setMotionDetectionDuration(uint8_t dur)` | Dauer (1 ms Schritte, siehe Register) |
| `bool getMotionInterruptStatus(void)` | Status auslesen |

---

## 6. Sonstiges (FSYNC, Bypass, …)

| Methode | Beschreibung |
|--------|----------------|
| `void setFsyncSampleOutput(mpu6050_fsync_out_t)` / `getFsyncSampleOutput()` | FSYNC-Auswahl: `DISABLED`, `TEMP`, `GYROX/Y/Z`, `ACCELX/Y/Z` |
| `void setI2CBypass(bool bypass)` | I²C-Bypass (z. B. für Magnetometer am Aux-Bus — Datenblatt) |

---

## 7. Adafruit Unified Sensor — Einzelkomponenten

Zusätzlich zu `getEvent` können **Sub-Sensoren** abgefragt werden:

- `Adafruit_Sensor *getTemperatureSensor(void)`
- `Adafruit_Sensor *getAccelerometerSensor(void)`
- `Adafruit_Sensor *getGyroSensor(void)`

Jedes implementiert `getEvent(sensors_event_t *)` und `getSensor(sensor_t *)` für Metadaten.

---

## 8. Öffentliche Roh-/Skalierungsfelder (geschützt, für Treiber)

Die Klasse hält u. a. `temperature`, `accX/Y/Z`, `gyroX/Y/Z` (float) — primär intern; **empfohlen** ist weiterhin **`getEvent`**.

---

## Workshop-Hinweis

- **Temperatur:** immer über `getEvent(..., &temp)` → `temp.temperature`.  
- **Neigung / Bewegung:** aus `acceleration` und/oder `gyro` ableiten, auf 0.0–1.0 normieren.  
- **Motion-Interrupt:** nur wenn INT-Pin verdrahtet und Registrierung gewünscht.

---

## Abhängigkeiten

Adafruit Unified Sensor, Adafruit BusIO
