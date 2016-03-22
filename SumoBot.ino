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

void rightAccelerate(float speedInitial, float speedFinal){
  if(speedFinal>=speedInitial){
    for(int speed = speedInitial; speed<=speedFinal;speed++)
    {
      motors.setRightSpeed(speed);
      delay(2);
    }
  }
  else if(speedFinal<speedInitial){
    for(int speed = speedInitial; speed>=speedFinal;speed--)
    {
      motors.setRightSpeed(speed);
      delay(2);
    }
  }
}
void leftAccelerate(float speedInitial, float speedFinal){
  if(speedFinal>=speedInitial){
    for(int speed = speedInitial; speed<=speedFinal;speed++)
    {
      motors.setLeftSpeed(speed);
      delay(2);
    }
  }
  else if(speedFinal<speedInitial){
    for(int speed = speedInitial; speed>=speedFinal;speed--)
    {
      motors.setLeftSpeed(speed);
      delay(2);
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
