//Team GerBear Sumobot Code
//Patrick Hannagan, Dan Schmetterling, Gerry Wagner, and Branden Garret
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>

#define LED_PIN 13

Pushbutton button(ZUMO_BUTTON);
ZumoBuzzer buzzer;
ZumoMotors motors;
ZumoReflectanceSensorArray reflectanceSensors;

void setup() {
  pinMode(LED_PIN, OUTPUT);

}

void loop() {

}
