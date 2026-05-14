# 02 · PairLink

PairLink ist das Herzstück der Netzwerkfunktion im Workshop. Es ermöglicht, zwei ESP32-Geräte miteinander zu verbinden — ohne jede Konfiguration, ohne Wissen über Netzwerktechnik.

---

## Die Grundidee

Ein Gerät misst etwas (Sensor). Ein anderes Gerät reagiert darauf (Aktor). PairLink sorgt dafür, dass der Wert des ersten Geräts über WLAN beim zweiten ankommt.

```
Gerät A                          Gerät B
─────────────────────────────────────────────
Sensor misst Wert   →→→  WLAN  →→→  Aktor reagiert
        0.0 – 1.0                    0.0 – 1.0
```

Das ist bidirektional: Beide Geräte können gleichzeitig senden und empfangen.

---

## [Das sensor.value Prinzip](./konzept.md)

Alle Werte fließen über einen einzigen Kanal: `sensor.value`. Warum das so einfach ist — und was dahintersteckt.

## [Netzwerk einrichten](./netzwerk.md)

Wie WLAN und WebSocket-Server für den Workshop konfiguriert sind.
