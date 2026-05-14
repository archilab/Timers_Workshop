# Pathfinder Workshop – Beispielprompts

**Kontext:** Diese Sammlung ergänzt [Schritt 1 · GPT-Anfrage formulieren](./schritt_1_gpt_anfrage.md) (dort: Vorlage und gut/schlecht-Beispiele). Wer lieber mit **Mustern** statt fertigen Sätzen arbeitet: [Prompt-Patterns / Baukasten](./prompt_patterns_baukasten.md). Vollständige Workshop-Durchläufe mit exaktem Prompt-Text stehen in [04 · Beispiele](../04_beispiele/README.md) je unter `prompt.md`.

---

Diese Sammlung enthält Beispielprompts für den Einsatz von KI im Pathfinder Workshop.  
Sie dienen als Ausgangspunkt für eigene Experimente und zeigen, wie durch Sprache interaktive Systeme entstehen.

Die Prompts sind in vier Stufen gegliedert:

- 🟢 Einstieg (direkt, klar, funktional)  
- 🟡 Kombination (mehrere Parameter koppeln)  
- 🟠 Interpretation (offene, gestalterische Prompts)  
- 🔴 Experiment (KI als Material)  

---

## 🟢 Einstieg – direkte Interaktionen

### Abstand → Farbe
```txt
Wenn sich meine Hand dem Sensor nähert, soll ein Farbverlauf von Blau zu Orange entstehen.
Der Wert soll direkt gemappt werden, ohne Glättung oder Verzögerung.
```

---

### Bewegung → Lichtimpuls
```txt
Wenn ich meine Hand schnell bewege, soll ein kurzer heller Lichtimpuls ausgelöst werden.
Langsame Bewegung soll kaum sichtbar sein.
```

---

### Distanz → Rotation
```txt
Die Entfernung meiner Hand soll eine Servo-Rotation von 0 bis 180 Grad steuern.
Die Bewegung soll direkt und ohne Verzögerung erfolgen.
```

---

### Umgebungslicht → Helligkeit (APDS9960)
```txt
Die Helligkeit im Raum soll über den APDS9960 gemessen werden und die NeoPixels proportional heller oder dunkler machen.
```

---

### Temperatur → Farbe (MPU6050)
```txt
Die On-Chip-Temperatur des MPU6050 soll die Farbe des LED-Streifens steuern: kälter bläulich, wärmer rötlicher — Werte sinnvoll auf 0.0–1.0 normieren.
```

---

## 🟡 Kombination – mehrere Dimensionen koppeln

### Distanz + Farbe + Rotation
```txt
Die Entfernung meiner Hand steuert die Rotation eines Servos von 0 bis 180 Grad.
Gleichzeitig erzeugt sie einen Farbverlauf von Blau zu Gelb.
Die Farbe soll sich unabhängig von der Rotation verändern.
```

---

### Rotation → Animation
```txt
Die Rotation meiner Hand soll eine Lichtanimation steuern.
Bei langsamer Rotation entsteht ein ruhiger Farbverlauf.
Bei schneller Rotation wird die Animation dynamisch und flackernd.
```

---

### Gesten → Ereignisse
```txt
Wenn ich meine Hand kurz nach oben bewege, soll ein farbiges Lichtsignal ausgelöst werden.
Wenn ich sie nach unten bewege, soll das Licht ausgehen.
```

---

## 🟠 Interpretation – KI als Co-Designer

### Sonnenaufgang
```txt
Die Rotation meiner Hand soll einen Sonnenaufgang simulieren.
Farben und Helligkeit sollen sich entsprechend verändern.
Zusätzlich soll eine langsame physische Bewegung entstehen.
```

---

### Emotionale Interaktion
```txt
Die Bewegung meiner Hand soll in eine emotionale Lichtreaktion übersetzt werden.
Ruhige Bewegungen erzeugen sanfte Farben, hektische Bewegungen intensive und schnelle Farbwechsel.
```

---

### Feuerwerk
```txt
Die Rotation meiner Hand soll ein farbiges Feuerwerk auslösen.
Die Geschwindigkeit bestimmt Intensität und Anzahl der Lichtimpulse.
Nutze möglichst viele Farben und dynamische Übergänge.
```

---

## 🔴 Experiment – KI als Material

### Unbestimmtes Verhalten
```txt
Die Bewegung meiner Hand soll ein System steuern, das nicht vollständig vorhersehbar ist.
Es soll zwischen verschiedenen Lichtmustern wechseln.
Die Übergänge dürfen überraschend sein.
```

---

### Fehler als Gestaltung
```txt
Die Interaktion soll bewusst ungenau sein.
Kleine Bewegungen können große Effekte auslösen.
Das System darf sich „falsch“ verhalten.
```

---

### Eigenständiges Verhalten
```txt
Das System soll auf meine Bewegung reagieren, aber auch ein eigenes Verhalten entwickeln.
Wenn keine Bewegung erkannt wird, soll es langsam in einen eigenen Rhythmus übergehen.
```

---

## 🧭 Hinweise zur Nutzung

- Prompts können direkt verwendet oder verändert werden  
- Kleine Änderungen führen oft zu völlig anderem Verhalten  
- Kombinationen mehrerer Prompts sind ausdrücklich erwünscht  

---

## 🧠 Wichtiger Gedanke

In diesem Workshop ist der Prompt selbst Teil des Entwurfsprozesses:

> Der Prompt beschreibt nicht nur das System – er gestaltet es.

---

## 🚀 Weiterarbeit

Eigene Prompts können ergänzt werden.  
Empfohlen wird:

- mit einfachen Beziehungen beginnen  
- dann mehrere Parameter kombinieren  
- anschließend offene, interpretative Beschreibungen testen  

---

**Ziel ist nicht Perfektion, sondern Exploration.**
