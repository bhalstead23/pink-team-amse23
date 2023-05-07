// PWMServoContinuous.h
#pragma once
#include <Arduino.h>
#include <Adafruit_PWMServoDriver.h>

// A class for controlling a single continuous rotation servo using the Adafruit PWM Servo Driver Library
class PWMServoContinuous {
  private:
    // A reference to the Adafruit_PWMServoDriver object
    Adafruit_PWMServoDriver pwm;
    // The channel number of the servo
    int channel;
    // The minimum and maximum PWM values for the servo
    int minPWM;
    int maxPWM;
    // The speed value for the servo rotation
    int speed;

  public:
    // A constructor that takes an Adafruit_PWMServoDriver object, a channel number, and optionally minimum and maximum PWM values
    PWMServoContinuous(Adafruit_PWMServoDriver &pwmDriver, int ch, int min = 1000, int max = 2000);
    // A method that returns the speed value
    int getSpeed() const;
    // A method that sets the speed value with validation
    void setSpeed(int s);
    // A method that updates the servo speed by using pwm.setPWM()
    void update();
};