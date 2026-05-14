# 04 · Beispiele

Drei vollständige Durchläufe des Workshop-Workflows — von der GPT-Anfrage bis zum laufenden Code auf dem Controller. Jedes Beispiel dokumentiert den Prozess, nicht den Code.

---

## Die drei Beispiele

| Beispiel | Sensor | Aktor | Modus |
|---|---|---|---|
| [01 · Geste steuert Licht](./beispiel_01_geste_licht/README.md) | APDS9960 (Geste) | NeoPixel Strip | Lokal |
| [02 · Bewegung steuert Servo](./beispiel_02_bewegung_servo/README.md) | MPU6050 (Neigung) | Servo | Lokal |
| [03 · Swarm-Installation](./beispiel_03_swarm_installation/README.md) | APDS9960 (Geste) | Servo auf zweitem Board | PairLink (Netzwerk) |

---

## Wie die Beispiele aufgebaut sind

Jedes Beispiel enthält:

- `README.md` — Idee, Prompt, Ergebnis, Beobachtungen
- `prompt.md` — der exakte Text, der an den GPT geschickt wurde
- `code/` — der vollständige, unveränderte GPT-Output als lauffähiges PlatformIO-Projekt

Die `code/`-Ordner können direkt in VSCode geöffnet und auf den ESP32 übertragen werden.
