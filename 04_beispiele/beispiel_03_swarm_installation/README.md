# Beispiel 03 · Swarm-Installation

## Die Idee

Zwei physisch getrennte Boards reagieren aufeinander. Gerät A erkennt Gesten. Gerät B dreht einen Servo — ohne Kabel, nur über WLAN. Beide Boards beeinflussen sich gegenseitig: der kombinierte Wert beider Sensoren steuert beide Aktoren.

Das ist das Prinzip einer verteilten, reagierenden Installation.

---

## Schritt 1 · GPT-Anfrage

**→ [Prompt ansehen](./prompt.md)**

Der Prompt beschreibt zwei Geräte, die über das Netzwerk verbunden sind. Der GPT generiert für beide Boards denselben Code — denn im Swarm-Modus ist jedes Board gleichzeitig Sender und Empfänger.

---

## Schritt 2 · Code in PlatformIO

```
code/
├── platformio.ini
└── src/
    └── main.cpp
```

Derselbe Code wird auf **beide** ESP32-Boards gespielt. Jedes Board erkennt Gesten, sendet seinen Wert, empfängt den Wert des anderen, und steuert damit seinen eigenen Servo.

In VSCode: **Datei → Ordner öffnen → `code/`**

---

## Schritt 3 · Upload und Pairing

1. Code auf **beide** Boards hochladen (nacheinander, gleicher Code)
2. Beide Boards mit Strom versorgen
3. Auf **beiden gleichzeitig** den Pairing-Button (GPIO 0) drücken
4. Status-LEDs leuchten dauerhaft → Verbindung steht

**Testen:**
- Hand über Gerät A → Servo auf Gerät B bewegt sich
- Hand über Gerät B → Servo auf Gerät A bewegt sich
- Beide gleichzeitig → kombinierter Wert → beide Servos reagieren

---

## Was im Hintergrund passiert

Jedes Board sendet seinen lokalen Gesturwert (`sensor.value`) über PairLink. Der empfangene Wert vom anderen Board wird mit dem eigenen Wert gemittelt. Das Ergebnis steuert den lokalen Servo. Kein Board hat eine "Führungsrolle" — das System ist symmetrisch.

```
Board A: lokal=0.8, empfangen=0.2 → kombiniert=0.5 → Servo 90°
Board B: lokal=0.2, empfangen=0.8 → kombiniert=0.5 → Servo 90°
```

---

→ Zurück zur [Beispiel-Übersicht](../README.md)  
→ Weiter zu: [Custom GPT](../../05_custom_gpt/README.md)
