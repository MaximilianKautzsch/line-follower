#include "dc_motor.h"
#include "light_sensor.h"

int proportionalTerm, integralTerm, derivativeTerm, previousError, error, controlTerm;

const float proportionalConstant = 1;
const float integralConstant = 1;
const float derivativeConstant = 1;

void setup()
{
  return;
}

void loop()
{
  followLine();
}

void followLine()
{
  int error = sensorLeft.getAnalogSignal() - sensorRight.getAnalogSignal();

  proportionalTerm = error;
  integralTerm = integralTerm + error;
  derivativeTerm = error - previousError;

  controlTerm = (proportionalConstant * proportionalTerm) + (integralConstant * integralTerm) + (derivativeConstant * derivativeTerm);
  error = previousError;

  drive(DEFAULT_SPEED - controlTerm, DEFAULT_SPEED + controlTerm);
}