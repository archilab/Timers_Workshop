# System Prompt · Erklärt (Folkwang_Timers)

Der **Master Prompt** für das Custom GPT **Folkwang_Timers** ist die Datei **[`Arduino_Nano_MasterPrompt.md`](../Dataset_Timers/Arduino_Nano_MasterPrompt.md)** (Kopien: [`system_prompt.txt`](./system_prompt.txt), [`Dataset_Timers/system-prompt.txt`](../Dataset_Timers/system-prompt.txt)). Hier die Einordnung für Lehrende.

**Öffentlicher GPT:** [Folkwang_Timers in ChatGPT](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)

---

## Rolle

Der GPT agiert als **Arduino-/PlatformIO-Entwickler**, **Elektronik-Didaktik** und **Technical Writer**. Zielgruppe: **absolute Anfänger** — kurze Erklärungen, wenig Jargon, **vollständige** Projekte (nicht nur Code-Schnipsel).

---

## Hardware-Plattform

**Nur** klassischer **Arduino Nano (ATmega328P, 5 V, 16 MHz)**. Explizit **ausgeschlossen:** ESP32, Nano 33, RP2040, Teensy usw. — damit generierter Code auf der Workshop-Platine läuft.

| Bauteil | Anschluss |
|---------|-----------|
| Servo | **D9** |
| NeoPixel-Ring (12× WS2812B RGB) | **D10** |
| DS3231, VL53L0X, SSD1306, MPU6050 | **I²C** A4/A5 |

**MPU6050** im Workshop: **0x69** (Pin **AD0 → VCC**), damit die **DS3231** **0x68** behält.

---

## Speicher (ATmega328P)

32 KB Flash, 2 KB SRAM — der Prompt verlangt **sparsamen** Code: kein `String`, `F()` für Serial-Texte, wenig OLED-Updates, keine unnötigen Puffer.

---

## RTC (Pflicht)

Jedes Projekt mit Zeitbasis nutzt die **DS3231**. Uhrzeit wird **nicht** beim Upload automatisch überschrieben.

Stattdessen Serial-Befehl (115200 Baud):

```
SETTIME 2026-06-22 15:30:00
```

Format: **`SETTIME YYYY-MM-DD HH:MM:SS`**

Das gehört in die GPT-Antwort unter **RTC Setup** und **First Startup Procedure**.

---

## Nutzer-Projekt

Im Chat beschreibt man das Verhalten — der Prompt reserviert dafür **`[PROJECT DESCRIPTION]`**. Beispiele im Master Prompt: Abstand → NeoPixel-Helligkeit, Neigung → Servo, Uhr, Reaktionsspiel.

---

## Ausgabeformat (11 Teile)

Jede vollständige Antwort soll enthalten:

1. **Project Overview** — Idee in einfachen Worten  
2. **Required Components** — Bauteilliste  
3. **Wiring Table** — Pin-Tabelle  
4. **Breadboard Assembly Instructions** — Steckreihenfolge  
5. **PlatformIO Setup** — Ordner, VS Code, erster Build  
6. **`platformio.ini`** — vollständig  
7. **`src/main.cpp`** — vollständig  
8. **First Startup Procedure** — Upload, Serial Monitor  
9. **RTC Setup** — **SETTIME** erklären  
10. **Troubleshooting** — typische Fehler  
11. **Educational Explanation** — was der Code macht  

Das geht über das frühere „nur main.cpp + ini“ hinaus — bewusst **didaktisch** und **hardwarenah**.

---

## Knowledge-Dateien (Upload ins GPT)

Zusätzlich zum Master Prompt im Feld **Anweisungen** das **[`Dataset_Timers/`](../Dataset_Timers/)**-Paket (oder ZIP) hochladen:

| Priorität | Dateien |
|-----------|---------|
| 1 | `Arduino_Nano_MasterPrompt.md` / `system-prompt.txt` (falls nicht schon in Anweisungen) |
| 2 | `template-platformio.ini`, `rules-meta-layer.md`, `rules-validation.md` |
| 3 | `context-library-index.md`, `context-library-*.md` |
| 4 | `sample-*.cpp` (nur Muster — Regeln haben Vorrang) |

Reihenfolge: [`context-example-scripts.md`](../Dataset_Timers/context-example-scripts.md)

---

## Was sich gegenüber älteren Workshop-Versionen geändert hat

| Thema | Neu (Master Prompt) |
|-------|---------------------|
| NeoPixel-Datenpin | **D10** (nicht D6) |
| RTC | **SETTIME** per Serial, kein Auto-`adjust` |
| Antwort | **11 Abschnitte** inkl. Verdrahtung und Didaktik |
| Zielgruppe | Explizit **Anfänger** + Speicheroptimierung |
| Rolle | Educational project generator (nicht nur „Code-Snippet-GPT“) |

---

## Zusammenfassung

Der Master Prompt ist ein **didaktisches Regelwerk** für **lokale** Nano-Projekte mit **Zeit, Sensoren und Aktoren** — abgestimmt auf den **Timers Workshop** und den Namen **Folkwang_Timers**.
