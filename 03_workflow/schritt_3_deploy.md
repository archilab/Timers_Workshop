# Schritt 3 · Auf den Controller übertragen

---

## Upload starten

1. ESP32 per USB anschließen
2. In VSCode unten in der **blauen Statusleiste** auf den **Pfeil → (Upload)** klicken

Das Terminal zeigt den Fortschritt. Ein erfolgreicher Upload endet mit:
```
SUCCESS
============================================================
```

---

## Serial Monitor öffnen

Nach dem Upload gibt der ESP32 Statusmeldungen aus. Diese sind hilfreich, um zu verstehen, was gerade passiert:

1. Unten in der Statusleiste auf das **Stecker-Symbol** klicken (Serial Monitor)
2. Baudrate muss `115200` sein

Typische Meldungen:
```
Connecting to WiFi...
Connected. IP: 192.168.1.xx
PairLink ready.
```

---

## Pairing zwischen zwei Boards

Wenn der Sketch PairLink verwendet und zwei Boards miteinander kommunizieren sollen:

1. Beide Boards mit Strom versorgen (USB)
2. Beide verbinden sich automatisch mit dem WLAN
3. Gleichzeitig auf beiden den **Pairing-Button (GPIO 0)** drücken
4. Die Status-LED leuchtet dauerhaft → Verbindung aufgebaut

---

## Häufige Probleme

| Problem | Mögliche Ursache | Lösung |
|---|---|---|
| `No device found` | USB nicht erkannt | Treiber prüfen, Kabel tauschen |
| Upload läuft, aber `FAILED` | Falscher Port oder Board | Port in `platformio.ini` manuell setzen |
| Bibliothek fehlt | Kein Internet | Einmalig mit Internet verbinden |
| Status-LED blinkt dauerhaft | WLAN nicht erreichbar | WLAN-Name und Passwort im Code prüfen |
| Sensor reagiert nicht | Verkabelung | SDA/SCL-Pins prüfen; Aufbau mit [Steckplatine & Schaltplan](../01_komponenten/README.md#verkabelung) abgleichen |

---

## Was jetzt?

Der Code läuft. Wenn das Verhalten nicht genau das ist, was du dir vorgestellt hast — kein Problem. Geh zurück zu Schritt 1 und beschreibe dem GPT, was anders sein soll. Die Iteration ist Teil des Prozesses.

→ Zurück zu: [Schritt 1 · GPT-Anfrage](./schritt_1_gpt_anfrage.md)  
→ Weiter zu: [Beispiele](../04_beispiele/README.md)
