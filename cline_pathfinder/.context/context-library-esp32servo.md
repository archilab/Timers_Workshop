# ESP32Servo Library — Vollständiger API-Kontext

**PlatformIO:** `madhephaestus/ESP32Servo@^3.0.8`  
**Include:** `#include <ESP32Servo.h>`  
**Klasse:** `Servo` (nicht `ESP32Servo` als Klassenname)

Quellen: [ESP32Servo.h](https://github.com/madhephaestus/ESP32Servo/blob/master/src/ESP32Servo.h), [Doxygen](https://madhephaestus.github.io/ESP32Servo/classServo.html)

---

## Makros & Defaults (Auszug)

- `DEFAULT_uS_LOW` = 544, `DEFAULT_uS_HIGH` = 2400 (Standard-Arduino-Servo)
- `MIN_PULSE_WIDTH` = 500, `MAX_PULSE_WIDTH` = 2500 (erzwungene Grenzen für Pulse)
- `MAX_SERVOS` = 20 (oberes Limit; effektiv abhängig von ESP32-Variante)
- `DEFAULT_TIMER_WIDTH` = 10 (Bits), `MINIMUM_TIMER_WIDTH` / `MAXIMUM_TIMER_WIDTH` je nach Chip (C3 vs. andere)

---

## Arduino-kompatible API

| Methode | Beschreibung |
|--------|----------------|
| `Servo()` | Konstruktor |
| `int attach(int pin)` | Pin → nächster freier PWM-Kanal; Rückgabe Kanal oder **0** bei Fehler |
| `int attach(int pin, int min, int max)` | min/max **Mikrosekunden** (500–2500 erzwungen) |
| `void detach()` | Servo stoppen, Kanal freigeben |
| `void write(int value)` | Siehe Logik unten |
| `void writeMicroseconds(int value)` | Pulsweite µs (innerhalb min/max) |
| `void writeTicks(int value)` | feinste Auflösung (interne Ticks) |
| `int read()` | letzter Wert als **Winkel** 0–180 |
| `int readMicroseconds()` | letzte Pulsweite µs |
| `int readTicks()` | letzte Ticks |
| `bool attached()` | ob verbunden |
| `void release()` | Freigabe / PWM-Verhalten (siehe Implementierung) |

### `write(int value)` Semantik (laut Header-Kommentar)

- **&lt; 500:** als **Grad** 0–180 (Werte &lt;0 → 0, 181–499 → 180)
- **500–2500:** als **Mikrosekunden** (geclamped auf min/max aus `attach`)

---

## ESP32-spezifisch

| Methode | Beschreibung |
|--------|----------------|
| `void setTimerWidth(int value)` | PWM-Timerbreite (**16–20** typ., je nach Chip Grenzen) |
| `int readTimerWidth()` | aktuelle Breite |
| `void setPeriodHertz(int hertz)` | setzt `REFRESH_CPS` (Standard **50 Hz** Servo) und passt Timer an |

Unter der Haube: `ESP32PWM` mit fester Frequenz (LEDC/MCPWM je nach Chip — README der Library).

---

## Empfohlene GPIO (laut Header-Kommentar)

„Empfohlen“: **2, 4, 12–19, 21–23, 25–27, 32–33** — Workshop nutzt **GPIO 12** für Servo.

---

## Workshop: 0.0–1.0 → Winkel

```cpp
int angle = (int)(constrain(v, 0.0f, 1.0f) * 180.0f);
servo.write(angle);
```

Feinjustierung: `attach(12, minUs, maxUs)` für konkretes Servo-Modell (SG90 vs. andere).
