// PageFlipperArm.cpp
#include "PageFlipperArm.h"
PageFlipperArm::PageFlipperArm(Adafruit_PWMServoDriver &pwmDriver, int CR1Pin, int CR2Pin, int P1Pin, int CRMinPWM, int CRMaxPWM, int PMinPWM, int PMaxPWM) : 
  pwm(pwmDriver), 
  CR1(pwmDriver, CR1Pin, CRMinPWM, CRMaxPWM), 
  CR2(pwmDriver, CR2Pin, CRMinPWM, CRMaxPWM), 
  P1(pwmDriver, P1Pin, PMinPWM, PMaxPWM) {}

void PageFlipperArm::setBeltSpeeds(int speed) {
  // Set the speed of CR1 using its setSpeed() method
  CR1.setSpeed(speed);
  // Set the speed of CR2 using its setSpeed() method with opposite direction
  CR2.setSpeed(-speed);
}

void PageFlipperArm::setRotationAngle(int degrees) {
  // Set the angle of P1 using its setAngle() method
  P1.setAngle(degrees);
}

void PageFlipperArm::update() {
  // Call update() for each servo object
  CR1.update();
  CR2.update();
  P1.update();
}