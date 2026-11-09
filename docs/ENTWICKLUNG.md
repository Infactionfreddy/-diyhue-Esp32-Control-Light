# Entwicklung

[← Zurück zur README](../README.md)

## Lokale Umgebung

- Arduino IDE oder PlatformIO mit ESP32-Unterstützung (Annahme)
- ESP32-Board und erreichbares DiyHue-Gateway zum Testen

## Code-Struktur

- `main.c`: WLAN-Setup und Demo-Schleife
- `HueControl.h`: Deklarationen (`group`, `light`, `color`, `brightness`, `extern ip`, `extern user_name`)
- `HueControl.c`: Implementierung; jede Funktion baut URL und JSON-Body und sendet `PUT`

## Bekannte Probleme

- Fehlende schließende Klammern in `if(strcmp(device_type,"light"){` (mehrfach).
- `strcmp` liefert bei Gleichheit 0; die Bedingung muss `strcmp(...) == 0` lauten.
- `brightness` hat keinen Rückgabetyp (`void` ergänzen).
- `HueControl.h` nutzt `byte`, `bool`, `String` ohne `#include <Arduino.h>`; Include-Guard heißt `FILE_FOO_SEEN`.
- `color()`: RGB-Werte werden nicht auf 0-1 normiert (Vergleich mit 0.04045 auf 0-255-Werten) und Zwischenergebnisse als `int` gespeichert; Division durch 0 bei Schwarz (X+Y+Z=0).
- Stark duplizierter Code; eine gemeinsame Hilfsfunktion für den PUT-Request wäre sinnvoll.
- Der `main.c`-Aufruf `color(...)` läuft ohne Pause in `loop()` und wird dadurch ständig wiederholt.
- Dateiendung `.c` passt nicht zu C++-Code (`String`, `HTTPClient`); `.cpp`/`.ino` verwenden.
- Der Workflow `msbuild.yml` erwartet eine Visual-Studio-Solution, die nicht existiert.

## Tests

Es sind keine Tests vorhanden. Empfehlung: Farbumrechnung als reine Funktion auslagern und per Unit-Test prüfen; Funktionstest gegen DiyHue.

## Coding-Standards

Keine definierten Vorgaben (Annahme). Vorschlag: einheitliche Einrückung, englische oder deutsche Kommentare konsistent, Fehlerbehandlung vereinheitlichen.

## Release-Ablauf

Kein formaler Ablauf vorhanden. Vorschlag: Änderungen testen, Version im Kopfkommentar (`Version: 1.00`) anpassen, Git-Tag setzen.
