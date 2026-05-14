# Schritt 1 · GPT-Anfrage formulieren

**→ [Custom GPT öffnen](https://chatgpt.com/g/g-69b6eda5e8888191b2000af26055b60b-folwang-pairlink-starter)**

---

## Was der GPT braucht

Der GPT ist spezialisiert — er erzeugt ausschließlich Code für den ESP32 mit den Workshop-Komponenten. Um funktionierenden Code zu generieren, braucht er drei Informationen:

**1. Was ist der Eingang?**
Womit wird die Installation gesteuert — eine Geste, eine Bewegung, eine Neigung?

**2. Was ist der Ausgang?**
Was soll passieren — leuchten die LEDs, dreht sich der Servo?

**3. Wie sollen sie zusammenhängen?**
Direkt auf einem Board, oder über zwei getrennte Boards via WLAN (PairLink)?

---

## Prompt-Vorlage

```
Ich möchte [EINGANG] mit [AUSGANG] verbinden.
[Optional: Das soll über zwei Boards via PairLink funktionieren.]
[Optional: Zusätzliche Beschreibung des Verhaltens.]
```

---

## Beispiele — gut vs. weniger gut

| Weniger gut | Besser |
|---|---|
| „Mach was mit dem Sensor" | „Wenn ich die Hand über den Sensor halte, sollen alle LEDs aufleuchten" |
| „LED und Bewegung" | „Der Servo dreht sich je nach Neigung des Boards — stark geneigt = weit gedreht" |
| „Zwei Boards verbinden" | „Gerät A misst Gesten, Gerät B reagiert mit dem Servo — über PairLink verbunden" |

Die Anfrage muss nicht technisch sein. Der GPT übersetzt künstlerische Beschreibungen in Code.

---

## Weitere Prompt-Ideen

- **[Beispielprompts](./pathfinder_prompts.md)** — stufenweise Beispiele (Einstieg bis Experiment) zum Kopieren und Variieren  
- **[Prompt-Patterns / Baukasten](./prompt_patterns_baukasten.md)** — Muster und Bausteine (Input → Transformation → Output), um eigene Prompts systematisch zu formulieren  

---

## Was der GPT ausgibt

Nach der Anfrage liefert der GPT immer zwei Dateien:

- `main.cpp` — der eigentliche Code
- `platformio.ini` — die Projektkonfiguration mit allen Bibliotheken

Beide Dateien werden im nächsten Schritt verwendet.

---

→ Weiter: [Schritt 2 · Code in PlatformIO einsetzen](./schritt_2_platformio.md)
