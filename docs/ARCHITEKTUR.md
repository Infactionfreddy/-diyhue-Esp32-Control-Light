# Architektur

[← Zurück zur README](../README.md)

## Überblick

Das Projekt ist ein kleines ESP32-Firmware-Beispiel. Es besteht aus einer Demo-Anwendung (`main.c`) und einer Hilfsbibliothek (`HueControl.c/.h`), die Befehle als HTTP-`PUT`-Requests an die Hue-API eines Gateways (DiyHue) sendet.

## Komponenten

| Komponente | Datei | Aufgabe |
|---|---|---|
| Demo / Hauptprogramm | `main.c` | WLAN-Verbindung in `setup()`, Demo-Schleife in `loop()`; definiert `ip` und `user_name` |
| Hue-Bibliothek | `HueControl.c`, `HueControl.h` | Funktionen `light`, `group`, `brightness`, `color` |
| CI | `.github/workflows/msbuild.yml` | MSBuild-Workflow (nicht passend zum Projekt, Annahme) |

## Datenfluss

```mermaid
sequenceDiagram
    participant L as loop() in main.c
    participant H as HueControl
    participant G as Hue-/DiyHue-Gateway
    L->>H: light(1,true) / brightness(...) / color(...)
    H->>H: URL und JSON-Body bauen
    H->>G: HTTP PUT /api/<user>/lights/<id>/state
    G-->>H: HTTP-Status + JSON-Antwort
    H-->>L: Ausgabe über Serial
```

## Ablauf

```mermaid
flowchart TD
    A[setup: Serial + WiFi.begin] --> B{Verbunden?}
    B -- nein --> B
    B -- ja --> C[loop]
    C --> D[Lampe/Gruppe an/aus]
    D --> E[Helligkeit]
    E --> F[Farbe]
    F --> C
```

## Request-Aufbau

- Lampen: `http://<ip>/api/<user_name>/lights/<id>/state`
- Gruppen: `http://<ip>/api/<user_name>/groups/<id>/action`
- Body: `{"on":true|false}`, `{"bri":N}` oder `{"xy":[x,y]}`
- Header `Content-Type: text/plain`
