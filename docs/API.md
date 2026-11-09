# API

[← Zurück zur README](../README.md)

Die Bibliothek `HueControl` bietet folgende öffentliche Funktionen (deklariert in `HueControl.h`). Voraussetzung: WLAN verbunden, `ip` und `user_name` gesetzt.

## Funktionen

| Funktion | Parameter | Beschreibung |
|---|---|---|
| `void light(byte light_id, bool current_state)` | Lampen-ID, Zustand | Lampe ein-/ausschalten (`{"on":...}`) |
| `void group(byte group_id, bool current_state)` | Gruppen-ID, Zustand | Gruppe ein-/ausschalten |
| `void brightness(char device_type[], byte id, int brightness)` | `"light"` oder `"group"`, ID, Wert 0-254 | Helligkeit (`{"bri":...}`) |
| `void color(char device_type[], byte id, int red, int green, int blue)` | `"light"` oder `"group"`, ID, RGB 0-255 | Farbe als CIE-xy (`{"xy":[x,y]}`) |

## Globale Variablen

| Variable | Beschreibung |
|---|---|
| `String ip` | Adresse des Gateways |
| `String user_name` | API-Benutzername |

## Verwendete Hue-Endpunkte

| Methode | Pfad |
|---|---|
| PUT | `/api/<user_name>/lights/<id>/state` |
| PUT | `/api/<user_name>/groups/<id>/action` |

## Beispiel

```cpp
light(1, true);
brightness("group", 1, 254);
color("light", 1, 255, 0, 0);
```

Hinweis: Rückgabewerte gibt es nicht; Status und Antwort werden über `Serial` ausgegeben. Die Funktionen sind im aktuellen Stand wegen Syntaxfehlern nicht kompilierbar.
