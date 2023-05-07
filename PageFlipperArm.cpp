// PageFlipperArm.cpp
#include "PageFlipperArm.h"
PageFlipperArm::PageFlipperArm(Adafruit_PWMServoDriver &pwmDriver, int ch1, int ch2, int ch3, int min1, int max1, int min2, int max2, int min3, int max3) : pwm(pwmDriver), CR1(pwmDriver, ch1, min1, max1), CR2(pwmDriver, ch2, min1, max1), P1(pwmDriver, ch3, min2, max2) {}

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