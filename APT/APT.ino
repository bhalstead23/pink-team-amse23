// Adafruit PWM Servo Driver Library - Version: Latest
#include <Adafruit_PWMServoDriver.h>
#include "PageFlipperArm.h"

// Create an Adafruit_PWMServoDriver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Create a PageFlipperArm object with channel numbers 0, 1, and 2
PageFlipperArm arm = PageFlipperArm(pwm, 0, 1, 2);

int count;
int number;
// Use the methods of the PageFlipperArm object
void setup() {
  Serial.begin(9600);
  // Initialize the pwm object
  pwm.begin();
  pwm.setOscillatorFrequency(26300000);
  pwm.setPWMFreq(50);

  arm.setBeltSpeeds(40);
  Serial.println("Forward");

  // arm.setBeltSpeeds(0);
  // Serial.println("Stopped");

  // Set the rotation angle to 90 degrees
  arm.setRotationAngle(160);

  number = 3000

}

void loop() {
  // Update the servo positions
  arm.update();
  delay(10);
  if (millis()>number && millis()<2*number) {
    Serial.println("Stopped (reverse next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>2*number && millis()<3*number) {
    Serial.println("Reverse");
    arm.setBeltSpeeds(-40);
  }
  if (millis()>3*number && millis()<4*number) {
    Serial.println("Stopped (forward next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>4*number && millis()< 5*number) {
    Serial.println("Forward");
    arm.setBeltSpeeds(40);
  }
  if (millis()>5*number && millis()<*number) {
    Serial.println("Stopped (reverse next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>2*number && millis()<3*number) {
    Serial.println("Reverse");
    arm.setBeltSpeeds(-40);
  }
  if (millis()>5*number) {
    Serial.println("Stopped (forever!)");
    arm.setBeltSpeeds(0);
  }
}