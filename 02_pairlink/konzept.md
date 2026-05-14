# Das sensor.value Prinzip

## Alle Werte sind gleich

Egal ob der Sensor eine Geste erkennt, eine Neigung misst oder eine Erschütterung registriert — PairLink verwandelt jeden Sensorwert in eine einzige Zahl zwischen `0.0` und `1.0`.

```
Keine Geste   →  0.0
Geste erkannt →  1.0

Flach liegend →  0.5
Stark geneigt →  0.9 oder 0.1
```

Diese Normalisierung macht es möglich, jeden Sensor mit jedem Aktor zu kombinieren — ohne Anpassung.

---

## Zwei Modi

**Lokal (nicht gepaart):**
Der Sensor steuert direkt den Aktor auf demselben Board. Kein Netzwerk notwendig.

```
Sensor → [ESP32] → Aktor
```

**Gepaart (über WLAN):**
Der Wert wird über WLAN an das andere Gerät gesendet. Der Aktor des zweiten Geräts reagiert.

```
Sensor → [ESP32 A] → WLAN → [ESP32 B] → Aktor
```

Das Pairing wird durch einen einfachen Knopfdruck gestartet — keine Konfiguration notwendig.

---

## Der Kanalname

Alle generierten Sketches verwenden denselben Kanalnamen: `sensor.value`. Das ist die "Adresse", über die Werte ausgetauscht werden. Es gibt nur diesen einen Kanal — dadurch bleibt das System einfach und stabil.

---

## Warum das künstlerisch interessant ist

Das Prinzip ermöglicht physisch getrennte, aber reagierende Objekte. Zwei Installationsobjekte in verschiedenen Räumen können sich gegenseitig wahrnehmen und beeinflussen — ohne sichtbare Verbindung.
