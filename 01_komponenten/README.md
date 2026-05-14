# 01 · Komponenten

Der **Timers Workshop** nutzt mehrere Module auf einem **Arduino Nano**. Du musst nicht jedes Datenblatt lesen — aber eine kurze Vorstellung hilft beim Prompten mit **Folkwang_Timers**.

---

## Überblick

| Komponente | Typ | Funktion |
|---|---|---|
| [Arduino Nano](./arduino_nano.md) | Mikrocontroller | Führt den Code aus |
| [DS3231](./ds3231.md) | Sensor/Zeit | Echtzeituhr (I²C) |
| [VL53L0X](./vl53l0x.md) | Sensor | Distanz in mm (I²C) |
| [SSD1306 OLED](./ssd1306.md) | Aktor/Anzeige | 128×64 Pixel (I²C) |
| [MPU6050](./mpu6050.md) | Sensor | Bewegung, Neigung, Temperatur (I²C, **0x69**) |
| [NeoPixel Strip](./neopixel.md) | Aktor | 6 RGBW-Pixel (Daten **D6**) |
| [Servo](./servo.md) | Aktor | Winkel 0–180° (Signal **D9**) |

---

## Sensoren und Aktoren

**Sensoren** liefern Messwerte — z. B. **Zeit**, **Abstand mm**, **Beschleunigung**, **Temperatur**.  
**Aktoren** setzen das sichtbar oder beweglich um: **OLED**, **NeoPixel**, **Servo**.

---

## Verkabelung

Steckplatine und Schaltplan im [README](../README.md) werden an **Nano + neue Module** angepasst (siehe [`NON_MARKDOWN_MIGRATION_CHECKLIST.md`](../NON_MARKDOWN_MIGRATION_CHECKLIST.md) für SVG-Nachzug).

---

## Referenzen & Libraries

**→ [Libraries & Referenzen](./referenzen.md)**
