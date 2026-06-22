# Eigenen Custom GPT erstellen

**Öffentlicher Workshop-GPT:** [Folkwang_Timers in ChatGPT öffnen](https://chatgpt.com/g/g-6a05cf109af481918718831969e45905-folkwang-timers)

Der **Master Prompt** dieses Workshops ist öffentlich — damit man einen eigenen Custom GPT nach dem **Timers Workshop**-Modell anlegen kann.

**Quellen:** [`system_prompt.txt`](./system_prompt.txt) · [`Arduino_Nano_MasterPrompt.md`](../Dataset_Timers/Arduino_Nano_MasterPrompt.md) · Erläuterung: [`system_prompt_erklaert.md`](./system_prompt_erklaert.md)

---

## Voraussetzung

ChatGPT-Account mit **ChatGPT Plus** (kostenpflichtig). Nur Plus-Nutzer können Custom GPTs erstellen und veröffentlichen.

---

## Schritt 1 · GPT Editor öffnen

1. Auf [chatgpt.com](https://chatgpt.com) einloggen
2. Oben links auf den eigenen Namen klicken
3. **„Meine GPTs“** wählen
4. **„GPT erstellen“** klicken

---

## Schritt 2 · Master Prompt einfügen

Im GPT Editor: Tab **Konfigurieren** → Feld **Anweisungen**.

Den **gesamten** Inhalt von [`system_prompt.txt`](./system_prompt.txt) (oder [`Arduino_Nano_MasterPrompt.md`](../Dataset_Timers/Arduino_Nano_MasterPrompt.md)) einfügen.

Der Prompt definiert u. a.:

- Nur **Arduino Nano ATmega328P**
- Feste Pins (**NeoPixel D10**, **Servo D9**, I²C **A4/A5**)
- **11-teiliges** Antwortformat (Verdrahtung, Code, RTC, Didaktik)
- Pflicht-**RTC** mit **`SETTIME YYYY-MM-DD HH:MM:SS`**

---

## Schritt 3 · Knowledge hochladen

Unter **Wissen** die Dateien aus [`Dataset_Timers/`](../Dataset_Timers/) (oder [`Dataset_Timers.zip`](../Dataset_Timers.zip)) hochladen — mindestens:

- `template-platformio.ini`
- `context-library-index.md` und `context-library-*.md`
- `rules-meta-layer.md`, `rules-validation.md`

Upload-Reihenfolge: [`context-example-scripts.md`](../Dataset_Timers/context-example-scripts.md)

---

## Schritt 4 · Hardware anpassen (optional)

Wenn man **andere** Pins oder Boards nutzt, im Master Prompt den Abschnitt **FIXED HARDWARE CONFIGURATION** und **PLATFORMIO** anpassen — und die Knowledge-Dateien (`02-hardware-pins` im Agent-Bundle) entsprechend spiegeln.

**Timers Workshop Standard:**

| Bauteil | Pin / Bus |
|---------|-----------|
| NeoPixel-Ring | **D10** |
| Servo | **D9** |
| I²C-Sensoren/Display | **A4**, **A5** |

---

## Schritt 5 · Testen

Vor der Veröffentlichung mit Workshop-Prompts testen:

- Liefert der GPT **alle 11 Abschnitte** inkl. Verdrahtung?
- Enthalten **`platformio.ini`** und **`src/main.cpp`** **`nanoatmega328`**?
- Ist **SETTIME** in **RTC Setup** dokumentiert?
- Bleibt der GPT bei **Nano** (kein ESP32)?

---

## Schritt 6 · Veröffentlichen

GPT Editor oben rechts: **Speichern → Nur ich / Link teilen / Öffentlich**

---

## Was man verändern kann — und was nicht

| Änderung | Empfehlung |
|----------|------------|
| Hardware-Pins | Nur anpassen, wenn die echte Platine abweicht |
| `lib_deps` | Nur getestete Versionen aus `template-platformio.ini` |
| 11-teiliges Output-Format | Beibehalten — didaktischer Kern des Workshops |
| RTC **SETTIME** | Beibehalten — keine Auto-Überschreibung der Uhr |
| ESP32 / WiFi | Nicht hinzufügen (widerspricht dem Master Prompt) |
