# Adafruit SSD1306 128×64 OLED (Timers Workshop)

**PlatformIO:** `adafruit/Adafruit SSD1306`, `adafruit/Adafruit GFX Library`  
**Include:** `#include <Adafruit_GFX.h>` / `#include <Adafruit_SSD1306.h>`

## Wiring / config

- I²C address **0x3C** (many modules) or **0x3D** — use the one that matches the board silkscreen.
- **`SSD1306_SWITCHCAPVCC`** for `begin`.

## Typical pattern

```cpp
#define OLED_RESET -1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setup() {
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Timers");
  display.display();
}
```

## Notes

- Call **`display.display()`** after drawing.
- Limit refresh rate if combined with fast VL53L0X polling.
