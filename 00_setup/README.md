# Setup — Schritt für Schritt (Einsteiger)

Bevor du Code auf den **Arduino Nano** überträgst, richtest du einmalig deinen Computer ein. Das dauert etwa **15–20 Minuten** und musst du nur einmal machen.

---

## Was du am Ende haben wirst

| Teil | Wofür |
|------|--------|
| **Git** | Wird von **PlatformIO** gebraucht, um Bibliotheken von GitHub zu laden. |
| **Visual Studio Code (VS Code)** | Der Editor für deinen Code. |
| **PlatformIO** | Erweiterung in VS Code: baut das Projekt, lädt Bibliotheken, lädt den Code auf den Arduino Nano. |
| **USB-Treiber** | Damit Windows/macOS den Arduino Nano am USB-Kabel erkennt. |

---

## Schritt 1 — Git installieren

**Git** ist die Basis-Software für Versionskontrolle. **PlatformIO braucht Git**, um viele Bibliotheken automatisch von GitHub zu beziehen — ohne Git schlagen Builds oft fehl.

1. Öffne: [https://git-scm.com/install/](https://git-scm.com/install/)
2. Wähle dein Betriebssystem (Windows, macOS, Linux) und folge der Anleitung. Bestätige alle vorgeschlagenen Optionen während dem Installationsprozess.

---

## Schritt 2 — Visual Studio Code installieren

VS Code ist der **Editor**, in dem du Code bearbeitest und Uploads startest.

1. Öffne: [https://code.visualstudio.com](https://code.visualstudio.com)
2. Installer für dein Betriebssystem herunterladen und installieren.

**Optional:** Wer die Oberfläche **weniger überladen** möchte, kann [VS Code vereinfachen](vscode-oberflaeche.md) — Darstellungsdesign, Aktivitätsleiste und untere Leiste Schritt für Schritt (mit Screenshots).

---

## Schritt 3 — PlatformIO in VS Code installieren

**PlatformIO** ist eine **Erweiterung** in VS Code. Sie kümmert sich um Bibliotheken, Compiler und den **Upload zum Arduino Nano**.

1. **VS Code** öffnen.
2. Links auf das Symbol **Erweiterungen** klicken (vier Quadrate).
3. Oben suchen: `PlatformIO IDE`.
4. Auf **Installieren** klicken.
5. Wenn VS Code danach einen **Neustart** verlangt: zustimmen.

Nach der Installation siehst du links das **PlatformIO-Symbol** (Kopf einer Ameise).

**Hinweis:** Beim **ersten** Projekt lädt PlatformIO Werkzeuge nach — das kann **2–3 Minuten** dauern, das ist normal.

---

## Schritt 4 — USB-Treiber installieren

Der Arduino Nano spricht über einen **USB-zu-UART-Chip** mit dem PC. Dafür braucht das Betriebssystem einen **Treiber**.

Workshop-Nanos nutzen häufig **CH340G** oder **FT232**; manche Clones **CP2102**. Installiere den Treiber, den dein Geräte-Manager oder die Board-Beschreibung nennt (z. B. [WCH CH341/CH340](http://www.wch-ic.com/downloads/CH341SER_ZIP.html) oder [Silicon Labs CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)).

### macOS (Ventura und neuer)

Falls der Treiber blockiert wird:

1. **Systemeinstellungen** → **Datenschutz & Sicherheit**
2. Unten den Hinweis zum Treiber suchen → **Trotzdem erlauben**

### Windows

Wenn kein **COM-Port** erscheint: **Geräte-Manager** öffnen — unter **Anschlüsse (COM & LPT)** sollte ein Eintrag wie *Silicon Labs* oder *USB-SERIAL* sichtbar sein. Sonst Treiber erneut prüfen oder USB-Kabel wechseln (Datenkabel, nicht nur Ladekabel).

### Kurztest

1. Arduino Nano per **USB** anschließen.
2. In VS Code unten in der **blauen Leiste** sollte ein Port erscheinen, z. B. `COM3` (Windows) oder `/dev/cu.usbserial-…` (macOS).  
   Wenn ja: Treiber passt.

---

## Schritt 5 — Erstes Projekt öffnen und testen

So prüfst du, ob **alles zusammenspielt**, bevor du mit dem Workshop startest.

### Projektordner öffnen

1. Lege den **Workshop-Ordner** auf deinen Rechner (z. B. per `git clone` oder **Code → Download ZIP** auf GitHub). Navigiere darin zu:  
   `04_beispiele/beispiel_01_geste_licht/code/`
2. In VS Code: **Datei → Ordner öffnen** → genau diesen Ordner **`code`** wählen (der enthält die `platformio.ini`).
3. PlatformIO erkennt das Projekt und lädt beim ersten Mal die Bibliotheken — wieder **einige Minuten** warten.

### Code auf den Arduino Nano laden (Upload)

1. Arduino Nano per USB angeschlossen lassen.
2. Unten in der blauen Leiste auf den **Pfeil nach rechts** (**Upload**) klicken — oder in der PlatformIO-Seitenleiste **Upload**.
3. Im **Terminal** unten siehst du den Ablauf. Erfolg endet oft mit **`SUCCESS`**.

### Serial Monitor (Ausgabe lesen)

1. Unten auf das **Stecker-Symbol** (**Serial Monitor**) klicken.
2. **Baudrate:** `115200` wählen (steht auch in der Workshop-`platformio.ini`).
3. Du siehst Textausgaben vom Arduino Nano (z. B. Sensor- oder Zeitstatus).

---

## Häufige Probleme

| Symptom | Mögliche Ursache | Was tun |
|--------|------------------|--------|
| Build meldet fehlende Bibliotheken | **Git** nicht installiert oder nicht im PATH | Schritt 1 wiederholen, VS Code neu starten |
| Kein Projektordner | Workshop-Dateien fehlen | Repository klonen oder ZIP von GitHub entpacken |
| Kein USB-Port sichtbar | Treiber oder Kabel | Schritt 4, anderes USB-Kabel (Daten) |
| `No device found on port` | Falscher Port oder Arduino Nano nicht verbunden | Port in PlatformIO manuell wählen |
| Upload schlägt fehl | Falscher Port | Unten in der Leiste anderen COM-Port wählen |
| Sehr langer erster Build | Normal | Internet anlassen, 2–5 Minuten warten |

---

## Weiter im Workshop

- **VS Code Oberfläche (optional):** [Oberfläche vereinfachen](vscode-oberflaeche.md)
- **Komponenten & Verkabelung:** [01 Komponenten](../01_komponenten/README.md) und [Projekt-README](../README.md)
- **Beispiele:** Ordner `04_beispiele/`

Wenn **Upload** und **Serial Monitor** funktionieren, ist dein Setup **fertig**.
