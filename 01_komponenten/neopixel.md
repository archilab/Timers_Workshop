# NeoPixel-Ring · WS2812B (12 LEDs, 5V)

![Verdrahtung NeoPixel (Beispiel)](./bilder/neopixel_wiring.png)

Im Workshop sitzt ein **NeoPixel LED Ring 5V RGB WS2812B** mit **12** einzeln ansteuerbaren LEDs. Jede LED kann RGB-Farben darstellen und unabhängig von den anderen leuchten. Datenleitung: **D6** (wie in den Regeln `02-hardware-pins.md`).

---

## Was er kann

- Helligkeit stufenlos regeln (0 = aus, 255 = maximale Helligkeit pro Kanal)
- Farben über **RGB** (kein separater Weißkanal wie bei RGBW-Streifen)
- Animationen, Kreisläufe und Muster über die **Ring**-Geometrie (Pixel 0–11)

## Wie er im Prompt beschrieben wird

> „…die LEDs am Ring leuchten heller, wenn…"
> „…der Ring zeigt die Intensität der Bewegung…"
> „…12 Pixel reagieren auf den Sensorwert…"

## Anschluss

- Datenleitung → **D6** (digital Pin 6)
- **5V** und **GND** zum Ring (bei voller Helligkeit mehr Strom → stabiles 5V, gemeinsame Masse mit dem Nano)
- Library-Typ: **`NEO_GRB + NEO_KHZ800`** (typisch für WS2812B)

Bibliothek: `Adafruit NeoPixel`

---

## Referenzen & Dokumentation

| Ressource | Link |
|---|---|
| WS2812B LED Datenblatt | [cdn-shop.adafruit.com · PDF](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf) |
| Adafruit NeoPixel Library (GitHub) | [github.com/adafruit/Adafruit_NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) |
| Adafruit NeoPixel Library (PlatformIO) | [registry.platformio.org](https://registry.platformio.org/libraries/adafruit/Adafruit%20NeoPixel) |
| Adafruit NeoPixel Überguide | [learn.adafruit.com/adafruit-neopixel-uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide) |

Optional (anderes Bauteil, nicht Workshop-Standard): SK6812 RGBW — siehe Datenblatt und `NEO_GRBW` in der Library-Doku.
