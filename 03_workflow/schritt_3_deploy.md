# Schritt 3 · Auf den Controller übertragen

---

## Upload starten

1. **Arduino Nano** per USB anschließen  
2. In VS Code unten in der **blauen Statusleiste** auf den **Pfeil → (Upload)** klicken  

Das Terminal zeigt den Fortschritt. Ein erfolgreicher Upload endet oft mit **`SUCCESS`**.

---

## Serial Monitor öffnen

1. Unten auf das **Stecker-Symbol** (Serial Monitor) klicken  
2. **Baudrate:** `115200` (wie in der Workshop-`platformio.ini`)

Typische Meldungen: Sensor gefunden / nicht gefunden, Debug-Ausgaben aus deinem Sketch.

---

## Häufige Probleme

| Problem | Mögliche Ursache | Lösung |
|---|---|---|
| `No device found` | USB / Treiber | Treiber (z. B. CH340) prüfen, Kabel tauschen |
| Upload `FAILED` | Falscher Port | Anderen COM-Port wählen |
| OLED bleibt schwarz | Adresse 0x3C vs 0x3D | Im Code anpassen |
| MPU nicht gefunden | AD0 nicht auf VCC | Verkabelung für **0x69** prüfen |

---

## Weiter im Workshop

- **Beispiele:** [`04_beispiele/`](../04_beispiele/README.md)  
- **Komponenten:** [`01_komponenten/`](../01_komponenten/README.md)
