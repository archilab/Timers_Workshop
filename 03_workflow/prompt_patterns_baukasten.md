# Pathfinder Workshop – Prompt Patterns / Baukasten

**Kontext:** Systematische Muster zum Entwerfen eigener Prompts. Ergänzt [Schritt 1 · GPT-Anfrage formulieren](./schritt_1_gpt_anfrage.md) und die fertigen Formulierungen in [Beispielprompts](./pathfinder_prompts.md).

---

Dieser Baukasten hilft dabei, eigene Prompts systematisch zu entwickeln.  
Er zeigt grundlegende Muster, mit denen sich interaktive Systeme beschreiben lassen.

---

## 🧩 Grundstruktur eines Prompts

Ein funktionierender Prompt besteht meist aus drei Teilen:

1. **Input (Was wird gemessen?)**  
2. **Transformation (Wie wird es übersetzt?)**  
3. **Output (Was passiert?)**

### Template
```txt
Wenn [Input],
dann soll [Transformation],
und daraus entsteht [Output].
```

---

## 🟢 Pattern 1 – Mapping

Direkte Übersetzung eines Wertes.

```txt
Die Entfernung meiner Hand soll direkt einen Farbverlauf von Blau zu Rot steuern.
```

👉 Prinzip: 1:1 Beziehung

---

## 🟢 Pattern 2 – Threshold (Schwelle)

Ein Ereignis wird ausgelöst, wenn ein Wert überschritten wird.

```txt
Wenn ich meine Hand schnell bewege, soll ein Lichtimpuls ausgelöst werden.
```

👉 Prinzip: Zustand → Ereignis

---

## 🟢 Pattern 3 – Range Transformation

Ein Wertebereich wird auf einen anderen übertragen.

```txt
Die Entfernung meiner Hand soll eine Rotation von 0 bis 180 Grad steuern.
```

👉 Prinzip: Skalierung

---

## 🟡 Pattern 4 – Multi-Mapping

Ein Input steuert mehrere Outputs gleichzeitig.

```txt
Die Entfernung meiner Hand steuert sowohl die Farbe als auch die Rotation.
```

👉 Prinzip: Parallelität

---

## 🟡 Pattern 5 – Parameter Trennung

Mehrere Inputs steuern unterschiedliche Outputs.

```txt
Die Entfernung steuert die Rotation.
Die Geschwindigkeit steuert die Farbe.
```

👉 Prinzip: Differenzierung

---

## 🟠 Pattern 6 – Metapher

Beschreibung über Bilder oder Situationen.

```txt
Die Bewegung meiner Hand soll einen Sonnenaufgang simulieren.
```

👉 Prinzip: Interpretation durch KI

---

## 🟠 Pattern 7 – Verhalten

System wird als dynamisch beschrieben.

```txt
Das System soll ruhig reagieren, aber bei schneller Bewegung lebendig werden.
```

👉 Prinzip: qualitative Zustände

---

## 🔴 Pattern 8 – Unbestimmtheit

System ist bewusst nicht exakt definiert.

```txt
Das System soll überraschend reagieren und zwischen Mustern wechseln.
```

👉 Prinzip: Offenheit

---

## 🔴 Pattern 9 – Fehler als Gestaltung

Instabilität wird gewollt eingesetzt.

```txt
Das System darf sich ungenau und übertrieben verhalten.
```

👉 Prinzip: Kontrollverlust

---

## 🔴 Pattern 10 – Autonomie

System entwickelt eigenes Verhalten.

```txt
Wenn keine Bewegung erkannt wird, soll das System ein eigenes Muster entwickeln.
```

👉 Prinzip: Eigenständigkeit

---

## 🧪 Kombinationsregeln

Gute Prompts entstehen oft durch Kombination:

- Mapping + Threshold  
- Metapher + Verhalten  
- Multi-Mapping + Autonomie  

---

## 🧠 Wichtiger Gedanke

> Ein Prompt ist kein Befehl, sondern eine Gestaltung von Verhalten.

---

## 🚀 Übung

Baue einen eigenen Prompt aus diesen Bausteinen:

```txt
Input: __________
Transformation: __________
Output: __________
Zusatz (optional): __________
```

---

**Ziel: eigene interaktive Systeme durch Sprache entwerfen.**
