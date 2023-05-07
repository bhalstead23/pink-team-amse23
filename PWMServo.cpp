// PWMServo.cpp
#include "PWMServo.h"
PWMServo::PWMServo(Adafruit_PWMServoDriver &pwmDriver, int ch, int minP, int maxP, int minA, int maxA) : pwm(pwmDriver), channel(ch), minPWM(minP), maxPWM(maxP), minAngle(minA), maxAngle(maxA), angle(0) {}

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
}

void PWMServo::update() {
  int pwmValue = map(angle, minAngle, maxAngle, minPWM, maxPWM);
  pwm.setPWM(channel, 0, pwmValue);
}