# Prompt · Beispiel 02

## Der verwendete Prompt

> Der Servo soll sich je nach Neigung des Boards drehen. Wenn das Board flach liegt, steht der Servo in der Mitte. Je mehr ich es kippe, desto weiter dreht er sich. Alles auf einem Board, kein Netzwerk.

---

## Was der GPT daraus macht

- Sensor: MPU6050 (Beschleunigungssensor, da „Neigung" beschrieben)
- Aktor: Servo (GPIO 12)
- Normalisierung: X-Achse des Beschleunigungssensors → 0.0 bis 1.0
- Modus: Lokal (kein PairLink-Pairing)

---

## Variationen, die man ausprobieren kann

| Prompt-Änderung | Erwartetes Ergebnis |
|---|---|
| „...reagiert auf Erschütterung statt Neigung" | GPT verwendet den Betrag der Beschleunigung |
| „...Servo soll sich nur bewegen wenn das Board stark geneigt ist" | GPT fügt einen Schwellenwert hinzu |
| „...zusätzlich leuchten die LEDs wenn der Servo ganz außen ist" | GPT kombiniert Servo und NeoPixel |
