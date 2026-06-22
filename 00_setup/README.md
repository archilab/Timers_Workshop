# Setup — Schritt für Schritt (Einsteiger)

Bevor man Code auf den **Arduino Nano** überträgt, richtet man einmalig den Computer ein. Das dauert etwa **15–20 Minuten** und ist nur **einmal** nötig.

Der **Timers Workshop** arbeitet **lokal** auf einem **Arduino Nano (ATmega328P, 5V)** — **kein ESP32**, **kein WLAN**, **kein PairLink**.

---

## Workshop-Hardware (Überblick)

| Bauteil | Anbindung | Hinweis |
|---------|-----------|---------|
| **Arduino Nano** | USB zum PC | Klassischer **ATmega328P**, 5V |
| **DS3231** (RTC) | I²C **A4** (SDA), **A5** (SCL) | Adresse **0x68** |
| **VL53L0X** (Abstand) | I²C A4/A5 | Adresse **0x29**, Werte in **mm** |
| **SSD1306** (OLED 128×64) | I²C A4/A5 | Adresse **0x3C** (manchmal **0x3D**) |
| **MPU6050** (Bewegung) | I²C A4/A5 | Adresse **0x69** — **AD0 → VCC** |
| **NeoPixel-Ring** (12× WS2812B RGB) | Daten **D6** | `NEO_GRB + NEO_KHZ800` |
| **Servo** | Signal **D9** | Arduino-**Servo**-Library (nicht ESP32Servo) |

**Gemeinsame Masse:** Alle Module mit **GND** am Nano verbinden. **5V**-Versorgung je nach Modul (viele Breakouts: **VCC** an **5V**).

Details und Bilder: [01 Komponenten](../01_komponenten/README.md) · Steckplatine im [Projekt-README](../README.md).

---

## Was man am Ende bereit hat

| Teil | Wofür |
|------|--------|
| **Git** | Wird von **PlatformIO** gebraucht, um Bibliotheken von GitHub zu laden. |
| **Visual Studio Code (VS Code)** | Der Editor für den Code. |
| **PlatformIO** | Erweiterung in VS Code: baut das Projekt, lädt Bibliotheken, lädt den Code auf den **Arduino Nano**. |
| **USB-Treiber** | Damit Windows/macOS den Nano am USB-Kabel erkennt (CH340, FT232, CP2102 …). |

---

## Schritt 1 — Git installieren

**Git** ist die Basis-Software für Versionskontrolle. **PlatformIO braucht Git**, um viele Bibliotheken automatisch von GitHub zu beziehen — ohne Git schlagen Builds oft fehl.

1. Öffnen: [https://git-scm.com/install/](https://git-scm.com/install/)
2. Das eigene Betriebssystem (Windows, macOS, Linux) wählen und der Anleitung folgen. Alle vorgeschlagenen Optionen während des Installationsprozesses bestätigen.

---

## Schritt 2 — Visual Studio Code installieren

VS Code ist der **Editor**, in dem man Code bearbeitet und Uploads startet.

1. Öffnen: [https://code.visualstudio.com](https://code.visualstudio.com)
2. Installer für das eigene Betriebssystem herunterladen und installieren.

**Optional:** Wer die Oberfläche **weniger überladen** möchte, kann [VS Code vereinfachen](vscode-oberflaeche.md) — Darstellungsdesign, Aktivitätsleiste und untere Leiste Schritt für Schritt (mit Screenshots).

---

## Schritt 3 — PlatformIO in VS Code installieren

**PlatformIO** ist eine **Erweiterung** in VS Code. Sie kümmert sich um Bibliotheken, Compiler und den **Upload zum Arduino Nano**.

1. **VS Code** öffnen.
2. Links auf das Symbol **Erweiterungen** klicken (vier Quadrate).
3. Oben suchen: `PlatformIO IDE`.
4. Auf **Installieren** klicken.
5. Wenn VS Code danach einen **Neustart** verlangt: zustimmen.

Nach der Installation sieht man links das **PlatformIO-Symbol** (Kopf einer Ameise).

**Hinweis:** Beim **ersten** Projekt lädt PlatformIO Werkzeuge nach — das kann **2–3 Minuten** dauern, das ist normal.

### Board-Einstellung (wichtig)

Workshop-Projekte nutzen **immer**:

```ini
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
monitor_speed = 115200
```

**Nicht** `esp32dev`, **nicht** `arduino_uno` — nur **Nano ATmega328**. Vorlage: [`Dataset_Timers/template-platformio.ini`](../Dataset_Timers/template-platformio.ini).

---

## Schritt 4 — USB-Treiber installieren

Der Arduino Nano spricht über einen **USB-zu-UART-Chip** mit dem PC. Dafür braucht das Betriebssystem einen **Treiber**.

Workshop-Nanos nutzen häufig **CH340G** oder **FT232**; manche Clones **CP2102**. Den Treiber installieren, den der Geräte-Manager oder die Board-Beschreibung nennt (z. B. [WCH CH341/CH340](http://www.wch-ic.com/downloads/CH341SER_ZIP.html) oder [Silicon Labs CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)).

### macOS (Ventura und neuer)

Falls der Treiber blockiert wird:

1. **Systemeinstellungen** → **Datenschutz & Sicherheit**
2. Unten den Hinweis zum Treiber suchen → **Trotzdem erlauben**

### Windows

Wenn kein **COM-Port** erscheint: **Geräte-Manager** öffnen — unter **Anschlüsse (COM & LPT)** sollte ein Eintrag wie *CH340*, *Silicon Labs* oder *USB-SERIAL* sichtbar sein. Sonst Treiber erneut prüfen oder USB-Kabel wechseln (Datenkabel, nicht nur Ladekabel).

### Kurztest

1. Arduino Nano per **USB** anschließen.
2. In VS Code unten in der **blauen Leiste** sollte ein Port erscheinen, z. B. `COM3` (Windows) oder `/dev/cu.usbserial-…` (macOS).  
   Wenn ja: Treiber passt.

---

## Schritt 5 — Erstes Projekt öffnen und testen

So prüft man, ob **Software und Nano** zusammenspielen, bevor man mit dem vollen Workshop-Set testet.

### Minimale Verkabelung für Beispiel 01

Das erste Testprojekt ([`beispiel_01`](../04_beispiele/beispiel_01_geste_licht/README.md)) braucht auf dem Breadboard mindestens:

| Modul | Anschluss am Nano |
|-------|-------------------|
| **DS3231** | **VCC**, **GND**, **SDA → A4**, **SCL → A5** |
| **SSD1306 OLED** | **VCC**, **GND**, **SDA → A4**, **SCL → A5** (parallel zum RTC am selben I²C-Bus) |

**VL53L0X**, **MPU6050**, **NeoPixel-Ring** und **Servo** sind für diesen ersten Upload **nicht** nötig — sie kommen in den anderen Beispielen bzw. im eigenen GPT-Projekt dazu.

**MPU6050-Hinweis für später:** **AD0** mit **VCC** verbinden, damit der Sensor **0x69** nutzt und der **DS3231** **0x68** behalten kann.

### Projektordner öffnen

1. Den **Workshop-Ordner** auf den Rechner legen (z. B. per `git clone` oder **Code → Download ZIP** auf GitHub). Im Ordner navigieren zu:  
   `04_beispiele/beispiel_01_geste_licht/code/`
2. In VS Code: **Datei → Ordner öffnen** → genau diesen Ordner **`code`** wählen (der enthält die `platformio.ini`).
3. In `platformio.ini` prüfen: **`board = nanoatmega328`**, **`platform = atmelavr`**.
4. PlatformIO erkennt das Projekt und lädt beim ersten Mal die Bibliotheken (**RTClib**, **SSD1306**, **GFX** …) — wieder **einige Minuten** warten.

### Code auf den Arduino Nano laden (Upload)

1. Arduino Nano per USB angeschlossen lassen.
2. Unten in der blauen Leiste auf den **Pfeil nach rechts** (**Upload**) klicken — oder in der PlatformIO-Seitenleiste **Upload**.
3. Im **Terminal** unten sieht man den Ablauf. Erfolg endet oft mit **`SUCCESS`**.

**Erwartung:** Das OLED zeigt die **Uhrzeit** der DS3231 (ggf. zuerst per Serial Monitor prüfen, ob `DS3231 missing` erscheint).

### Serial Monitor (Ausgabe lesen)

1. Unten auf das **Stecker-Symbol** (**Serial Monitor**) klicken.
2. **Baudrate:** `115200` wählen (steht in der Workshop-`platformio.ini` als `monitor_speed = 115200`).
3. Es erscheinen Textausgaben vom Nano (z. B. Fehlermeldungen zu RTC oder OLED).

---

## Häufige Probleme

| Symptom | Mögliche Ursache | Was tun |
|--------|------------------|--------|
| Build meldet fehlende Bibliotheken | **Git** nicht installiert oder nicht im PATH | Schritt 1 wiederholen, VS Code neu starten |
| Build sucht **ESP32**-Toolchain | Falsche `platformio.ini` | `board = nanoatmega328`, `platform = atmelavr` setzen |
| Kein Projektordner | Workshop-Dateien fehlen | Repository klonen oder ZIP von GitHub entpacken |
| Kein USB-Port sichtbar | Treiber oder Kabel | Schritt 4, anderes USB-Kabel (Daten) |
| `No device found on port` | Falscher Port oder Nano nicht verbunden | Port in PlatformIO manuell wählen |
| Upload schlägt fehl | Falscher Port | Unten in der Leiste einen anderen COM-Port wählen |
| Serial Monitor leer / Kauderwelsch | Falsche Baudrate | **115200** wählen |
| `DS3231 missing` | RTC nicht verkabelt oder I²C falsch | **A4/A5**, **VCC**, **GND** prüfen |
| OLED bleibt schwarz | Falsche I²C-Adresse oder Verdrahtung | **0x3C** vs. **0x3D** am Modul prüfen; Bus **A4/A5** |
| `MPU6050` nicht gefunden (spätere Sketches) | **AD0** nicht auf VCC | MPU auf **0x69** verdrahten |
| NeoPixel flackert / Nano reset | Zu wenig Strom | Ring separat mit 5V versorgen, **`setBrightness()`** senken |
| Sehr langer erster Build | Normal | Internet anlassen, 2–5 Minuten warten |

---

## Workshop-`lib_deps` (Referenz)

Alle GPT-Projekte und Beispiele nutzen dieselbe Bibliothekenmenge (Auszug):

```
adafruit/RTClib@^2.1.4
pololu/VL53L0X@^1.3.1
adafruit/Adafruit SSD1306@^2.5.15
adafruit/Adafruit GFX Library@^1.11.11
adafruit/Adafruit MPU6050@^2.2.4
adafruit/Adafruit Unified Sensor@^1.1.15
adafruit/Adafruit NeoPixel@^1.12.5
```

Vollständige Datei: [`Dataset_Timers/template-platformio.ini`](../Dataset_Timers/template-platformio.ini).

---

## Weiter im Workshop

- **VS Code Oberfläche (optional):** [Oberfläche vereinfachen](vscode-oberflaeche.md)
- **Komponenten & Verkabelung:** [01 Komponenten](../01_komponenten/README.md) und [Projekt-README](../README.md)
- **I²C & Zeit:** [02 Zeit und I²C-Bus](../02_pairlink/README.md)
- **Workflow (GPT → PlatformIO → Upload):** [03 Workflow](../03_workflow/README.md)
- **Beispiele:** Ordner [`04_beispiele/`](../04_beispiele/README.md)

Wenn **Upload** und **Serial Monitor** mit dem Nano funktionieren, ist das Setup **fertig**.
