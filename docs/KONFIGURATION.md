# Konfiguration

[← Zurück zur README](../README.md)

Es gibt keine Umgebungsvariablen, Konfigurationsdateien, Hooks oder Filter. Die Konfiguration erfolgt über globale Variablen in `main.c`.

## Einstellungen

| Variable | Typ | Beschreibung |
|---|---|---|
| `ssid` | `const char*` | WLAN-Name |
| `password` | `const char*` | WLAN-Passwort |
| `ip` | `String` | IP oder Hostname des Gateways (in `HueControl.h` als `extern` deklariert) |
| `user_name` | `String` | API-Benutzername des Gateways (`extern`) |

## Feste Werte im Code

| Wert | Ort | Beschreibung |
|---|---|---|
| `115200` | `setup()` | Baudrate der seriellen Schnittstelle |
| `500` ms | `loop()` | Pause zwischen Demo-Befehlen |
| `1000` ms | `setup()` | Wartezeit zwischen WLAN-Verbindungsprüfungen |

## Sicherheitshinweis

Zugangsdaten nicht im Repository einchecken. Verwendet werden Platzhalter; echte Werte nur lokal eintragen.
