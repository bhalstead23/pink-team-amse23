// PWMServo.cpp
#include "PWMServo.h"
PWMServo::PWMServo(Adafruit_PWMServoDriver &pwmDriver, uint8_t ch, int minP, int maxP, int minA, int maxA) :
  pwm(pwmDriver), 
  channel(ch), 
  minPWM(minP), 
  maxPWM(maxP), 
  minAngle(minA), 
  maxAngle(maxA), 
  angle(0),
  PWMVal(300) {}

int PWMServo::getAngle() const {
  return angle;
}

void PWMServo::setAngle(int degrees) {
  if (degrees >= minAngle && degrees <= maxAngle) {
    angle = degrees;
  } else {
    Serial.println("Angle value out of range");
    angle = constrain(degrees, minAngle, maxAngle);
  }
  setPWMVal(map(angle, minAngle, maxAngle, minPWM, maxPWM));
}

int PWMServo::getPWMVal() const {
  return PWMVal;
}

void PWMServo::setPWMVal(int val) {
  if (val >= minPWM && val <= maxPWM) {
    PWMVal = val;
  } else {
    Serial.println("PWM value out of range");
    PWMVal = constrain(val, minPWM, maxPWM);
  }
}

void PWMServo::update() {
  pwm.setPWM(channel, 0, PWMVal);
}