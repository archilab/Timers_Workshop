# I²C, RTC, OLED, and timing

## Bus discipline

- One **`Wire`** bus on **A4/A5**; all I²C devices share it.
- Initialize **`Wire.begin()`** before **`rtc.begin()`**, display, VL53L0X, or MPU6050.
- If a device fails `begin()`, print a clear **`Serial`** message with the expected address.

## DS3231 (RTClib) — mandatory in generated projects

- Typical types: **`RTC_DS3231 rtc;`**
- **`rtc.begin()`** — returns false if module missing.
- **Never** call **`rtc.adjust(DateTime(F(__DATE__), F(__TIME__)))`** automatically on every boot — that overwrites user-set time.
- Read: **`DateTime now = rtc.now();`** — use **`now.hour()`**, **`now.minute()`**, **`now.unixtime()`**, etc.

### SETTIME via Serial (Master Prompt)

At **`Serial.begin(115200)`**, parse lines from the Serial Monitor:

```
SETTIME YYYY-MM-DD HH:MM:SS
```

Example: **`SETTIME 2026-06-22 15:30:00`**

On valid input: **`rtc.adjust(DateTime(year, month, day, hour, minute, second))`** and confirm on Serial (and optionally OLED).

Document in **RTC Setup** and **First Startup Procedure** that the user sets time once with **SETTIME**, not by re-flashing with a new compile time.

## SSD1306 (128×64 I²C)

- Use **`Adafruit_SSD1306`** with **`SSD1306_SWITCHCAPVCC`**, address **0x3C** (or **0x3D**).
- After writes: **`display.display()`**.
- Keep redraws modest (e.g. a few Hz) so the loop stays responsive for VL53L0X and MPU6050.

## VL53L0X

- **`VL53L0X sensor;`** → **`sensor.init()`** after **`Wire.begin()`**.
- Set a timeout (e.g. **`sensor.setTimeout(500)`**).
- Read range mm: **`sensor.readRangeSingleMillimeters()`** — treat out-of-range / timeout per library docs.

## Non-blocking loop

- Avoid long **`delay()`** in **`loop()`** when polling sensors or refreshing the display; prefer **`millis()`** spacing.
