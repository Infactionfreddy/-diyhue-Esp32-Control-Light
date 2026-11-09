# Installation

[← Zurück zur README](../README.md)

## Voraussetzungen

- ESP32-Board mit USB-Kabel
- Arduino IDE mit installiertem ESP32-Board-Paket (oder PlatformIO) – Annahme, da `WiFi.h` und `HTTPClient.h` verwendet werden
- DiyHue oder Hue Bridge im selben Netzwerk, API-Benutzername vorhanden

## Schritt für Schritt

1. Repository klonen: `git clone https://github.com/Infactionfreddy/-diyhue-Esp32-Control-Light.git`
2. Neuen Arduino-Sketch anlegen und `main.c` (als `.ino`/`.cpp`, Annahme), `HueControl.c` und `HueControl.h` einbinden. Da der Code C++-Klassen (`String`, `HTTPClient`) nutzt, muss er als C++ kompiliert werden.
3. In `main.c` `ssid`, `password`, `ip` und `user_name` setzen.
4. Board und Port auswählen, kompilieren und hochladen.
5. Seriellen Monitor mit 115200 Baud öffnen.

Hinweis: Der aktuelle Code enthält Syntaxfehler und muss vor dem Kompilieren korrigiert werden (siehe [Entwicklung](ENTWICKLUNG.md#bekannte-probleme)).

## Update

`git pull` ausführen, Konfigurationswerte prüfen und erneut flashen.

## Deinstallation

Sketch-Ordner löschen. Auf dem ESP32 ein anderes Programm flashen oder den Flash löschen.
