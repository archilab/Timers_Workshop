# Prompt · Beispiel 03

## Der verwendete Prompt

> Ich möchte zwei ESP32-Boards über PairLink verbinden. Beide haben einen Gestensensor und einen Servo. Wenn Board A eine Geste erkennt, soll der Servo auf Board B reagieren — und umgekehrt. Beide Boards sollen sich gegenseitig beeinflussen.

---

## Was der GPT daraus macht

- Sensor: APDS9960 (Geste) — auf beiden Boards
- Aktor: Servo (GPIO 12) — auf beiden Boards
- Modus: PairLink (bidirektional, Swarm)
- Verhalten: lokaler Wert + empfangener Wert werden gemittelt → Servo
- Derselbe Code auf beide Boards

---

## Warum derselbe Code für beide Boards?

Das Swarm-Prinzip macht jeden Knoten gleichwertig. Kein Board ist "Master" oder "Slave" — jedes sendet und empfängt gleichermaßen. Der GPT generiert daher einen einzigen Sketch, der auf beliebig vielen Boards laufen kann.

---

## Variationen

| Prompt-Änderung | Erwartetes Ergebnis |
|---|---|
| „...der empfangene Wert soll stärker gewichtet sein als der lokale" | GPT ändert die Mittelwert-Formel |
| „...statt Servo sollen LEDs auf Board B reagieren" | GPT trennt Sensor- und Aktor-Code |
| „...drei Boards statt zwei" | Prinzip bleibt gleich, Code läuft unverändert auf drei Boards |
