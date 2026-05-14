# Cline — Timers Workshop / Folkwang

Cline bundle mirroring **`cline_pathfinder/`**: **`CLINE.md`**, **`.cline/rules/*.md`**, **`.context/`** (same role as `claude_pathfinder/`).

Custom GPT name: **Folkwang_Timers**. Hardware: **Arduino Nano**, DS3231, VL53L0X, SSD1306, MPU6050 @0x69, NeoPixel, Servo.

## Sync

When **`claude_pathfinder/`** or **`GPT_Dataset_Pathfinder/`** changes, re-copy **`.context/`** and **`.cline/rules/`** from the canonical Claude bundle (or from the dataset), then adjust Cline-only text if needed.
