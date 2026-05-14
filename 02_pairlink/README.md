# 02 · Zeit und I²C-Bus

Im **Timers Workshop** arbeiten alle Sensoren und das OLED-Display am **gemeinsamen I²C-Bus** des **Arduino Nano** (**A4 = SDA**, **A5 = SCL**). Die **DS3231** liefert verlässliche **Uhrzeit und Datum** — sie eignet sich als Taktgeber für zeitbasierte Installationen und für die Anzeige auf dem **SSD1306**.

> **Hinweis:** Es gibt **kein WLAN** und **kein PairLink** mehr. Alle Beispiele laufen **lokal auf einem Nano**.

---

## Die Grundidee

**Zeit** (RTC) und **Messwerte** (Abstand, Neigung, Temperatur) werden im `loop()` gelesen, verarbeitet und auf **OLED**, **NeoPixel** oder **Servo** ausgegeben. Die genauen Pins und Adressen stehen in [`claude_pathfinder/.claude/rules/02-hardware-pins.md`](../claude_pathfinder/.claude/rules/02-hardware-pins.md).

---

## [Uhrzeit und Anzeige](./konzept.md)

Wie RTC und OLED zusammenarbeiten — und warum der **MPU6050** im Workshop an **0x69** hängt.

## [I²C-Bus und Adressen](./netzwerk.md)

Geräte am Bus, Spannungspegel und typische Fehler — **ohne** Netzwerkkonfiguration.
