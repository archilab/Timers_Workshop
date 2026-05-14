# 01 · Komponenten

Der Workshop verwendet fünf Hardware-Komponenten. Du musst nicht verstehen, wie sie intern funktionieren — aber es hilft zu wissen, was jede davon tut und wofür du sie einsetzen kannst.

---

## Überblick

| Komponente | Typ | Funktion |
|---|---|---|
| [ESP32-PICO-KIT](./esp32_pico.md) | Mikrocontroller | Das Gehirn — führt den Code aus |
| [APDS9960](./apds9960.md) | Sensor | Gesten, Nähe, Umgebungslicht und Farbe (Library) |
| [MPU6050](./mpu6050.md) | Sensor | Bewegung, Neigung, Temperatur (Library) |
| [NeoPixel Strip](./neopixel.md) | Aktor | 6 individuell steuerbare RGB-LEDs |
| [Servo](./servo.md) | Aktor | Dreht sich auf einen bestimmten Winkel 0-180° |

---

## Sensoren und Aktoren

Der GPT unterscheidet zwischen zwei Arten von Komponenten:

**Sensoren** nehmen etwas aus der Welt auf — eine Bewegung, eine Geste, eine Neigung, **Licht oder Farbe**, **Temperatur** — und wandeln es in eine Zahl zwischen `0.0` und `1.0` um.

**Aktoren** reagieren auf eine solche Zahl — sie leuchten heller oder dunkler, drehen sich weiter oder weniger weit.

Das ist das grundlegende Prinzip aller generierten Sketches.

---

## Verkabelung

Steckplatine und Schaltplan zeigen alle Bauteile und Verbindungen des vollständigen Workshop-Sets (dieselben Abbildungen wie in der [Projekt-README](../README.md)).

![Steckplatine — Aufbau aller Workshop-Komponenten](../pathfinder_Steckplatine.svg)

![Schaltplan — Verschaltung aller Workshop-Komponenten](../pathfinder_Steckplatine_circuit.svg)

Alle Pins sind im GPT fest eingebaut. Du musst keine Pin-Nummern kennen oder angeben.

---

## Referenzen & Libraries

Eine vollständige Übersicht aller verwendeten Bibliotheken, Datasheets und Quellen findest du unter:

**→ [Libraries & Referenzen](./referenzen.md)**
