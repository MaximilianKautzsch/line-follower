//-------------------- PINS AND VARIABLES --------------------
#define LIGHT_SENSOR_LEFT_PIN 14
#define LIGHT_SENSOR_LEFT_PIN 15

const int BLACK_MIN = 800;
const int BLACK_MAX = 1000;
const int WHITE_MIN = 0;
const int WHITE_MAX = 200;

// Get minimum and maximum values of thresholds
int thresholds[] = { WHITE_MIN, WHITE_MAX, BLACK_MIN, BLACK_MAX };

for (int i = 0; i <= sizeof(thresholds); i++) {
  unsigned int minimumValue = min(thresholds[i], minimumValue);

  return minimumValue;
}
for (int i = 0; i <= sizeof(thresholds); i++) {
  unsigned int maximumValue = max(thresholds[i], maximumValue);

  return maximumValue;
}

//-------------------- CLASS FOR LIGHT SENSOR --------------------
class LightSensor {
public:
  LightSensor(int sensorPin) {
    pinMode(sensorPin, INPUT);
  }

  //-------------------- GETTING ANALOG SIGNAL --------------------
  void getAnalogSignal() {
    // read digital signal from input pin
    int analogSignal = analogRead(sensorPin);
    analogSignal = constrain(analogSignal, minimumValue, maximumValue);

    return analogSignal;
  }

  //-------------------- GETTING COLOR --------------------
  void getColor() {
    char color;

    // convert signal to color
    if (BLACK_MIN <= analogSignal && analogSignal <= BLACK_MAX) {
      color = "black";
    } else if (WHITE_MIN <= analogSignal && analogSignal <= WHITE_MAX) {
      color = "white";
    }

    return color;
  }
};

// Create objects of light sensor class
LightSensor sensorLeft(LIGHT_SENSOR_LEFT_PIN);
LightSensor sensorRight(LIGHT_SENSOR_RIGHT_PIN);