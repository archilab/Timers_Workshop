# 01 · Uhrzeit auf dem OLED

Dieses Beispiel zeigt den **Timers Workshop**-Workflow: eine kurze Beschreibung an **Folkwang_Timers**, der generierte **Arduino-Nano**-Code mit **DS3231** und **SSD1306**, Upload und Test.

## Idee

Die aktuelle Uhrzeit soll **groß auf dem OLED** erscheinen — Ausgangspunkt für Installationen, die **Zeit** sichtbar machen.

## Hardware

- Arduino Nano, DS3231, SSD1306 (128×64, I²C), gemeinsamer Bus **A4/A5**.

## Ablauf

1. Prompt formulieren (siehe `prompt.md`).  
2. Antwort in PlatformIO (`code/`) übernehmen — `pio run`, Upload.  
3. Beobachten: läuft die Uhr plausibel? (Einmalige Zeiteinstellung mit `rtc.adjust(...)` im Code möglich.)

## Ergebnis

Der Ordner `code/` enthält ein lauffähiges **Nano**-Projekt passend zu `template-platformio.ini` des Workshops.
