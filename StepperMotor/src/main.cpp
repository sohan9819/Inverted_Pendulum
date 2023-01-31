#include <Arduino.h>
#include <AccelStepper.h>

#define MAX_SPEED 3000

// STEPPER PINS
// stepper(mode , pulse  , dir)
AccelStepper stepper(1, 9, 8);

// LIMIT SWITCH PINS
int MicroSwitch_Left = 3;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("start");

  pinMode(MicroSwitch_Left, INPUT);

  stepper.setMaxSpeed(MAX_SPEED);
  stepper.setAcceleration(MAX_SPEED);

  bool MicroSwitch_Left_Value = digitalRead(MicroSwitch_Left);

  while (!MicroSwitch_Left_Value)
  {
    /* code */
    stepper.setSpeed(MAX_SPEED / 2);
    stepper.moveTo(-1000);
    stepper.run();
  }
  stepper.stop();
  stepper.setCurrentPosition(0);
}

void loop()
{
  // put your main code here, to run repeatedly:
  stepper.moveTo(1000);
  stepper.run();

  Serial.print("Stepper position");
  Serial.println(stepper.currentPosition());
}