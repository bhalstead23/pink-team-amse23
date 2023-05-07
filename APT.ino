// Adafruit PWM Servo Driver Library - Version: Latest
#include <Adafruit_PWMServoDriver.h>
#include "PageFlipperArm.h"

// Create an Adafruit_PWMServoDriver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Create a PageFlipperArm object with channel numbers 0, 1, and 2
PageFlipperArm arm = PageFlipperArm(pwm, 0, 1, 2);

// Use the methods of the PageFlipperArm object
void setup() {
  // Initialize the pwm object
  pwm.begin();
  pwm.setPWMFreq(60);

  // Set the belt speeds to 50
  arm.setBeltSpeeds(50);

  // Set the rotation angle to 90 degrees
  arm.setRotationAngle(90);
}

void loop() {
  // Update the servo positions
  arm.update();
}