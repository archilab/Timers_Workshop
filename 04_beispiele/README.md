# 04 · Beispiele

Drei vollständige Durchläufe des **Timers Workshop** — von der Anfrage an **Folkwang_Timers** bis zum laufenden Code auf dem **Arduino Nano**. Jedes Beispiel dokumentiert den Prozess; der Code liegt unter `code/` als PlatformIO-Projekt.

> **Hinweis:** `platformio.ini` und `src/main.cpp` müssen auf **Nano + neue `lib_deps`** angepasst werden, falls noch nicht erledigt — siehe [`NON_MARKDOWN_MIGRATION_CHECKLIST.md`](../NON_MARKDOWN_MIGRATION_CHECKLIST.md).

---

## Die drei Beispiele

| Beispiel | Inhalt | Fokus |
|---|---|---|
| [01 · Zeit auf dem OLED](./beispiel_01_geste_licht/README.md) | RTC + Anzeige (+ optional NeoPixel) | DS3231, SSD1306 |
| [02 · Bewegung steuert Servo](./beispiel_02_bewegung_servo/README.md) | MPU6050 → Servo | Neigung / Beschleunigung |
| [03 · Zeit und Nähe](./beispiel_03_swarm_installation/README.md) | RTC + VL53L0X + Aktor | **Lokal**, kein PairLink |

*(Ordnername `beispiel_01_geste_licht` ist historisch; Inhalt wird auf RTC/OLED umgestellt.)*

---

## Aufbau jedes Beispiels

- `README.md` — Idee, Prompt, Ergebnis  
- `prompt.md` — Text an das GPT  
- `code/` — PlatformIO-Projekt (`platformio.ini`, `src/main.cpp`)

Die `code/`-Ordner in VS Code öffnen, **`pio run`**, Upload auf den **Nano**.
