#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a dervifferent address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafrouit_PWMServoDriver(0x40, Wire);


// Depending on your servo make, the pulse width min and max may vary, you
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  2048 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  2049 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  553 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2305 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates


// our servo # counter
uint8_t servonum = 0;


int incomingByte = 0; // for incoming serial data


const unsigned int MAX_MESSAGE_LENGTH = 12;




void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);


pwm.begin();


pwm.setOscillatorFrequency(27000000);
 pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates


 delay(10);
}


void loop() {
 // put your main code here, to run repeatedly:
while (Serial.available() == 0) {
 }


 int menuChoice = Serial.parseInt();



 switch (menuChoice) {
   case 1:
     // temp sensor code goes here
     for (uint16_t microsec = USMIN; microsec < USMAX; microsec++)
       {
       pwm.writeMicroseconds(0, microsec);
       }
     Serial.println("case 1 with degrees: ");
     break;


   case 2:
     // humidity sensor code goes here
     for (uint16_t microsec = USMAX; microsec > USMIN; microsec--)
       {
       pwm.writeMicroseconds(0, microsec);
       }
     Serial.println("case 2");
     break;


   default:
     Serial.println("Please choose a valid selection");
 }
}
