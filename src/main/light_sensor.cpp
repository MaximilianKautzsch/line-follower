#include "light_sensor.h"

LightSensor::LightSensor(int pin) {
  this->pin = pin;
  pinMode(this->pin, INPUT);
}

//-------------------- GETTING ANALOG SIGNAL --------------------
int LightSensor::getAnalogSignal() {
  static unsigned long temporaryValue;
  int analogSignal;

  // read digital signal from input pin
  if (millis() > temporaryValue + 10) {
    analogSignal = analogRead(pin);
  }

  return analogSignal;
}

//-------------------- GETTING COLOR --------------------
char LightSensor::getColor(int blackMin, int blackMax, int whiteMin, int whiteMax) {
  this->blackMin = blackMin;
  this->blackMax = blackMax;
  this->whiteMin = whiteMin;
  this->whiteMax = whiteMax;

  char color;

  // convert signal to color
  if (blackMin <= getAnalogSignal() && getAnalogSignal() <= blackMax) {
    color = 'b';
  } else if (whiteMin <= getAnalogSignal() && getAnalogSignal() <= whiteMax) {
    color = 'w';
  }

  return color;
}