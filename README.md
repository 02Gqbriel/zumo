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
In der Funktion `setup()` initialisiert das Programm die Linien- und Näherungssensoren und kalibriert die Liniensensoren.
- In der Funktion `loop()` liest das Programm die Werte von den Linien- und Näherungssensoren und verwendet diese Werte, um die nächste Bewegung des Roboters zu bestimmen.
- Der Roboter wechselt in den Zustand ***BACKWARDS*** und bewegt sich rückwärts, wenn der vordere Liniensensor einen niedrigen Wert feststellt.
- Befindet sich der Roboter im Zustand ***BACKWARDS***, wählt er nach dem Zufallsprinzip, ob er sich nach links oder nach rechts bewegt.
- Befindet sich der Roboter im Zustand ***VORWÄRTS***, bewegt er sich vorwärts.
- Außerdem enthält das Programm eine Funktion zur Kalibrierung der Liniensensoren, die in der Funktion `setup()` aufgerufen wird.


## Anforderungen

- Zumo 32U4 Roboter
- Arduino IDE
- Zumo library


## Verwendung

1. Schließen Sie den Zumo-Roboter an Ihren Computer an.
2. Öffnen Sie den Code in der Arduino IDE
3. Laden Sie den Code auf den Roboter hoch.
4. Beobachte die Navigation des Roboters mithilfe seiner Linien- und Näherungssensoren.

## Hinweis

Dies ist ein einfaches Beispiel dafür, wie der Zumo-Roboter mit Hilfe seiner Linien- und Näherungssensoren navigiert und zufällige Wendungen macht, wenn er ein Hindernis erkennt. Sie können den Code nach Belieben ändern und an Ihre Bedürfnisse anpassen.
