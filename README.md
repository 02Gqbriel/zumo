# Zumo 32U4 Roboter - Modul 242

This is a simple program written for a Zumo 32U4 robot, which is a small, Arduino-compatible robot that can be controlled with the Zumo library. The program uses the Zumo's line sensors and proximity sensors to navigate.

## Enthaltene Bibliotheken

```cpp
#include <Wire.h>
#include <Zumo32U4.h>
```

## Funktionalität

- Das Programm beginnt mit der Einbindung der erforderlichen Bibliotheken für den Zumo-Roboter und der Einrichtung der verschiedenen Komponenten des Roboters, wie Motoren, Tasten, Zeilensensoren und Näherungssensoren.
- Das Programm definiert auch mehrere Konstanten für die verschiedenen Zustände, in denen sich der Roboter befinden kann, z. B. "VORWÄRTS" und "RÜCKWÄRTS", und setzt den Anfangszustand auf "VORWÄRTS".
In der Funktion ` setup()`cpp initialisiert das Programm die Linien- und Näherungssensoren und kalibriert die Liniensensoren.
- Third item
