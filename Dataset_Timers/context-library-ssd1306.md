# Adafruit SSD1306 + GFX — Vollständiger API-Kontext (128×64 I²C)

**PlatformIO:** `adafruit/Adafruit SSD1306`, `adafruit/Adafruit GFX Library`  
**Includes:** `#include <Wire.h>` · `#include <Adafruit_GFX.h>` · `#include <Adafruit_SSD1306.h>`  
**Timers Workshop:** typisch **128×64**, I²C **`0x3C`** oder **`0x3D`**, Reset oft **nicht** angeschlossen → **`rst_pin = -1`**.

Quellen: [Adafruit_SSD1306.h](https://github.com/adafruit/Adafruit_SSD1306/blob/master/Adafruit_SSD1306.h), [Adafruit_GFX.h](https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.h), [SSD1306 Learn Guide](https://learn.adafruit.com/monochrome-oled-breakouts)

---

## 1. Konstruktor `Adafruit_SSD1306` (I²C — empfohlen)

```cpp
Adafruit_SSD1306(uint8_t w, uint8_t h, TwoWire *twi = &Wire,
                 int8_t rst_pin = -1,
                 uint32_t clkDuring = 400000UL,
                 uint32_t clkAfter = 100000UL);
```

| Parameter | Bedeutung |
|-----------|-----------|
| `w`, `h` | Pixel (**128**, **64** im Workshop) |
| `twi` | I²C-Bus (Standard **`&Wire`**) |
| `rst_pin` | Hardware-Reset-GPIO oder **`-1`** wenn nicht verbunden |
| `clkDuring` / `clkAfter` | I²C-Takt (Hz) während/nach SSD1306-Transaktionen (optional Feintuning) |

Weitere Konstruktoren im Header: **SPI** (Hardware- oder Bitbang) — für den Workshop meist **nicht** nötig.

---

## 2. `begin`, Puffer, Ausgabe

| Methode | Beschreibung |
|--------|----------------|
| `bool begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = 0, bool reset = true, bool periphBegin = true)` | Initialisiert Controller; **`switchvcc`**: meist **`SSD1306_SWITCHCAPVCC`** (interne Ladepumpe aus 3,3-V-Logik) oder **`SSD1306_EXTERNALVCC`**. **`i2caddr`**: **0x3C** oder **0x3D** (7-Bit-Adresse). Rückgabe **`false`** bei Allokations-/Init-Fehler. |
| `void display(void)` | RAM-Puffer **auf das Panel** schieben — **nach** Zeichnen immer aufrufen. |
| `void clearDisplay(void)` | Puffer mit **0** füllen (Pixel aus). |
| `void invertDisplay(bool i)` | Display-Invert (alle Pixel). |
| `void dim(bool dim)` | Dimmen (reduzierte Ansteuerung / Kontrastpfad je nach Implementierung). |
| `bool getPixel(int16_t x, int16_t y)` | Pixelzustand im **Puffer** lesen. |
| `uint8_t *getBuffer(void)` | Rohzugriff auf den **1-Bit-Framebuffer** (zeilenweise nach SSD1306-Seiten — für Fortgeschrittene). |

---

## 3. Farben & `drawPixel`

Monochrom (1 Bit pro Pixel im Puffer); „Farbe“ ist logisch:

| Konstante | Wert | Bedeutung |
|-----------|------|-----------|
| `SSD1306_BLACK` | 0 | Pixel **aus** |
| `SSD1306_WHITE` | 1 | Pixel **an** |
| `SSD1306_INVERSE` | 2 | Pixel **invertieren** |

`virtual void drawPixel(int16_t x, int16_t y, uint16_t color)` — Basiszeichnung; Koordinaten **0 … width-1**, **0 … height-1**.

---

## 4. Hardware-Scrolling (SSD1306)

| Methode | Beschreibung |
|--------|----------------|
| `void startscrollright(uint8_t start, uint8_t stop)` | horizontale Seiten **start…stop** nach rechts |
| `void startscrollleft(uint8_t start, uint8_t stop)` | nach links |
| `void startscrolldiagright(uint8_t start, uint8_t stop)` | diagonal rechts |
| `void startscrolldiagleft(uint8_t start, uint8_t stop)` | diagonal links |
| `void stopscroll(void)` | Scroll stoppen |

**Hinweis:** Seitenadressen beziehen sich auf **8-Pixel-Zeilen** („pages“) des Controllers (0…7 bei 64 px Höhe).

---

## 5. Low-Level / Kontrast

| Methode | Beschreibung |
|--------|----------------|
| `void ssd1306_command(uint8_t c)` | Rohbefehl an den Controller (nur nutzen, wenn Datenblatt bekannt). |

Intern: **`contrast`** Feld; Kontraststeuerung läuft typischerweise über init-Sequenz — bei Bedarf in Beispielen der Library nachsehen.

---

## 6. `Adafruit_GFX` — Geometrie & Füllen

`Adafruit_SSD1306` erbt von **`Adafruit_GFX`**. Wichtige Zeichen-APIs (farbargument = `SSD1306_WHITE` / `BLACK` / `INVERSE`):

| Gruppe | Methoden |
|--------|----------|
| Linien / Rahmen | `drawLine`, `drawFastHLine`, `drawFastVLine`, `drawRect`, `fillRect`, `fillScreen` |
| Kreise / Ellipsen | `drawCircle`, `fillCircle`, `drawEllipse`, `fillEllipse`, `drawCircleHelper`, `fillCircleHelper` |
| Polygone | `drawTriangle`, `fillTriangle`, `drawRoundRect`, `fillRoundRect`, `drawRotatedRect`, `fillRotatedRect` |
| Bitmap | `drawBitmap` (mehrere Überladungen), `drawXBitmap`, `drawGrayscaleBitmap`, `drawRGBBitmap` (letztere eher für Farbdisplays; am OLED meist 1-bit-Bitmaps) |

**Transaktionen (optional):** `startWrite()` … `writePixel` / `writeFillRect` / … `endWrite()` — für weniger I²C-Overhead bei vielen Pixeln.

---

## 7. `Adafruit_GFX` — Text & `Print`

`Adafruit_GFX` erbt von **`Print`** → **`print` / `println`** funktionieren.

| Methode | Beschreibung |
|--------|----------------|
| `void setCursor(int16_t x, int16_t y)` | Startpunkt für Text |
| `void setTextSize(uint8_t s)` | gleichmäßige Skalierung |
| `void setTextSize(uint8_t sx, uint8_t sy)` | unabhängige Skalierung X/Y |
| `void setTextColor(uint16_t c)` | Vorder- = Hintergrundfarbe („ohne“ Hintergrund in Mono oft gleicher Wert) |
| `void setTextColor(uint16_t c, uint16_t bg)` | Vorder- und Hintergrundfarbe |
| `void setTextWrap(bool w)` | Zeilenumbruch am rechten Rand |
| `void setFont(const GFXfont *f = NULL)` | optional **GFXfont** (NULL = Standardfont) |
| `void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size)` | einzelnes Zeichen |
| `void drawChar(..., uint8_t size_x, uint8_t size_y)` | mit getrennter Skalierung |
| `void getTextBounds(...)` | Bounding-Box für Strings (`const char*`, `String`, `__FlashStringHelper`) |

Hilfs-Getter: **`width()`**, **`height()`**, **`getRotation()`**, **`getCursorX()`**, **`getCursorY()`**.

**Rotation:** `setRotation(uint8_t r)` mit **0…3** (90°-Schritte); beeinflusst `width`/`height` und Koordinatensystem.

---

## 8. Workshop-Hinweise

- **`display()`** nach jeder sichtbaren Änderung — sonst bleibt das Panel alt.  
- **AVR / Nano:** große `print`-Blöcke + hohe Textgröße = viel RAM; lieber kurze Strings oder `snprintf` in Puffer.  
- **Refresh-Rate:** bei **VL53L0X**-Polling nicht jedes Messergebnis voll neu zeichnen — z. B. alle **200–500 ms** UI aktualisieren.  
- **Doppelpuffer:** nicht vorhanden — `clearDisplay` + neu zeichnen vermeidet „Geister“-Reste.

---

## Abhängigkeiten

**Adafruit GFX Library**, **Adafruit BusIO**, **Wire**.
