# 03 · Zeitfenster und Nähe

Installation mit **lokaler** Logik: nur wenn die **Uhrzeit** in einem Tagesfenster liegt **und** der **VL53L0X** eine Nahdistanz misst, fährt der **Servo** aus — sonst zurück auf 0°. Kein zweites Board, **kein PairLink**.

## Hardware

- Nano, DS3231, VL53L0X, Servo **D9**, I²C **A4/A5**.

## Ablauf

1. `prompt.md` an **Folkwang_Timers**.  
2. `code/` bauen und testen.
