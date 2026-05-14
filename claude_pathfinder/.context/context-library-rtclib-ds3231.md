# RTClib — DS3231 (Vollständiger API-Kontext)

**PlatformIO:** `adafruit/RTClib`  
**Include:** `#include <RTClib.h>`  
**Timers Workshop:** DS3231 nutzt **I²C `0x68`**. Der **MPU6050** liegt daher am Workshop an **`0x69`** (AD0 → VCC).

Quellen: [RTClib.h](https://github.com/adafruit/RTClib/blob/master/src/RTClib.h), [Adafruit Learn — DS3231](https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout-board-kit/overview)

---

## 1. Klasse `RTC_DS3231` — Initialisierung & Zeit

| Methode | Beschreibung |
|--------|----------------|
| `bool begin(TwoWire *wireInstance = &Wire)` | I²C-Gerät ansprechen; **`true`** wenn DS3231 antwortet. Vorher **`Wire.begin()`** aufrufen. |
| `void adjust(const DateTime &dt)` | Uhrzeit/Datum **setzen** (Schreibzugriff auf RTC-Register). |
| `DateTime now()` | Aktuelle Zeit als **`DateTime`** lesen. |
| `bool lostPower(void)` | **`true`**, wenn OSF-Flag gesetzt (z. B. Stromausfall / leere Batterie — Zeit kann ungültig sein). Nach `adjust()` typischerweise zurückgesetzt. |

---

## 2. `DateTime` — Felder, Konstruktoren, Vergleiche

`DateTime` speichert **keine** Zeitzone; gültiger Bereich laut Header typischerweise **2000-01-01 … 2099-12-31**.

### Konstruktoren (Auswahl)

| Signatur | Nutzung |
|----------|---------|
| `DateTime(uint32_t t = SECONDS_FROM_1970_TO_2000)` | Sekunden seit **2000-01-01 00:00:00** (interner Epoch-Offset der Library). |
| `DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour=0, uint8_t min=0, uint8_t sec=0)` | Kalenderdatum; **Jahr voll** (z. B. 2026). |
| `DateTime(const char *date, const char *time)` | Strings wie `"Dec 26 2015"` / `"12:34:56"` (siehe Library-Doku). |
| `DateTime(const __FlashStringHelper *date, const __FlashStringHelper *time)` | Varianten für PROGMEM (`F(__DATE__)`, `F(__TIME__)`) — **einmalige** Compile-Zeit-Initialisierung. |
| `DateTime(const char *iso8601date)` | z. B. `"2015-12-26T12:34:56"` |

### Zugriff (Getter)

| Methode | Rückgabe |
|---------|----------|
| `uint16_t year()` | Jahr **2000…2099** |
| `uint8_t month()` | **1…12** |
| `uint8_t day()` | **1…31** |
| `uint8_t hour()` | **0…23** |
| `uint8_t twelveHour()` | 12-Stunden-Format |
| `uint8_t isPM()` | **1** wenn PM, sonst **0** |
| `uint8_t minute()`, `second()` | **0…59** |
| `uint8_t dayOfTheWeek()` | **0 = Sonntag … 6 = Samstag** |
| `uint32_t unixtime()` | Sekunden seit **1970-01-01** (32-Bit; beachte Jahr-2038-Thema bei langfristiger Speicherung). |
| `uint32_t secondstime()` | Sekunden seit **2000-01-01** |
| `String timestamp(timestampOpt opt)` | `TIMESTAMP_FULL` / `TIMESTAMP_TIME` / `TIMESTAMP_DATE` (ISO-ähnliche Strings; braucht **String**-Support auf der Plattform). |

### Validierung & String

- `bool isValid() const` — prüft Plausibilität des `DateTime`-Tupels.  
- `char *toString(char *buffer) const` — kompaktes Format in **vom Aufrufer bereitgestellten** Puffer.

### Operatoren

`+` / `-` mit **`TimeSpan`**; **`operator-`** zwischen zwei `DateTime` liefert **`TimeSpan`**. Vergleiche: **`<` `>` `<=` `>=` `==` `!=`** (bei ungültigen Werten laut Doku Vorsicht).

---

## 3. `TimeSpan`

Differenzen / Offsets in **Sekundengenauigkeit**:

| Konstruktor | Beispiel |
|-------------|----------|
| `TimeSpan(int32_t seconds)` | `TimeSpan(3600)` = 1 h |
| `TimeSpan(int16_t days, int8_t h, int8_t m, int8_t s)` | Mehrfeld |

Getter: **`days()`**, **`hours()`**, **`minutes()`**, **`seconds()`** (Anteile), **`totalseconds()`** (Gesamt).

---

## 4. DS3231 — SQW / 32 kHz / Chip-Temperatur

| Methode | Beschreibung |
|--------|----------------|
| `Ds3231SqwPinMode readSqwPinMode()` | Aktuellen Modus lesen. |
| `void writeSqwPinMode(Ds3231SqwPinMode mode)` | Rechteckwellen auf **SQW**: `DS3231_OFF`, `DS3231_SquareWave1Hz`, `1kHz`, `4kHz`, `8kHz`. |
| `void enable32K(void)` / `void disable32K(void)` | **32 kHz**-Ausgang (falls am Chip angebunden). |
| `bool isEnabled32K(void)` | Status 32 kHz-Ausgang. |
| `float getTemperature()` | **Interne** Chip-Temperatur in **°C** (kein externer Sensor; für Diagnose / grobe Umgebung). |

---

## 5. Alarme 1 & 2

| Methode | Beschreibung |
|--------|----------------|
| `bool setAlarm1(const DateTime &dt, Ds3231Alarm1Mode mode)` | Weckzeit **Alarm 1**; Modus bestimmt welche Felder verglichen werden (`DS3231_A1_PerSecond` … `DS3231_A1_Day`). |
| `bool setAlarm2(const DateTime &dt, Ds3231Alarm2Mode mode)` | **Alarm 2** (minutengenauer, je nach `Ds3231Alarm2Mode`). |
| `DateTime getAlarm1()`, `getAlarm2()` | eingestellte Alarmzeit lesen |
| `Ds3231Alarm1Mode getAlarm1Mode()`, `getAlarm2Mode()` | Modus lesen |
| `void disableAlarm(uint8_t alarm_num)` | **1** oder **2** |
| `void clearAlarm(uint8_t alarm_num)` | Flag nach Auslösung löschen |
| `bool alarmFired(uint8_t alarm_num)` | ob Alarm ausgelöst hat |

**Hinweis:** Hardware-INT-Pin des Moduls muss ggf. mit MCU verbunden und per Register/IRQ ausgewertet werden — rein über diese High-Level-Methoden steuert man die **RTC-Seite** der Alarme.

---

## 6. Hilfs-Enum & I²C

- **`Ds3231SqwPinMode`** — siehe Abschnitt 4.  
- **`Ds3231Alarm1Mode` / `Ds3231Alarm2Mode`** — siehe Abschnitt 5.  
- **`RTC_DS3231::dowToDS3231(uint8_t d)`** — konvertiert Library-Wochentag (**0=So**) in DS3231-Konvention (**1=Mo … 7=So**).

Basisklasse **`RTC_I2C`** ist nur intern relevant (`read_register` / `write_register`).

---

## 7. Workshop-Hinweise

- **`lostPower()`**: nach Batteriewechsel oder erstem Einbau oft **`true`** → **`adjust(...)`** setzen.  
- **`rtc.adjust(DateTime(F(__DATE__), F(__TIME__)))`**: setzt Zeit auf **Compile-Zeit** — gut für Demos, schlecht für „echte“ Uhren (lieber serielle Eingabe oder NTP auf einem anderen System, hier nicht vorgesehen).  
- **Zeitvergleiche:** `now()` in Variable, mit anderem `DateTime` oder mit `TimeSpan` verrechnen (`if (now.unixtime() > t0.unixtime()) …`).  
- **Speicher:** `DateTime` ist kompakt; für Logik oft **`unixtime()`** oder explizite Stunden/Minuten-Felder.

---

## Abhängigkeiten

**Adafruit BusIO** (über RTClib / Adafruit-Paketstruktur), **Wire**.
