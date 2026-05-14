# Arduino Nano

Der **Arduino Nano** (hier: klassischer **ATmega328P**, 5V) ist der Mikrocontroller des **Timers Workshop**. Er führt deinen Sketch aus und spricht über **I²C** und **digitale Pins** mit RTC, Sensoren, OLED, NeoPixel und Servo.

## Wichtige Anschlüsse

- **USB:** Programmieren und Stromversorgung vom Laptop  
- **A4 / A5:** I²C (**SDA** / **SCL**) für DS3231, VL53L0X, SSD1306, MPU6050  
- **D6:** NeoPixel-Datenleitung (Workshop-Festlegung)  
- **D9:** Servo-Signal (Workshop-Festlegung)  
- **D13:** eingebaute LED (optional zum Testen)

## Software

Im Workshop wird **PlatformIO** mit dem Environment **`nanoatmega328`** und **`platform = atmelavr`** verwendet.
