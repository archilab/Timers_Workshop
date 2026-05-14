# Example scripts — Custom GPT integration (read-first)

Die folgenden Dateien sind **Referenzbeispiele** (Muster für Struktur, PairLink-Nutzung und Sensordaten). Sie sind **keine** normativen Spezifikationen: Verhalten, Pins und API-Details sind in **`system-prompt.txt`**, **`context-pairlink.md`**, **`rules-meta-layer.md`**, **`rules-validation.md`** und den **`context-library-*.md`** verbindlich, wenn es Abweichungen gibt.

---

## Priorität im Wissens-Stack (höher = zuerst anwenden)

1. **`system-prompt.txt`** — Rollen, Pflicht-Includes, `lib_deps`, feste Pins, Ausgabeformat  
2. **`context-pairlink.md`** — PairLink-API, Kanäle, `pairLink.update()`, Konfiguration  
3. **`rules-meta-layer.md`** + **`rules-validation.md`** — Workshop-Regeln (Default-Sensor, verbotene Muster, Checks)  
4. **`context-library-index.md`** → **`context-library-*.md`** — vollständige Bibliotheks-APIs  
5. **Beispiel-Skripte** (`sample-*.cpp`) + **`template-platformio.ini`** — illustrieren typische Kombinationen; bei Konflikten **nicht** gegen 1–4 verletzen  
6. **`config-routing.json`** — optionale Sensor-Alias-Logik für Routing/Defaults (kein Ersatz für System Prompt)

---

## Datei-Katalog (was wofür dient)

| Datei | Inhalt | Passende Library-Contexts |
|-------|--------|---------------------------|
| **`sample-gesture-apds9960.cpp`** | APDS9960 + PairLink: Geste → `sensor.value`, lokaler Fallback | `context-library-adafruit-apds9960.md` |
| **`sample-mpu6050-servo.cpp`** | MPU6050 + Servo + PairLink: Beschleunigung normalisiert → `sensor.value` | `context-library-adafruit-mpu6050.md`, `context-library-esp32servo.md`, `context-library-adafruit-unified-sensor.md` |
| **`sample-neopixel-actor.cpp`** | NeoPixel-Aktor + PairLink (hier Demo-Eingang `random`) | `context-library-adafruit-neopixel.md` |
| **`sample-swarm-node.cpp`** | APDS9960 + Servo, Netzwerkwert und lokaler Sensor kombiniert | APDS9960 + ESP32Servo + `context-pairlink.md` |
| **`sample-smooth-node.cpp`** | APDS9960 + gleitender Wert über empfangene `sensor.value` | APDS9960 + `context-pairlink.md` |
| **`template-platformio.ini`** | **Template** für `lib_deps` und `env` (Workshop-Set) | Spiegel mit `system-prompt.txt` / Index; generierte Projekte nutzen **`src/main.cpp`**, nicht diese Dateinamen |
| **`rules-meta-layer.md`** | Kurzregeln (Default-Sensor, Kanal, keine `analogRead` …) | Vor Skript-„Kreativität“ anwenden |
| **`config-routing.json`** | Alias → Sensor-Typ (`gesture`→`apds9960`, `motion`→`mpu6050`, …) | Nur semantische Zuordnung; Hardware bleibt aus System Prompt |

---

## Konventionen für das GPT

- **Ausgabe-Dateiname:** Immer **`main.cpp`** (und `platformio.ini`) im generierten Projekt — die Dataset-Samples heißen `sample-*.cpp` nur als **Referenz**.  
- **Beispiele als Muster:** Struktur übernehmen (`setup`/`loop`, `pairLink.begin`, Kanäle, `isPaired`-Zweig), aber **Pins, Normalisierung und Sensor-Setup** an Aufgabe und `context-library-*` anpassen.  
- **I²C:** Wenn ein Sample `Wire.begin(21,22)` weglässt, trotzdem gemäß Workshop **`Wire.begin(21, 22)`** in echten Sketches setzen, sofern I²C-Sensoren genutzt werden.  
- **`rules-validation.md`:** z. B. `analogRead` verboten (außer explizit angefordert) — auch wenn ein älteres Beispiel `analogWrite` o. Ä. zeigt: **Validierungsregeln** und System Prompt haben Vorrang für neue Generierung.

---

## Empfohlene Upload-Reihenfolge (Custom GPT „Knowledge“)

1. `system-prompt.txt`  
2. `rules-meta-layer.md`, `rules-validation.md`  
3. `context-pairlink.md`  
4. `context-library-index.md` + alle `context-library-*.md`  
5. `context-example-scripts.md` (**diese Datei**)  
6. `config-routing.json`  
7. `template-platformio.ini`  
8. `sample-gesture-apds9960.cpp`, `sample-mpu6050-servo.cpp`, `sample-neopixel-actor.cpp`, `sample-swarm-node.cpp`, `sample-smooth-node.cpp`  

So weiß das Modell, dass Punkt 5–8 **Beispiele/Templates** sind und Punkt 1–4 die **Regeln** sind.

---

## Kurzreferenz `config-routing.json`

```json
{
  "sensor_map": {
    "gesture": "apds9960",
    "motion": "mpu6050",
    "distance": "apds9960",
    "light": "apds9960",
    "lux": "apds9960",
    "color": "apds9960",
    "als": "apds9960",
    "temperature": "mpu6050",
    "temp": "mpu6050"
  },
  "fallback": { "sensor": "gesture" }
}
```

- **`distance`** → selber Chip wie Nähe am APDS9960 (semantisch, nicht separates Bauteil).  
- **`light` / `lux` / `color` / `als`** → APDS9960 ALS (`enableColor`, `getColorData`, ggf. `calculateLux` / `calculateColorTemperature`).  
- **`temperature` / `temp`** → MPU6050 On-Chip-Temperatur (`getEvent` drittes Event).  
- **`fallback.sensor: gesture`** → Default-Pfad entspricht **`rules-meta-layer.md`** (APDS9960 / Geste).
