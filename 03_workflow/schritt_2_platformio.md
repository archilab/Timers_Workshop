# Schritt 2 · Code in PlatformIO einsetzen

Der GPT hat zwei Dateien geliefert: `main.cpp` und `platformio.ini`. Beide müssen in ein PlatformIO-Projekt eingefügt werden.

---

## Projektstruktur

Ein gültiges PlatformIO-Projekt sieht so aus:

```
mein-projekt/
├── platformio.ini      ← Konfigurationsdatei (vom GPT)
└── src/
    └── main.cpp        ← Der Code (vom GPT)
```

Die Ordnerstruktur ist fest — PlatformIO erwartet die `main.cpp` immer im `src/`-Unterordner.

---

## Option A · Beispielprojekt als Vorlage

Am einfachsten: einen der fertigen Code-Ordner aus `04_beispiele/` kopieren und den Inhalt der Dateien durch den GPT-Output ersetzen.

1. Z.B. `04_beispiele/beispiel_01_geste_licht/code/` kopieren
2. In VSCode öffnen: **Datei → Ordner öffnen**
3. `src/main.cpp` öffnen → Inhalt komplett markieren → GPT-Code einfügen
4. `platformio.ini` öffnen → Inhalt komplett markieren → GPT-Konfiguration einfügen
5. Speichern

---

## Option B · Neues Projekt anlegen

1. In VSCode das PlatformIO-Symbol (Ameisenkopf) anklicken
2. **New Project** → Name eingeben
3. Board: `Espressif ESP32 Dev Module` (suche nach `esp32dev`)
4. Framework: `Arduino`
5. Location: beliebiger Ordner → **Finish**
6. Die vom GPT generierten Dateien ersetzen `src/main.cpp` und `platformio.ini`

---

## Was nach dem Einfügen passiert

PlatformIO liest die `platformio.ini` und lädt beim ersten Build automatisch alle dort angegebenen Bibliotheken herunter. Das dauert einmalig 1–2 Minuten.

Man sieht das im Terminal-Bereich:
```
Installing dependencies...
Library installed: PairLink
Library installed: Adafruit NeoPixel
...
```

Wenn alle Bibliotheken geladen sind, kann der Upload starten.

---

→ Weiter: [Schritt 3 · Auf den Controller übertragen](./schritt_3_deploy.md)
