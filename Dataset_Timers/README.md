# Dataset_Timers — Folkwang_Timers (Timers Workshop)

Dieser Ordner enthält **Knowledge**-Dateien für ein Custom GPT mit dem Namen **Folkwang_Timers** (Timers Workshop, **Arduino Nano**).

**Öffentlicher GPT:** [Folkwang_Timers in ChatGPT öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)

## Kern

- **`Arduino_Nano_MasterPrompt.md`** — **Master Prompt** (didaktischer Projektgenerator, 11-teiliges Antwortformat, RTC **SETTIME**)
- **`system-prompt.txt`** — gleicher Inhalt zum Einfügen in ChatGPT **Anweisungen**
- **`one-shot-prompt.md`** — gekürzte Variante

## Ergänzendes Wissen

- **`rules-meta-layer.md`**, **`rules-validation.md`**
- **`context-library-*.md`**, **`context-library-index.md`**
- **`context-example-scripts.md`**, **`template-platformio.ini`**, **`config-routing.json`**
- **`sample-*.cpp`** — Mustercode (Regeln / Master Prompt haben Vorrang)

Agent-Regeln im Repo: **`claude_pathfinder/.claude/rules/07-generator-contract.md`** (Spiegel des Master Prompts + Workshop-Details).

Teilnehmer laden den Ordner **`Dataset_Timers/`** direkt als Knowledge in ChatGPT hoch (siehe [05 Custom GPT](../05_custom_gpt/README.md)).
