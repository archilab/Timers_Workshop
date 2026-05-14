# ArduinoJson v7 — Vollständiger API-Kontext (Kern)

**PlatformIO:** `bblanchon/ArduinoJson@^7.2.2`  
**Include:** `#include <ArduinoJson.h>`

Quellen: [arduinojson.org v7](https://arduinojson.org/v7/), API-Referenz dort (JsonDocument, deserializeJson, serializeJson, …)

---

## 1. Dokumentmodell

- **`JsonDocument`** — einheitlicher Speicher für Objekt **oder** Array (v7; kein separates Static/Dynamic mehr).
- Unteraufteilung: **`JsonObject`**, **`JsonArray`**, **`JsonVariant`** (Referenzen in den Speicher des `JsonDocument`).

Konstruktion optional mit **Allocator** (PSRAM auf ESP32, Custom Allocator).

---

## 2. Deserialisieren

**Hauptfunktion:** `deserializeJson(JsonDocument& doc, Input, ...)`

**Input-Typen** (typisch): `const char*`, `String`, `Stream`, `std::string`, `JsonVariantConst`, …

**Rückgabe:** `DeserializationError` — `error.code()`, `error.c_str()`

**Optionen (Auswahl):**

- `DeserializationOption::NestingLimit(n)`
- `DeserializationOption::Filter(JsonDocument)` — nur Teilfelder parsen (Speicher sparen)
- `DeserializationOption::AllowUnicodeEscape`, etc. (siehe Doku)

---

## 3. Serialisieren

- `serializeJson(src, destination)` — kompakt  
- `serializeJsonPretty(src, destination)` — lesbar mit Zeilenumbrüchen

**Destination:** `Print&` (Serial, WiFiClient, …), `char*`, `String`, `std::string`, …

Verwandt: **MsgPack** — `serializeMsgPack`, `deserializeMsgPack` (binär, kompakter).

---

## 4. Auf Werte zugreifen

- `doc["key"]` / `doc["a"][0]` — wie JSON
- Typ-Tests: `doc["x"].is<T>()`, `as<T>()`
- Sichere Defaults: `doc["x"] | defaultValue`

**Kopieren in C-String:** vorsichtig mit Lebensdauer — `const char*` kann auf Puffer im Dokument zeigen.

---

## 5. Dokument bearbeiten

- `doc.clear()`, `doc.overflowed()` (Speicher reichte nicht)
- `doc.shrinkToFit()` — Speicher zurückgeben
- `doc.to<JsonObject>()` / `to<JsonArray>()` — Root-Typ wechseln

---

## 6. Größe / Speicher

- [ArduinoJson Assistant](https://arduinojson.org/v7/assistant/) — Kapazität schätzen
- `measureJson(doc)` — serialisierte Größe ohne Ausgabe

---

## 7. Filter-Deserialisierung

Große API-Antworten: nur benötigte Keys mit **Filter**-Objekt übernehmen (siehe Tutorial „Filtering“).

---

## 8. Rolle im Folkwang-Workshop

**PairLink** nutzt ArduinoJson **intern**. Anwendungscode soll primär **PairLink-Kanäle** nutzen. Diese Referenz dient korrekter **`lib_deps`**, Debugging und falls JSON dennoch explizit benötigt wird — **keine** frei erfundenen Payload-Schemas neben PairLink ohne Nutzeranforderung.

---

## 9. Kompilier-Flags (Auszug)

Siehe offizielle Doku: `ARDUINOJSON_*` Makros (Infinity, NaN, String-Duplikate, …).
