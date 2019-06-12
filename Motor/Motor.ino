/*
 * Author: Hanbyul Park
 * Description: Code for running dc motor for 5 seconds and stop.
 */
#include <AFMotor.h>
#include <Servo.h> 

// DC motor on M1
AF_DCMotor motor1(1);

// DC motor on M2
AF_DCMotor motor2(2);

unsigned long mili_time;
long real_time;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Basic motor settings");

  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(RELEASE);
  motor2.run(RELEASE); 
}

void loop() {
  mili_time = (unsigned long)millis();
  real_time = (mili_time / 1000);

  if (real_time >= 5) {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    return;
  }
  motor1.run(FORWARD); 
  motor2.run(FORWARD);
}
