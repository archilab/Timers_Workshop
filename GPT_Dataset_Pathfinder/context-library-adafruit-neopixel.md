# Adafruit NeoPixel Library — Vollständiger API-Kontext

**PlatformIO:** `adafruit/Adafruit_NeoPixel@^1.12.5`  
**Include:** `#include <Adafruit_NeoPixel.h>`

Quelle: [Adafruit_NeoPixel.h](https://github.com/adafruit/Adafruit_NeoPixel/blob/master/Adafruit_NeoPixel.h), [Überguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use), [Doxygen](https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html)

---

## Workshop-Festlegung (Referenz)

- 6 Pixel, **Pin D6** (digital 6), **RGBW**, `NEO_GRBW + NEO_KHZ800`

---

## 1. Konstruktor & Typ

```cpp
Adafruit_NeoPixel(uint16_t n, int16_t pin = 6, neoPixelType type = NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel(void);  // spät konfigurierbar
```

**Farbreihenfolge + Takt** (`neoPixelType`):

- **RGB (3 Byte/Pixel):** `NEO_RGB`, `NEO_RBG`, `NEO_GRB`, `NEO_GBR`, `NEO_BRG`, `NEO_BGR`
- **RGBW (4 Byte/Pixel):** `NEO_WRGB`, `NEO_WRBG`, …, `NEO_RGBW`, …, **`NEO_GRBW`**, … (alle Permutationen im Header)
- **Takt:** `NEO_KHZ800` (typisch), `NEO_KHZ400` (ältere v1-Pixel)

Kombination: z. B. `NEO_GRBW + NEO_KHZ800`.

---

## 2. Lebenszyklus & Pin

| Methode | Beschreibung |
|--------|----------------|
| `bool begin(void)` | Initialisierung |
| `void show(void)` | Pixeldaten ausgeben (**Pflicht** nach Farbänderungen) |
| `void setPin(int16_t p)` | Datenpin ändern |
| `int16_t getPin(void) const` | |
| `void updateLength(uint16_t n)` | Pixelanzahl ändern |
| `void updateType(neoPixelType t)` | LED-Typ ändern |
| `uint16_t numPixels(void) const` | Anzahl LEDs |

---

## 3. Farben & Pixel

| Methode | Beschreibung |
|--------|----------------|
| `void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b)` | RGB; bei RGBW: W oft 0 |
| `void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint8_t w)` | RGBW |
| `void setPixelColor(uint16_t n, uint32_t c)` | gepackt |
| `uint32_t getPixelColor(uint16_t n) const` | auslesen |
| `void fill(uint32_t c = 0, uint16_t first = 0, uint16_t count = 0)` | Bereich füllen |
| `void clear(void)` | löschen (äquivalent zu fill 0) |

---

## 4. Helligkeit & global

| Methode | Beschreibung |
|--------|----------------|
| `void setBrightness(uint8_t)` | 0–255, **global** (intern +1 gespeichert) |
| `uint8_t getBrightness(void) const` | |

---

## 5. Hilfsfunktionen (statisch)

| Methode | Beschreibung |
|--------|----------------|
| `static uint32_t Color(uint8_t r, uint8_t g, uint8_t b)` | Packen RGB |
| `static uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w)` | Packen RGBW (`W` im höchsten Byte) |
| `static uint32_t ColorHSV(uint16_t hue, uint8_t sat = 255, uint8_t val = 255)` | HSV → gepackt |
| `static uint8_t sine8(uint8_t x)` | 0–255 periodisch (Lookup) |
| `static uint8_t gamma8(uint8_t x)` | Gamma 2.6 |
| `static uint32_t gamma32(uint32_t x)` | Gamma auf 32-Bit-Farbe |
| `static neoPixelType str2order(const char *v)` | String → Typ |

---

## 6. Animation

| Methode | Beschreibung |
|--------|----------------|
| `void rainbow(uint16_t first_hue = 0, int8_t reps = 1, uint8_t saturation = 255, uint8_t brightness = 255, bool gammify = true)` | Regenbogen über Kette |

---

## 7. Performance / Raw-Puffer

| Methode | Beschreibung |
|--------|----------------|
| `uint8_t *getPixels(void) const` | Direktzugriff auf Rohpuffer (**Vorsicht**, Format = Datenstrom-Reihenfolge) |
| `bool canShow(void)` | ob `show()` sofort senden kann oder ~300 µs warten muss (Latch) |

---

## 8. ESP32

Ab IDF 5.0+ ggf. `espInit()` (extern „C“) — von der Library gekapselt. Keine langen `delay()` direkt vor kritischem Timing.

---

## 9. Strom & Hardware

Mehrere Ampere bei vielen Pixeln → externes 5V, gemeinsame GND mit MCU; 470Ω–500Ω Serienwiderstand auf Datenleitung oft empfohlen (Hardware-Guide).
