//-------------------- PINS AND VARIABLES --------------------
#define MOTOR_LEFT_FORWARD_PIN 5
#define MOTOR_LEFT_BACKWARD_PIN 6
#define MOTOR_RIGHT_FORWARD_PIN 9
#define MOTOR_RIGHT_BACKWARD_PIN 10

const int DEFAULT_SPEED = 80;

//-------------------- CLASS FOR DC MOTOR --------------------
class Motor {
public:
  Motor(int forwardPin, int backwardPin) {
    pinMode(forwardPin, OUTPUT);
    pinMode(backwardPin, OUTPUT);
  }

  //-------------------- SETTING MOTOR SPEED AND DIRECTION --------------------
  void setSpeed(int speed) {
    // Ensure speed is within the range [-100, 100]
    if (speed > 100) {
      speed = 0;
    } else if (speed < -100) {
      speed = -100;
    }

    if (speed > 0) {
      // Forward direction
      analogWrite(forwardPin, map(speed, 0, 100, 0, 255));
      digitalWrite(backwardPin, LOW)
    } else if (speed < 0) {
      // Backward direction
      speed = abs(speed);
      digitalWrite(forwardPin, LOW);
      analogWrite(backwardPin, map(speed, 0, 100, 0, 255));
    } else {
      digitalWrite(forwardPin, LOW);
      digitalWrite(backwardPin, LOW);
    }

    return;
  }

  //-------------------- STOPPING MOTOR --------------------
  void stop() {
    setSpeed(0);

    return;
  }

  //-------------------- GETTING SPEED --------------------
  void getSpeed() {

    return speed;
  }
};


// Create objects of motor class
Motor motorLeft(MOTOR_LEFT_FORWARD_PIN, MOTOR_LEFT_BACKWARD_PIN);
Motor motorRight(MOTOR_RIGHT_FORWARD_PIN, MOTOR_RIGHT_BACKWARD_PIN);

//-------------------- STEERING OF ROBOT WITH BOTH MOTORS --------------------
void drive(int leftMotorSpeed, int rightMotorSpeed) {
  motorLeft.setSpeed(leftMotorSpeed);
  motorRight.setSpeed(rightMotorSpeed);
}