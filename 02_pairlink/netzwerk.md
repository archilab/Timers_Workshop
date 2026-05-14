# I²C-Bus (Nano) — kein Netzwerk

Der **Timers Workshop** nutzt **kein WLAN** und keine WebSockets. Stattdessen verbinden sich alle I²C-Module mit **A4 (SDA)** und **A5 (SCL)**.

## Adressen (Workshop-Standard)

| Modul    | Adresse | Hinweis |
|----------|---------|---------|
| DS3231   | 0x68    | RTC |
| MPU6050  | **0x69**| **AD0-Pin an VCC** — sonst Kollision mit der RTC |
| VL53L0X  | 0x29    | Standard |
| SSD1306  | 0x3C oder 0x3D | Auf dem Modul prüfen |

## Ablauf im Code

1. `Serial.begin(115200);` falls du Meldungen brauchst.  
2. `Wire.begin();` **einmal** in `setup()`.  
3. Danach `begin()` der Module in sinnvoller Reihenfolge (z. B. RTC, Display, ToF, MPU).

## Typische Probleme

- **Nichts antwortet:** SDA/SCL vertauscht oder schlechte Lötstelle.  
- **MPU + RTC gleichzeitig „weg“:** MPU noch auf **0x68** — AD0 muss an **VCC** für **0x69**.  
- **OLED schwarz:** falsche Adresse (0x3C vs 0x3D) oder fehlendes `display.display()`.
