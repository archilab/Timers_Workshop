# Beispiel 02 · Bewegung steuert Servo

## Die Idee

Das Board selbst wird zum Eingabegerät. Je nachdem wie stark es geneigt wird, dreht sich der Servo in eine bestimmte Position. Das Objekt reagiert auf seine eigene Lage im Raum.

---

## Schritt 1 · GPT-Anfrage

**→ [Prompt ansehen](./prompt.md)**

Die Anfrage beschreibt eine physische Interaktion: das Neigen des Boards. Der GPT wählt automatisch den MPU6050 als passenden Sensor aus.

---

## Schritt 2 · Code in PlatformIO

Die Projektstruktur:

```
code/
├── platformio.ini
└── src/
    └── main.cpp
```

In VSCode: **Datei → Ordner öffnen → `code/`**

Beim ersten Build werden automatisch geladen: MPU6050-Bibliothek, Adafruit Unified Sensor, ESP32Servo, PairLink, ArduinoWebsockets, ArduinoJson.

---

## Schritt 3 · Upload und Test

1. ESP32 anschließen
2. Upload starten (→ in der Statusleiste)
3. Nach `SUCCESS`: Board in verschiedene Winkel neigen
4. Der Servo dreht sich entsprechend der Neigung

Im Serial Monitor sieht man den aktuellen Neigungswert als Zahl zwischen `0.0` und `1.0`.

---

## Was passiert im Hintergrund

Der MPU6050 liefert die Beschleunigung auf der X-Achse. Dieser Rohwert (ca. -10 bis +10 m/s²) wird auf den Bereich `0.0–1.0` normalisiert. Der Servo empfängt diesen Wert und dreht sich auf den entsprechenden Winkel (0° bis 180°).

---

→ Weiter: [Beispiel 03 · Swarm-Installation](../beispiel_03_swarm_installation/README.md)
