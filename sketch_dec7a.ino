#include <Wire.h>
#include <Zumo32U4.h>

// Robi Funktionen
Zumo32U4Motors motors;

Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;

Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;

Zumo32U4LCD lcd;

// Sensoren Werte
uint16_t lineSensorValues[3] = { 0, 0, 0 };

// Sensoren Index
const unsigned short LEFT_GROUND = 0;
const unsigned short FRONT_GROUND = 1;
const unsigned short RIGHT_GROUND = 2;


// Zustände
const unsigned short LEFT = 1;  
const unsigned short RIGHT = 2;
const unsigned short FORWARDS = 3;
const unsigned short BACKWARDS = 4;
const unsigned short STOP = 4;

unsigned short intensity = 3;

unsigned short zustand;

void setup() {
  lineSensors.initThreeSensors();
  proxSensors.initThreeSensors();

  calibrateLineSensors();
  randomSeed(micros());

  zustand = FORWARDS;
}

void loop() {
  lineSensors.readCalibrated(lineSensorValues);
  proxSensors.read();

  uint8_t sum = proxSensors.countsFrontWithRightLeds() + proxSensors.countsFrontWithLeftLeds();
  int8_t diff = proxSensors.countsFrontWithRightLeds() - proxSensors.countsFrontWithLeftLeds();

  switch (zustand) {
    case FORWARDS:
      motors.setLeftSpeed(300);
      motors.setRightSpeed(300);

      if (lineSensorValues[FRONT_GROUND] < 200) {
        zustand = BACKWARDS;
      }

      break;

    case LEFT:
      motors.setLeftSpeed(300);
      motors.setRightSpeed(-300);

      delay(random(300, 750));

      zustand = FORWARDS;

      break;

    case RIGHT:
      motors.setLeftSpeed(-300);
      motors.setRightSpeed(300);

      delay(random(300, 750));  

      zustand = FORWARDS;

      break;

    case BACKWARDS:
      motors.setSpeeds(-400, -400);

      delay(250);

      if (random(0, 4) > 2) {
        zustand = LEFT;
      } else {
        zustand = RIGHT;
      }

      break;
  }
}

void calibrateLineSensors() {
  ledYellow(1);
  lcd.clear();
  lcd.print(F("Line cal"));

  for (uint16_t i = 0; i < 400; i++) {
    lcd.gotoXY(0, 1);
    lcd.print(i);
    lineSensors.calibrate();
  }

  ledYellow(0);
  lcd.clear();
}
