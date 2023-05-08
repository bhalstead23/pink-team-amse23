// Adafruit PWM Servo Driver Library - Version: Latest
#include <Adafruit_PWMServoDriver.h>
#include "PageFlipperArm.h"


// Create an Adafruit_PWMServoDriver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();


// Create a PageFlipperArm object with channel numbers 0, 1, and 2
// PageFlipperArm arm = PageFlipperArm(pwm, 0, 1, 2);
PageFlipperArm arm = PageFlipperArm(pwm, )

int count;
int number;

void backAndForth(int n) {
  if (millis()>n && millis()<2*n) {
    Serial.println("Stopped (reverse next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>2*n && millis()<3*n) {
    Serial.println("Reverse");
    arm.setBeltSpeeds(-40);
  }
  if (millis()>3*n && millis()<4*n) {
    Serial.println("Stopped (forward next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>4*n && millis()< 5*n) {
    Serial.println("Forward");
    arm.setBeltSpeeds(40);
  }
  if (millis()>5*n && millis()<6*n) {
    Serial.println("Stopped (reverse next)");
    arm.setBeltSpeeds(0);
  }
  if (millis()>6*n && millis()<7*n) {
    Serial.println("Reverse");
    arm.setBeltSpeeds(-40);
  }
  if (millis()>7*n) {
    Serial.println("Stopped (forever!)");
    arm.setBeltSpeeds(0);
  }
}
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
  arm.setRotationAngle(180);

  number = 3750;

}

void loop() {
  if (millis()>number && millis()<2*number) {
    arm.setBeltSpeeds(0);
    arm.setRotationAngle(180 - map(millis(),number,2*number, 0, 65));
    Serial.println("Stopped (Reverse Next)");
  }
  if (millis()>2*number && millis()<2.25*number) {
    arm.setBeltSpeeds(-40);
    Serial.println("Reverse");
  }
  if (millis()>2.25*number && millis()<2.5*number) {
    arm.setRotationAngle(130);
  }
  if (millis()>2.5*number && millis()<2.75*number) {
    arm.setRotationAngle(140);
  }
  if (millis()>2.75*number && millis()<3*number) {
    arm.setRotationAngle(150);
  }
  if (millis()>3*number && millis()<3.5*number) {
    arm.setRotationAngle(160);
  }
  if (millis()>3.5*number && millis()<4*number) {
    arm.setRotationAngle(170);
  }
  if (millis()>4*number && millis()<4.25*number) {
    arm.setBeltSpeeds(0);
    arm.setRotationAngle(180);
    Serial.println("Stopped (Forward Next)");
  }
  if (millis()>4.25*number && millis()<5.1*number) {
    arm.setBeltSpeeds(40);
    Serial.println("Forward");
  }
  if (millis()>5.1*number) {
    arm.setBeltSpeeds(0);
    Serial.println("Stopped Forever");
  }
  
  // Update the servo positions
  arm.update();
  delay(10);
  
}