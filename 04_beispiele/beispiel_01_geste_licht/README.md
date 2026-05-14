# Beispiel 01 · Geste steuert Licht

## Die Idee

Eine Handbewegung über den Sensor lässt alle sechs LEDs aufleuchten. Keine Geste — kein Licht. Das Board reagiert lokal, ohne Netzwerk.

---

## Schritt 1 · GPT-Anfrage

**→ [Prompt ansehen](./prompt.md)**

Der verwendete Prompt beschreibt die Idee in einem Satz. Keine technischen Details, keine Pin-Nummern — nur das gewünschte Verhalten.

Der GPT antwortet mit zwei Dateien: `main.cpp` und `platformio.ini`.

---

## Schritt 2 · Code in PlatformIO

Die beiden Dateien aus dem GPT-Output werden in die folgende Struktur eingefügt:

```
code/
├── platformio.ini
└── src/
    └── main.cpp
```

Der fertige Code liegt bereits unter [`code/`](./code/) — er kann direkt geöffnet und verwendet werden.

In VSCode: **Datei → Ordner öffnen → `code/`**

PlatformIO lädt beim ersten Build automatisch alle Bibliotheken.

---

## Schritt 3 · Upload und Test

1. ESP32 anschließen
2. Upload-Button (→) in der Statusleiste klicken
3. Warten bis `SUCCESS` erscheint
4. Hand über den APDS9960 halten → LEDs leuchten auf

---

## Was passiert im Hintergrund

Der APDS9960 erkennt eine Geste und setzt den Wert auf `1.0`. Der NeoPixel-Strip empfängt diesen Wert und leuchtet mit maximaler Helligkeit. Wenn keine Geste erkannt wird, bleibt der Wert bei `0.0` — die LEDs bleiben aus.

Das Board ist nicht im WLAN — es arbeitet vollständig lokal. Das PairLink-System ist zwar im Code vorhanden, aber inaktiv.

---

→ Weiter: [Beispiel 02 · Bewegung steuert Servo](../beispiel_02_bewegung_servo/README.md)
