#include "dc_motor.h"

Motor::Motor(int forwardPin, int backwardPin) {
  this->forwardPin = forwardPin;
  this->backwardPin = backwardPin;
  pinMode(this->forwardPin, OUTPUT);
  pinMode(this->backwardPin, OUTPUT);
}

//-------------------- SETTING MOTOR SPEED AND DIRECTION --------------------
void Motor::setSpeed(int speed) {
  this->speed = speed;

  // Ensure speed is within the range [-100, 100]
  if (speed > 100) {
    speed = 100;
  } else if (speed < -100) {
    speed = -100;
  }

  if (speed > 0) {
    // Forward direction
    analogWrite(forwardPin, map(speed, 0, 100, 0, 255));
    digitalWrite(backwardPin, LOW);
  } else if (speed < 0) {
    // Backward direction
    speed = abs(speed);
    digitalWrite(forwardPin, LOW);
    analogWrite(backwardPin, map(speed, 0, 100, 0, 255));
  } else {
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
  }
}

//-------------------- STOPPING MOTOR --------------------
void Motor::stop() {
  setSpeed(0);
}