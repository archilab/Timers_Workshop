# Eigenen Custom GPT erstellen

**Öffentlicher Workshop-GPT:** [Folkwang_Timers in ChatGPT öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)

Der System Prompt dieses Workshops ist öffentlich — damit du ihn als Vorlage für deinen eigenen Custom GPT verwenden kannst. Hier ist der Prozess Schritt für Schritt.

---

## Voraussetzung

Du brauchst einen ChatGPT-Account mit Zugang zu **ChatGPT Plus** (kostenpflichtig). Nur Plus-Nutzer können Custom GPTs erstellen und veröffentlichen.

---

## Schritt 1 · GPT Editor öffnen

1. Auf [chatgpt.com](https://chatgpt.com) einloggen
2. Oben links auf deinen Namen klicken
3. **"Meine GPTs"** wählen
4. **"GPT erstellen"** klicken

---

## Schritt 2 · System Prompt eingeben

Im GPT Editor gibt es zwei Tabs: **Erstellen** (geführter Chat) und **Konfigurieren** (direkter Zugriff).

Wechsle zu **Konfigurieren**.

Dort findest du das Feld **"Anweisungen"** — das ist der System Prompt. Hier kannst du:

- Den Prompt aus [`system_prompt.txt`](./system_prompt.txt) einfügen und anpassen
- Eigene Regeln hinzufügen oder bestehende ändern

---

## Schritt 3 · Anpassen an deine Hardware

Wenn du andere Komponenten, andere Pins oder andere Bibliotheken verwendest, musst du diese Abschnitte anpassen:

**Hardware ändern:**
```
HARDWARE RULES
DEIN_SENSOR → GPIO X
DEIN_AKTOR  → GPIO Y
```

**Bibliotheken ändern:**
```
LIBRARIES (STRICT)
#include <DeineBibliothek.h>

LIB_DEPS (STRICT)
autor/DeineBibliothek@^version
```

**Kernprinzip anpassen:**
Das `LOCAL: Sensor → Actor` / `PAIRED: ...` Prinzip kann auf andere Protokolle übertragen werden — z.B. MQTT, OSC, oder BLE.

---

## Schritt 4 · Testen

Bevor du den GPT veröffentlichst, teste ihn mit den gleichen Prompts, die du in echten Workshops verwenden würdest:

- Einfache Anfrage: funktioniert der Code sofort?
- Grenzfall: reagiert der GPT sinnvoll wenn die Anfrage unklar ist?
- Unerlaubte Anfrage: bleibt er in seiner Rolle wenn jemand etwas anderes verlangt?

---

## Schritt 5 · Veröffentlichen

Im GPT Editor oben rechts: **Speichern → Nur ich / Link teilen / Öffentlich**

Mit einem geteilten Link können andere sofort mit deinem GPT arbeiten — ohne ihn installieren zu müssen.

---

## Was du verändern kannst — und was nicht

| Änderung | Empfehlung |
|---|---|
| Hardware-Pins | Unbedingt anpassen wenn du andere Boards verwendest |
| Bibliotheken | Nur durch stabile, getestete Versionen ersetzen |
| Kernprinzip (0.0–1.0) | Beibehalten — das macht den GPT verlässlich |
| NEVER-Regeln | Eher ergänzen als entfernen |
| Output-Format | Anpassen an dein Tool-Setup (z.B. Arduino IDE statt PlatformIO) |
