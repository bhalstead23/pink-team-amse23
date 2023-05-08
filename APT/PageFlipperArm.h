// PageFlipperArm.h
#pragma once
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
#include "PWMServo.h"
#include "PWMServoContinuous.h"


// A class for controlling a page flipper arm mechanism using three servos
class PageFlipperArm {
  private:
    // A reference to the Adafruit_PWMServoDriver object
    Adafruit_PWMServoDriver pwm;
    // The PWMServoContinuous objects for the two continuous rotation servos
    PWMServoContinuous CR1;
    PWMServoContinuous CR2;
    // The PWMServo object for the position servo
    PWMServo P1;

  public:
    // A constructor that takes an Adafruit_PWMServoDriver object, channel numbers, and optionally PWM values for each servo
    PageFlipperArm(
      Adafruit_PWMServoDriver &pwmDriver, 
      int CR1Pin,
      int CR2Pin,
      int P1Pin,
      int CRMinPWM = 184, 
      int CRMaxPWM = 430, 
      int PMinPWM = 120, 
      int PMaxPWM = 450
    );
    // A method that sets the belt speeds based on a speed value
    void setBeltSpeeds(int speed);
    // A method that sets the rotation angle based on an angle value
    void setRotationAngle(int degrees);
    // A method that updates the servo positions by calling their update() methods
    void update();
};
