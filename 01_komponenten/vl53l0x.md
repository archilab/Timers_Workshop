# VL53L0X (Time-of-Flight)

Der **VL53L0X** misst die **Entfernung** zu einem vorderen Objekt in **Millimetern** per Infrarot-Laufzeitmessung. Er hängt am **I²C-Bus** (Standardadresse **0x29**).

## Wofür du es nutzt

- Nähe steuert **Helligkeit** (NeoPixel) oder **Servo-Winkel**  
- Schwellen („wenn näher als 200 mm …“)  
- Kombination mit **Uhrzeit** (z. B. nur tagsüber reagieren)

## Tipps

- Sehr weite oder absorbierende Oberflächen können die Messung erschweren.  
- Nicht in einer **langen** `delay()`-Schleife blockieren — lieber mit `millis()` takten.
