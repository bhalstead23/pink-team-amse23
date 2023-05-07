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
    int PWMVal;
  
  public:
    PWMServo(Adafruit_PWMServoDriver &pwmDriver, uint8_t ch, int minP = 1000, int maxP = 2000, int minA = 0, int maxA = 180);
    int getAngle() const;
    void setAngle(int degrees);
    int getPWMVal() const;
    void setPWMVal(int val_US);
    void update();
};