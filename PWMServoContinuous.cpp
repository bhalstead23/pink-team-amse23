// PWMServoContinuous.cpp
#include "PWMServoContinuous.h"
PWMServoContinuous::PWMServoContinuous(Adafruit_PWMServoDriver &pwmDriver, int ch, int min, int max) : pwm(pwmDriver), channel(ch), minPWM(min), maxPWM(max), speed(0) {}

int PWMServoContinuous::getSpeed() const {
  return speed;
}

void PWMServoContinuous::setSpeed(int s) {
  // Check if the speed is within the range of -100 and 100
  if (s >= -100 && s <= 100) {
    // Assign the speed value
    speed = s;
  } else {
    // Print an error message
    Serial.println("Speed value out of range");
    // Constrain the speed value to the range of -100 and 100
    speed = constrain(s, -100, 100);
  }
  // Map the speed to a PWM value using a linear function
  setPWMVal(map(speed, -100, 100, minPWM, maxPWM));
}

int PWMServoContinuous::getPWMVal() const {
  return PWMVal;
}

void PWMServoContinuous::setPWMVal(int val) {
  if (val >= minPWM && val <= maxPWM) {
    PWMVal = val;
  } else {
    Serial.println("PWM value out of range");
    PWMVal = constrain(val, minPWM, maxPWM);
  }
}

void PWMServoContinuous::update() {
  // Set the PWM value for the servo channel
  pwm.setPWM(channel, 0, PWMVal);
}