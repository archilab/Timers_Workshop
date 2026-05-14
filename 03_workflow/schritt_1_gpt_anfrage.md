# Schritt 1 · GPT-Anfrage formulieren

**[→ Folkwang_Timers in ChatGPT öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)**

---

Öffne das Custom GPT **Folkwang_Timers** in ChatGPT (Link oben). Wenn du ein **eigenes** GPT auf Basis dieses Workshops anlegst, nutze die Dateien aus [`Dataset_Timers/`](../Dataset_Timers/) als Wissen.

---

## Was der GPT braucht

Der GPT erzeugt Code für den **Arduino Nano** mit den Workshop-Komponenten. Sinnvolle Anfragen enthalten:

**1. Was ist der Eingang?**  
Zeit (RTC), Abstand (VL53L0X), Neigung/Bewegung (MPU6050), ggf. Kombination.

**2. Was ist der Ausgang?**  
OLED-Text, NeoPixel, Servo.

**3. Wie hängen sie zusammen?**  
Schwellen, Zeitfenster, „je näher desto …“, „nur nach 18 Uhr …“.

---

## Prompt-Vorlage

```
Ich möchte [EINGANG] mit [AUSGANG] verbinden.
[Optional: Verhalten genauer beschreiben — z. B. Zeitfenster, Schwellen in mm.]
```

---

## Beispiele — gut vs. weniger gut

| Weniger gut | Besser |
|---|---|
| „Mach was mit dem Sensor" | „Wenn der Abstand unter 200 mm fällt, sollen die NeoPixels voll aufleuchten." |
| „LED und Uhr" | „Das OLED zeigt die Uhrzeit; jede volle Minute blitzt der NeoPixel-Ring kurz auf." |
| „Servo und MPU" | „Der Servo folgt der X-Neigung des MPU6050 zwischen 0° und 180°." |

Die Anfrage muss nicht technisch sein — aber **Eingang**, **Ausgang** und **Zusammenhang** sollten klar sein.

---

## Weitere Prompt-Ideen

- **[Beispielprompts](./pathfinder_prompts.md)** — stufenweise Beispiele  
- **[Prompt-Patterns / Baukasten](./prompt_patterns_baukasten.md)** — Bausteine für eigene Prompts  

---

## Weiter

**→ [Schritt 2 · Code in PlatformIO einsetzen](./schritt_2_platformio.md)**
