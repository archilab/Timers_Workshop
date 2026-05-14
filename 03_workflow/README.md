# 03 · Der Workflow

Der gesamte Prozess — von der Idee bis zur laufenden Installation — besteht aus drei Schritten. Kein Schritt erfordert Programmierkenntnisse.

---

## Der Prozess

```
┌─────────────────────────────────────────────────────┐
│                                                     │
│   1.  Idee beschreiben  →  Custom GPT              │
│                              ↓                      │
│   2.  Code einfügen     →  PlatformIO              │
│                              ↓                      │
│   3.  Upload starten    →  Arduino Nano            │
│                                                     │
└─────────────────────────────────────────────────────┘
```

**GPT:** [Folkwang_Timers in ChatGPT öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)

---

## [Schritt 1 · GPT-Anfrage formulieren](./schritt_1_gpt_anfrage.md)

Wie formuliert man eine Idee so, dass der GPT versteht, was gemeint ist? Was muss man angeben, was nicht? Mit Prompt-Vorlagen und Beispielen.

**→ [Beispielprompts (Einstieg bis Experiment)](./pathfinder_prompts.md)** — stufenweise Prompt-Ideen zum Kopieren, Variieren und Kombinieren.

**→ [Prompt-Patterns / Baukasten](./prompt_patterns_baukasten.md)** — Muster (Mapping, Schwelle, Metapher …) und Vorlage, um eigene Prompts strukturiert zu bauen.

## [Schritt 2 · Code in PlatformIO einsetzen](./schritt_2_platformio.md)

Der GPT liefert zwei Dateien. Wo kommen sie hin? Wie sieht ein gültiges Projekt aus? Was muss geprüft werden bevor der Upload startet?

## [Schritt 3 · Auf den Controller übertragen](./schritt_3_deploy.md)

Upload starten, Serial Monitor lesen, häufige Probleme erkennen und lösen. Bei Hardware-Problemen helfen [Steckplatine & Schaltplan](../01_komponenten/README.md#verkabelung) zum Abgleich der Verkabelung.

---

Die drei Schritte sind in den [Beispielen](../04_beispiele/README.md) jeweils vollständig dokumentiert — einmal komplett durchgearbeitet, läuft der Prozess anschließend aus dem Gedächtnis.
