# ArduinoWebsockets (gilmaimon) — Vollständiger API-Kontext (Kern)

**PlatformIO:** `gilmaimon/ArduinoWebsockets@^0.5.4`  
**Include:** `#include <ArduinoWebsockets.h>` · oft `using namespace websockets;`

Quelle: [README / GitHub](https://github.com/gilmaimon/ArduinoWebsockets), Version **0.5.x** — ESP8266, **ESP32**, Teensy 4.1

---

## 1. Client (`WebsocketsClient`)

### Verbindung

- `bool connect(String url)` — z. B. `"ws://host:port/path"` oder `"wss://..."`  
- HTTPS/WSS auf ESP32: z. B. `setCACert`, `setInsecure` (siehe README-Beispiele)
- `void addHeader(const char* key, const char* value)` — zusätzliche HTTP-Header
- `close()` / automatisches Schließen bei Fehler

### Nachrichten senden

- `bool send(String data)` — Text
- Binär: APIs mit Raw-Daten (siehe README „Binary Data“: `msg.rawData()`, `c_str()`)

### Empfang & Schleife

- `void onMessage(WebsocketsMessageCallback)` — Lambda oder Funktionszeiger
- `void onEvent(WebsocketsEventCallback)` — Verbindungsereignisse
- **`bool poll()`** — **muss** regelmäßig in `loop()` aufgerufen werden (Empfang + Keepalive)

### Sonstiges (typisch)

- `ping()` / Ping-Pong (Events `GotPing`, `GotPong`)
- Timeout für Verbindung (ab Version 0.5.2 konfigurierbar, siehe Changelog)

---

## 2. Server (`WebsocketsServer`)

- `bool listen(uint16_t port)` / Port wählen
- `WebsocketsClient accept()` — eingehende Verbindung
- `bool available()` — ob Server bereit
- Client-Verarbeitung wie bei Client-API (`onMessage`, `poll` auf **Client-Instanz**)

---

## 3. Nachrichten-Typ `WebsocketsMessage`

- `String data()` — Text als Arduino-String (einfach, nicht ideal für großes Binär)
- `const char* c_str()` / `std::string rawData()` — Rohbytes bevorzugt für Binär

---

## 4. Events (`WebsocketsEvent`)

 u. a. `ConnectionOpened`, `ConnectionClosed`, `GotPing`, `GotPong` (siehe README-Beispiel)

---

## 5. SSL / WSS — ESP32

- `client.connect("wss://host:port/path")`
- Zertifikat: `setCACert(const char* pem)` oder `setInsecure()` für Tests
- Weitere Optionen: Fingerprints, Client-Zertifikate (README „SSL and WSS Support“)

---

## 6. Rolle im Folkwang-Workshop

**PairLink** kapselt WebSockets und JSON. **Normalfall:** kein eigener `WebsocketsClient` im Sketch — stattdessen `pairLink.update()` und Kanäle (`context-pairlink.md`).

Diese Datei verhindert, dass falsche Bibliotheken oder falsche `poll()`-Semantik verwechselt werden.

---

## 7. Abhängigkeit

Wird als **transitive** Abhängigkeit von PairLink über `template-platformio.ini` / Projekt-`platformio.ini` eingebunden; Version an `^0.5.4` pinnen wie im Workshop.
