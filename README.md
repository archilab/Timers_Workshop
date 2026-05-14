# Timers Workshop  
Folkwang Universität der Künste  

## Worum es geht

Interaktive Systeme entstehen heute nicht mehr primär durch Programmieren, sondern durch **Beschreibung, Iteration und Dialog mit KI**.

Dieser Workshop untersucht einen zentralen Paradigmenwechsel:  
Large Language Models fungieren nicht länger nur als Werkzeuge, sondern als **aktive Co-Designer und Übersetzer zwischen Idee und technischer Umsetzung**. Sie transformieren Sprache direkt in funktionale Systeme – vom Sensor bis zur physischen Interaktion.

Am Beispiel des **Arduino Nano** mit **Echtzeituhr (DS3231)**, **Distanzsensor (VL53L0X)** und **OLED-Display** wird sichtbar, wie sich diese Entwicklung konkret materialisiert:  
Teilnehmende beschreiben eine künstlerische oder performative Idee — und das Custom-GPT-System **„Folkwang_Timers“** generiert daraus lauffähigen Code, der auf die Workshop-Hardware übertragen werden kann.

Der Fokus liegt dabei nicht auf klassischer Programmierlogik, sondern auf:

- der Präzision von Beschreibung  
  *(Prompting als neue Entwurfspraxis)*
- der Iteration im Dialog mit KI
- dem Verständnis von KI-generierten Systemen als gestaltbare, aber nicht vollständig deterministische Prozesse

Der Workshop positioniert sich damit im aktuellen KI-Diskurs, in dem sich Softwareentwicklung zunehmend von einem handwerklichen zu einem **kuratorischen und konzeptionellen Prozess** verschiebt.

Gleichzeitig wird sichtbar, dass diese Systeme neue Kompetenzen erfordern:  
Während einfache Anwendungen bereits zuverlässig generiert werden können, stoßen komplexere Systeme schnell an Grenzen und erfordern gezielte Steuerung, Kontext und kritische Bewertung.

Der Workshop versteht sich daher nicht als reine Einführung in Tools, sondern als **Experimentierfeld für eine neue Form von Gestaltung**:  
**Interaktive Systeme entstehen durch Sprache, Vorstellung und kritische Reflexion – nicht mehr nur durch Code.**

---

## Niedrigschwelliger Einstieg

Trotz dieser theoretischen Einordnung ist der Workshop bewusst als **offener Einstieg** angelegt.  
Es sind keine Programmierkenntnisse erforderlich.

Der Zugang erfolgt über:

- eine Idee
- eine sprachliche Beschreibung
- einen KI-gestützten Entwicklungsprozess
- die direkte Übertragung auf physische Hardware

So wird sichtbar, wie KI technische Barrieren senken kann, ohne die gestalterische Komplexität zu reduzieren.

---

## Relevanz

KI verändert aktuell grundlegend, wie interaktive Systeme entworfen und entwickelt werden.

Statt Code Zeile für Zeile selbst zu schreiben, wird Entwicklung zunehmend zu einem Prozess aus:

- Beschreiben
- Kuratieren
- Testen
- Korrigieren
- Reflektieren

Sprache wird damit zu einem neuen Interface für Technologie.  
Zugleich verschiebt sich die Rolle der Gestaltenden: weg von der reinen Implementierung, hin zur Formulierung von Verhalten, zur Steuerung von Prozessen und zur kritischen Bewertung von Ergebnissen.

---

## Was passiert im Workshop

Im Workshop entstehen **zeit- und messwertbasierte** interaktive Systeme mit:

- **Arduino Nano** Mikrocontrollern  
- **DS3231** Echtzeituhr, **VL53L0X** Abstand, **SSD1306** OLED (128×64, I²C)  
- **MPU6050** Bewegung / Lage / Temperatur  
- **NeoPixel**-Streifen und **Servo**  
- KI-generiertem Code  
- dem Custom GPT **„Folkwang_Timers“**

Beispielhafte Anwendungen:

- Uhrzeit und Datum auf dem OLED; Abläufe nach Uhrzeit steuern  
- Abstand steuert Licht, Bewegung oder Servo  
- Neigung oder Temperatur kombinieren sich mit Zeit und Anzeige

---

## Grundprinzip

Technisch lässt sich jede Installation als Kette fassen: **Sensor** liefert Daten, dazwischen liegt **Transformation** (Mapping, Logik, Schwellen), **Aktoren** setzen das sichtbar oder beweglich um — genau so strukturieren auch sinnvolle Prompts die Anfrage an den GPT.

![Prompt-Logik: Input (Sensor), Transformation (Mapping / Logik), Output (Aktoren)](./prompt_logic_diagram.svg)

Der Ablauf im Workshop ist einfach:

1. Eine Idee oder Interaktion beschreiben  
2. Mit dem GPT-System daraus Code erzeugen  
3. Den Code auf den **Arduino Nano** übertragen  
4. Testen, verändern, verbessern  
5. Verhalten, Ergebnis und Logik reflektieren 

---


## Kontext: KI, Gestaltung und Physical Computing

Der Workshop berührt mehrere aktuelle Entwicklungslinien:

### Von „No-Code“ zu „Post-Code“

Der Workshop soll nicht einfach suggerieren, dass Programmierung verschwindet.  
Treffender ist: **Code verschwindet nicht, sondern rückt in eine nachgelagerte Ebene**.

Der Schwerpunkt verlagert sich vom manuellen Schreiben von Code zur Beschreibung von Verhalten, zur Auswahl geeigneter Lösungen und zur kritischen Revision maschinell erzeugter Vorschläge.

### KI als Interface und KI als Material

Im Workshop kann KI auf zwei Weisen verstanden werden:

- **KI als Interface**  
  Sprache wird zum Interface für technische Systeme.

- **KI als Material**  
  Verhalten, Unschärfen, Missverständnisse und Fehler der KI können selbst Teil einer gestalterischen Auseinandersetzung werden.

Gerade im künstlerischen Kontext ist beides relevant.

### Embodied AI / Physical Computing

Ein besonders spannender Aspekt liegt darin, dass KI den Bildschirm verlässt und in Objekte, Räume und körperliche Interaktion übergeht.

Der Workshop kann daher auch als Annäherung an eine Entwicklung verstanden werden, bei der aus sprachlicher Beschreibung unmittelbar physisch erfahrbare Systeme entstehen:  
**vom Prompt zur physischen Realität**.

---

## Kritische Perspektiven

Der Workshop will KI nicht nur als Erleichterung zeigen, sondern auch Fragen sichtbar machen, die im aktuellen Diskurs zentral sind:

- Wer versteht den generierten Code tatsächlich?
- Was bedeutet Autorschaft in einem KI-gestützten Entwicklungsprozess?
- Wo liegt die Grenze zwischen technischem Fehler und ästhetischem Verhalten?
- Welche neuen Kompetenzen entstehen, wenn Beschreibung wichtiger wird als Implementierung?

Diese Fragen sind kein Nebenthema, sondern Teil der gestalterischen Praxis.

---

## Custom GPT „Folkwang_Timers“

Custom GPTs von OpenAI liefern bessere Ergebnisse, wenn du als Nutzer eingeloggt bist.

**[→ Folkwang_Timers Custom GPT direkt öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)**

Zum **Nachbauen oder Erweitern** eines eigenen GPT: Trainingsdateien aus [`Dataset_Timers/`](./Dataset_Timers/) bzw. [`Dataset_Timers.zip`](./Dataset_Timers.zip) als Wissen einbinden — siehe [`05_custom_gpt/`](./05_custom_gpt/README.md) und [`NON_MARKDOWN_MIGRATION_CHECKLIST.md`](./NON_MARKDOWN_MIGRATION_CHECKLIST.md).

**[→ Custom GPT Dataset (ZIP)](./Dataset_Timers.zip)** — System Prompt + Trainingsdateien *(ZIP bei Änderungen neu packen; siehe [`NON_MARKDOWN_MIGRATION_CHECKLIST.md`](./NON_MARKDOWN_MIGRATION_CHECKLIST.md).)*

---

## Der Workflow in drei Schritten

```
1. GPT-Anfrage stellen   →   Idee in Sprache beschreiben
2. Code in PlatformIO    →   Einfügen, fertig
3. Auf Controller laden  →   Upload, testen
```

Kein manuelles Programmieren. Kein Verständnis von Syntax notwendig.

---

## Inhalt

| Abschnitt | Inhalt |
|---|---|
| [00 Setup](./00_setup/README.md) | Git, VS Code, PlatformIO, Treiber — die Installation notwendiger Komponenten Schritt für Schritt erklärt |
| [01 Komponenten](./01_komponenten/README.md) | Alle elektronischen Bauteile im Detail erklärt |
| [02 Zeit und I²C-Bus](./02_pairlink/README.md) | Echtzeit, I²C-Bus, Adressen — **kein** WLAN/PairLink mehr |
| [03 Workflow](./03_workflow/README.md) | Der Workflow im Detail · [Beispielprompts](./03_workflow/pathfinder_prompts.md) · [Prompt-Baukasten](./03_workflow/prompt_patterns_baukasten.md) |
| [04 Beispiele](./04_beispiele/README.md) | Drei vollständige Beispiele mit Workflow-Durchläufen |
| [05 Custom GPT](./05_custom_gpt/README.md) | Wie das Custom GPT funktioniert — und wie man sein eigenes bauen/anpassen kann |

---

## Im Workshop verwendete Hardware

- **Arduino Nano** (ATmega328P, klassisch 5V)  
- **DS3231** Modul (Echtzeituhr, I²C)  
- **VL53L0X** Time-of-Flight (Distanz mm, I²C)  
- **SSD1306** OLED 128×64 (I²C)  
- **MPU6050** (Bewegung, Lage, On-Chip-Temperatur; im Workshop-Adressschema **0x69**)  
- **NeoPixel** RGBW LED-Streifen (6 Pixel, Datenpin **D6**)  
- **Servomotor** (0–180°, Signal **D9**)

Hinweis: **MPU6050 AD0** mit **VCC** verbinden, damit der Sensor **0x69** nutzt und der **DS3231** **0x68** frei bleibt.

### Steckplatine und Schaltplan

Der **Aufbau auf der Steckplatine** und der **Schaltplan** zeigen dasselbe Workshop-Set: alle Bauteile und ihre Verbindungen. Details zu einzelnen Komponenten stehen in [01 Komponenten](./01_komponenten/README.md).

![Steckplatine — Aufbau mit allen Workshop-Komponenten](./pathfinder_Steckplatine.svg)

![Schaltplan — Verschaltung aller Workshop-Komponenten](./pathfinder_Steckplatine_circuit.svg)

Alle Komponenten sind vorkonfiguriert. Pins und Bibliotheken sind fest im GPT eingebaut — es muss nichts konfiguriert werden.

---

*Folkwang Universität der Künste · Timers Workshop*
