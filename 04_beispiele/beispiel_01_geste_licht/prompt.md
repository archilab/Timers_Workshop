# Prompt · Beispiel 01

## Der verwendete Prompt

> Wenn ich die Hand über den Sensor halte, sollen alle sechs LEDs aufleuchten. Kein Netzwerk, alles auf einem Board.

---

## Was der GPT daraus macht

Aus dieser einzeiligen Beschreibung leitet der GPT ab:

- Sensor: APDS9960 (Standard-Gestensensor, da kein anderer angegeben)
- Aktor: NeoPixel Strip (6 Pixel, GPIO 14)
- Modus: Lokal (kein PairLink-Pairing aktiv)
- Verhalten: Geste erkannt → Wert 1.0 → LEDs voll an; keine Geste → Wert 0.0 → LEDs aus

Alle technischen Details — Pins, Bibliotheken, Normalisierung — fügt der GPT eigenständig hinzu.

---

## Variationen, die man ausprobieren kann

| Prompt-Änderung | Erwartetes Ergebnis |
|---|---|
| „...die LEDs sollen langsam aufleuchten" | GPT fügt eine Überblendung hinzu |
| „...die LEDs sollen blau leuchten" | GPT setzt die Farbe auf Blau |
| „...nicht alle LEDs, nur die ersten drei" | GPT begrenzt die Pixelanzahl |

Diese Variationen zeigen, wie man über natürliche Sprache das Verhalten anpasst — ohne den Code selbst anzufassen.
