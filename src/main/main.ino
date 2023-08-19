#include "dc_motor.h"
#include "light_sensor.h"



//==================== GENERAL CONFIG ====================


//-------------------- PINS AND VARIABLES --------------------

#define MOTOR_LEFT_FORWARD_PIN 5
#define MOTOR_LEFT_BACKWARD_PIN 6
#define MOTOR_RIGHT_FORWARD_PIN 9
#define MOTOR_RIGHT_BACKWARD_PIN 10

#define LIGHT_SENSOR_LEFT_PIN 14
#define LIGHT_SENSOR_RIGHT_PIN 15


const int BLACK_MIN = 100;
const int BLACK_MAX = 300;
const int WHITE_MIN = 800;
const int WHITE_MAX = 1023;

int minimumValue = 0;
int maximumValue = 1023;


const int DEFAULT_SPEED = 80;


int proportionalTerm, integralTerm, derivativeTerm, previousError, error, controlTerm;

const float proportionalConstant = 1;
const float integralConstant = 1;
const float derivativeConstant = 1;

//-------------------- CREATING OBJECTS --------------------

// Create objects of motor class
Motor motorLeft(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN);
Motor motorRight(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN);

// Create objects of light sensor class
LightSensor sensorLeft(LIGHT_SENSOR_LEFT_PIN);
LightSensor sensorRight(LIGHT_SENSOR_RIGHT_PIN);

//-------------------- SETUP --------------------

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
}



//==================== MAIN PROGRAMM ====================

//-------------------- LOOP --------------------

void loop() {
  Serial.print(sensorLeft.getAnalogSignal());
  Serial.print("\t");
  Serial.print(sensorRight.getAnalogSignal());
  Serial.print("\t");
  Serial.print(sensorLeft.getColor(BLACK_MIN, BLACK_MAX, WHITE_MIN, WHITE_MAX));
  Serial.print("\t");
  Serial.println(sensorRight.getColor(BLACK_MIN, BLACK_MAX, WHITE_MIN, WHITE_MAX));
}

//-------------------- STEERING OF ROBOT WITH BOTH MOTORS --------------------
void drive(int leftMotorSpeed, int rightMotorSpeed) {
  motorLeft.setSpeed(leftMotorSpeed);
  motorRight.setSpeed(rightMotorSpeed);
}

//-------------------- PID ALGORITHM --------------------
void followLine() {
  int leftValue = sensorLeft.getAnalogSignal();
  int rightValue = sensorRight.getAnalogSignal();
  int error = leftValue - rightValue;

  int leftMotorSpeed = DEFAULT_SPEED - controlTerm;
  int rightMotorSpeed = DEFAULT_SPEED + controlTerm;

  proportionalTerm = error;
  integralTerm = integralTerm + error;
  derivativeTerm = error - previousError;

  controlTerm = (proportionalConstant * proportionalTerm) + (integralConstant * integralTerm) + (derivativeConstant * derivativeTerm);
  error = previousError;

  drive(leftMotorSpeed, rightMotorSpeed);
  
  return leftMotorSpeed, rightMotorSpeed;
}