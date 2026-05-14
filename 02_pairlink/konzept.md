# Uhrzeit und Anzeige

## DS3231 (RTC)

Die **DS3231** hält **Sekunden, Minuten, Stunden, Tag, Monat, Jahr** bereit. Typischer Ablauf:

- `RTC_DS3231 rtc;`  
- Nach `Wire.begin()` → `rtc.begin()`  
- In `loop()`: `DateTime now = rtc.now();` und Werte auf dem **SSD1306** ausgeben oder für Logik nutzen (z. B. „nach 18 Uhr“).

## OLED SSD1306

Das **128×64**-Display zeigt Text und einfache Grafik. Nach jedem Zeichenblock **`display.display()`** aufrufen. Häufiges Neuzeichnen kostet Zeit — für schnelle VL53-Messungen lieber nur einige Male pro Sekunde aktualisieren.

## MPU6050 und Adresse 0x69

**DS3231** und **MPU6050** würden beide gern **0x68** nutzen. Im Workshop ist vereinbart: **MPU6050 mit AD0 an VCC → Adresse 0x69**, RTC bleibt auf **0x68**.

Im Code: `mpu.begin(0x69, &Wire, 0);`

## Distanz VL53L0X

Der Sensor liefert **Millimeter** (Einzelmessung). Werte lassen sich auf NeoPixel-Helligkeit, Servo-Winkel oder Text auf dem OLED mappen.
