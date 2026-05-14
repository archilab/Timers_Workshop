# I²C, RTC, OLED, and timing

## Bus discipline

- One **`Wire`** bus on **A4/A5**; all I²C devices share it.
- Initialize **`Wire.begin()`** before **`rtc.begin()`**, display, VL53L0X, or MPU6050.
- If a device fails `begin()`, print a clear **`Serial`** message with the expected address.

## DS3231 (RTClib)

- Typical types: **`RTC_DS3231 rtc;`**
- **`rtc.begin()`** — returns false if module missing.
- Set time once in lab: **`rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));`** only when appropriate, or document user setting via compile time.
- Read: **`DateTime now = rtc.now();`** — use **`now.hour()`**, **`now.minute()`**, **`now.unixtime()`**, etc.

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
