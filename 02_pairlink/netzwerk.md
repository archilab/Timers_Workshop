# Netzwerk einrichten

PairLink kommuniziert über einen WebSocket-Server, der im Workshop-Netzwerk bereitgestellt wird.

---

## Netzwerkdaten

Die folgenden Werte sind bereits im Custom GPT hinterlegt und werden automatisch in jeden generierten Code eingetragen:

```
WLAN-Name:   nextreality_net
Passwort:    hololens
Server:      ws://192.168.1.14:8080/ws
```

Du musst diese Daten nicht selbst eingeben oder kennen — sie erscheinen automatisch im generierten Code.

---

## Was der WebSocket-Server macht

Der Server ist der Vermittler zwischen den ESP32-Geräten. Er empfängt den Wert von Gerät A und leitet ihn an Gerät B weiter. Der Server läuft auf einem Computer im Workshop-Netzwerk und muss gestartet sein, damit das Pairing funktioniert.

---

## Status-LED

Auf den meisten ESP32 Boards gibt es eine Status-LED (GPIO 2), die anzeigt, ob das Gerät mit dem Server verbunden ist:

| LED-Zustand | Bedeutung |
|---|---|
| Leuchtet | Mit Server verbunden |
| Blinkt | Verbindung wird hergestellt |
| Aus | Kein Netzwerk |

---

## Pairing starten

1. Beide ESP32-Boards mit dem WLAN verbinden (automatisch beim Start)
2. Auf beiden Boards gleichzeitig den **Pairing-Button (GPIO 0) BOOT** drücken
3. Die Status-LEDs bestätigen das erfolgreiche Pairing

Nach dem Pairing reagiert ein Board auf das andere in Echtzeit.
