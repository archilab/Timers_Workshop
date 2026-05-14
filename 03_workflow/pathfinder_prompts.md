# Timers Workshop – Beispielprompts

Kurze **Beispielprompts** für **Folkwang_Timers** (Arduino Nano, DS3231, VL53L0X, SSD1306, MPU6050, NeoPixel, Servo). Formulierungen kann man an die eigene Idee anpassen.

---

## Einstieg

> „Zeige die aktuelle Uhrzeit der DS3231 groß auf dem OLED. Nutze die Workshop-Pins und `lib_deps`."

> „Der Abstand vom VL53L0X soll die Helligkeit des NeoPixel-Rings steuern — nah = alle LEDs heller (z. B. gleiches Grau R=G=B)."

---

## Zeit + Anzeige

> „Jede volle Minute soll die NeoPixel für eine Sekunde aufblitzen, sonst zeigt das OLED nur die Uhrzeit."

---

## Bewegung

> „Wenn man das Board neigt (MPU6050), soll der Servo zwischen 0° und 180° mitfahren. MPU an 0x69."

---

## Kombination

> „Zwischen 9 und 18 Uhr: wenn jemand näher als 250 mm kommt, Servo auf 120°, sonst 0°. Außerhalb des Zeitfensters immer 0°."

---

## OLED-Text

> „Zeige auf dem OLED zwei Zeilen: erste Zeile Uhrzeit, zweite Zeile Distanz in mm vom VL53L0X. Aktualisiere zweimal pro Sekunde."

---

## Hinweis

Kein WLAN, kein PairLink — alles **lokal** auf einem Nano. Strikte **`lib_deps`** aus dem Workshop beibehalten.
