# FolkwangESP-GPT v5.2

Stable workshop release.

Includes:
- gesture-based default input (APDS9960); optional ALS/light/color and Lux on same sensor
- MPU6050 motion plus on-chip temperature via Unified Sensor events
- unified PairLink channel (sensor.value)
- multi-node interaction (swarm + smoothing)
- enforced PlatformIO dependencies

Build-safe and beginner-safe.

## Filename scheme (this folder)

| Präfix | Bedeutung | Beispiele |
|--------|-----------|-----------|
| `system-` | System Prompt für das Custom GPT | `system-prompt.txt` |
| `rules-` | Kurze normative Workshop-Regeln | `rules-meta-layer.md`, `rules-validation.md` |
| `context-` | Wissens-/API-Kontext | `context-pairlink.md`, `context-library-index.md`, `context-library-*.md`, `context-example-scripts.md` |
| `config-` | Maschinenlesbare Konfiguration | `config-routing.json` |
| `template-` | Vorlage für Teilnehmer-Projekte | `template-platformio.ini` |
| `sample-` | Beispiel-Sketches (kein `main.cpp`) | `sample-gesture-apds9960.cpp`, … |
| `one-shot-` | Alles-in-einem, komprimiert (Paste / langer Kontext) | `one-shot-prompt.md` |

Generierte Projekte verwenden weiterhin **`src/main.cpp`** und **`platformio.ini`** — die Dataset-Dateinamen sind nur für Upload und Navigation.

**Kurzstart:** [`one-shot-prompt.md`](./one-shot-prompt.md) bündelt System Prompt, Regeln, `platformio.ini`, Routing, PairLink-Kern und Library-Cheat-Sheet; für vollständige APIs weiterhin `context-library-*.md` und `context-pairlink.md` nutzen.

---

## Custom GPT knowledge — recommended bundle

1. **Rules (normative):** `system-prompt.txt`, `rules-meta-layer.md`, `rules-validation.md`  
2. **PairLink:** `context-pairlink.md`  
3. **Libraries (offline API):** `context-library-index.md` + all `context-library-*.md`  
4. **How examples fit in:** **`context-example-scripts.md`** — maps `sample-*.cpp`, `template-platformio.ini`, `config-routing.json` to the stack above; lists upload order. Example `sample-*.cpp` files are **patterns only**; the manifest coordinates them.  
5. **Examples / template:** `template-platformio.ini`, `sample-gesture-apds9960.cpp`, `sample-mpu6050-servo.cpp`, `sample-neopixel-actor.cpp`, `sample-swarm-node.cpp`, `sample-smooth-node.cpp`, `config-routing.json`

Together this lets the model resolve **Adafruit / ESP32Servo / ArduinoJson / ArduinoWebsockets** APIs without live web access, while treating sample scripts as reference sketches, not overrides for system rules.

---

## Cline.dev (VS Code agent)

Self-contained bundle for [Cline](https://cline.bot): **[`../cline_pathfinder/`](../cline_pathfinder/)** — includes `CLINE.md`, **`.cline/rules/*.md`** (generator contract in **`07-generator-contract.md`**, replaces root `system-prompt.txt`), and **`.context/`** (same role as `claude_pathfinder/`). Copy **`.cline/rules/*.md`** → **`.clinerules/`** at the repo root (see `cline_pathfinder/README.md`).

## Claude Code (terminal / IDE agent)

Self-contained bundle for [Claude Code](https://code.claude.com/docs): **[`../claude_pathfinder/`](../claude_pathfinder/)** — includes `CLAUDE.md`, **`.claude/rules/*.md`** (generator contract in **`07-generator-contract.md`**, replaces root `system-prompt.txt`), and under **`.context/`**: `rules-*.md`, `context-*.md`, `template-platformio.ini`, `config-routing.json`, `sample-*.cpp`. Install steps: `claude_pathfinder/README.md`.
