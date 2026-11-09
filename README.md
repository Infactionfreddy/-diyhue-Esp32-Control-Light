# Diyhue Esp32 Control

![Sprache: C/C++](https://img.shields.io/badge/Sprache-C%2FC%2B%2B-blue) ![Plattform: ESP32](https://img.shields.io/badge/Plattform-ESP32-green)

Ein kleines Beispielprojekt, um die Philips-Hue-API (getestet mit [DiyHue](https://github.com/diyhue/diyHue)) von einem ESP32 aus zu steuern: Lampen und Gruppen ein-/ausschalten, dimmen und Farben setzen.

> Hinweis des Autors (aus der alten README): Dies war ein kleines Beispiel zur Steuerung der Philips-Hue-API auf einem ESP32. Getestet mit DiyHue.

## Features

- Lampe (`light`) oder Gruppe (`group`) ein- und ausschalten
- Helligkeit setzen (8 Bit, 0-254)
- Farbe per RGB (0-255) setzen, Umrechnung nach CIE-xy
- Ausgabe von Request-URL und Antwort über die serielle Schnittstelle (115200 Baud)

## Tech-Stack

- C/C++ im Arduino-Framework für ESP32 (`WiFi.h`, `HTTPClient.h`) – abgeleitet aus den Includes
- Hue-REST-API (HTTP `PUT`) gegen DiyHue oder eine Hue Bridge

## Schnellstart

### Voraussetzungen

- ESP32-Board
- Arduino IDE oder PlatformIO mit ESP32-Core (Annahme)
- Erreichbares DiyHue-/Hue-Gateway im lokalen Netz mit gültigem API-Benutzernamen

### Installation

1. Repository klonen.
2. In `main.c` die Werte `ssid`, `password`, `ip` und `user_name` eintragen.
3. Die Dateien als Arduino-Sketch einbinden (siehe [Installation](docs/INSTALLATION.md)).

### Start

Sketch kompilieren, auf den ESP32 flashen und den seriellen Monitor mit 115200 Baud öffnen.

> **Achtung:** Der Code im Repository ist in dieser Form noch nicht kompilierbar (siehe [Entwicklung](docs/ENTWICKLUNG.md#bekannte-probleme)).

## Konfiguration

Es gibt keine Umgebungsvariablen; die Konfiguration erfolgt über Variablen im Quelltext von `main.c`:

| Variable | Beschreibung |
|---|---|
| `ssid` | WLAN-Name |
| `password` | WLAN-Passwort |
| `ip` | IP oder Hostname des Hue-Gateways |
| `user_name` | API-Benutzername des Gateways |

## Projektstruktur

```
.
├── .github/workflows/msbuild.yml  # CI-Workflow (MSBuild, siehe Hinweise)
├── HueControl.c                   # Hue-Funktionen (HTTP-Requests)
├── HueControl.h                   # Deklarationen
├── main.c                         # setup()/loop() Demo
└── README.md
```

## Dokumentation

- [Architektur](docs/ARCHITEKTUR.md)
- [Installation](docs/INSTALLATION.md)
- [Konfiguration](docs/KONFIGURATION.md)
- [Entwicklung](docs/ENTWICKLUNG.md)
- [API](docs/API.md)
