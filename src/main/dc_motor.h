#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include <Arduino.h>

//-------------------- CLASS FOR DC MOTOR --------------------
class Motor
{
private:
  int forwardPin;
  int backwardPin;
  int speed;

public:
  Motor(int forwardPin, int backwardPin);
  void setSpeed(int speed);
  void stop();
};

#endif