# 05 · Custom GPT

Der Custom GPT "FOLWANG-PairLink-starter" ist kein allgemeiner Assistent — er ist ein spezialisiertes Werkzeug. Er kennt genau die Hardware des Workshops, die erlaubten Bibliotheken, die Pin-Belegung und das PairLink-Protokoll. Alles andere lehnt er ab.

---

## Links

**→ [GPT öffnen](https://chatgpt.com/g/g-69b6eda5e8888191b2000af26055b60b-folwang-pairlink-starter)**

**→ [Custom GPT Dataset herunterladen](../GPT_Dataset_Pathfinder.zip)** — System Prompt, Beispiel-Sketches und Konfigurationsdateien als ZIP

**→ [context-example-scripts.md](../GPT_Dataset_Pathfinder/context-example-scripts.md)** — Priorität von Regeln vs. Beispiel-Skripten (`sample-*.cpp`, `template-platformio.ini`) und empfohlene Upload-Reihenfolge ins GPT-Wissen

---

## Inhalt dieses Abschnitts

| Datei | Inhalt |
|---|---|
| [system_prompt.txt](./system_prompt.txt) | Der vollständige, unveränderte System Prompt |
| [system_prompt_erklaert.md](./system_prompt_erklaert.md) | Jeder Abschnitt erklärt: Was steht da, und warum? |
| [eigenen_gpt_erstellen.md](./eigenen_gpt_erstellen.md) | Schritt-für-Schritt: So baust du deinen eigenen Custom GPT |

---

## Was ein Custom GPT ist

Ein Custom GPT ist ein ChatGPT-Modell, das durch einen System Prompt auf eine bestimmte Aufgabe spezialisiert wurde. Der System Prompt ist ein unsichtbarer Anfangstext, der dem Modell mitteilt:

- Welche Rolle es hat
- Was es tun darf und was nicht
- Welches Wissen es voraussetzen soll
- Wie es seine Ausgaben formatieren soll

Der GPT dieses Workshops ist auf diese Regeln beschränkt, damit er zuverlässig funktionierenden, anfängerfreundlichen Code erzeugt — und nicht in allgemeine Programmierdiskussionen abweicht.
