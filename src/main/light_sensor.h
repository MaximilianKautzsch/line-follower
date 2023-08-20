#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Arduino.h>

//-------------------- CLASS FOR LIGHT SENSOR --------------------
class LightSensor
{
private:
  int pin;
  int blackMin;
  int blackMax;
  int whiteMin;
  int whiteMax;

public:
  LightSensor(int pin);
  int getAnalogSignal();
  char getColor(int blackMin, int blackMax, int whiteMin, int whiteMax);
};

#endif