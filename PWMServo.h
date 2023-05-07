// PWMServo.h
#pragma once
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>
class PWMServo {
  private:
    Adafruit_PWMServoDriver pwm;
    int channel;
    int minPWM;
    int maxPWM;
    int minAngle;
    int maxAngle;
    int angle;
  
  public:
    PWMServo(Adafruit_PWMServoDriver &pwmDriver, int ch, int minP = 150, int maxP = 600, int minA = 0, int maxA = 180);
    int getAngle() const;
    void setAngle(int degrees);
    void update();
};