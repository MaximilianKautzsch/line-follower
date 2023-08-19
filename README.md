# Line Follower &middot; ![Project Status](https://img.shields.io/badge/project_status-building-cyan) [![Feedback is welcome](https://img.shields.io/badge/feedback-welcome-green)](https://github.com/MaximilianKautzsch) [![GitHub License](https://img.shields.io/github/license/MaximilianKautzsch/line-follower?color=blue)](https://github.com/MaximilianKautzsch/line-follower/blob/main/LICENSE)

Source code for robot that can follow a black line using a PID controller.

<!--
TODO:

- [ ] Finish program
- [ ] Test out robot
- [ ] Set project status to closed
- [ ] Upload all programs with submodules as one .zip file into the `src/main` directory

-->

## Hardware Components

- Chassis: [Standart Robot Car Chassis Kit](https://www.amazon.de/Smart-Chassis-Motors-Encoder-Battery/dp/B01LXY7CM3/ref=sr_1_5?keywords=robot+chassis&qid=1692451580&sr=8-5)
- Microcontroller / SBM: [Arduino Uno Rev3](https://www.amazon.de/Arduino-A000066-UNO-Rev3/dp/B008GRTSV6/ref=sr_1_3?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=3GB4E0KZ111IV&keywords=arduino%2Buno%2Brev3&qid=1692451624&sprefix=arduino%2Buno%2Brev3%2Caps%2C105&sr=8-3&th=1)
- IR-Sensor (2x): [MH Sensor Series TCRT5000](https://www.amazon.de/AZDelivery-TRCT5000-Infrarot-Hindernis-Vermeidung/dp/B07DRCKV3X/ref=sr_1_3?keywords=Tcrt5000&qid=1692451702&sr=8-3)
- DC-Motor (2x): [Standard 12V DC Motor](https://www.amazon.de/Gebildet-Getriebemotor-Allradantrieb-Spielzeugauto-Flugzeugspielzeug-Chargennummer/dp/B07Z4PYJY4/ref=sr_1_26?keywords=dc%2Bmotor&qid=1692451768&sr=8-26&th=1)
- Batteries: [Amazon Basic batteries](https://www.amazon.de/Amazon-Basics-AA-Alkalibatterien-leistungsstark-variieren-Grau/dp/B00NTCH52W/ref=sr_1_10?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=24A8CZRLISJW2&keywords=star+batterien&qid=1692451810&sprefix=star+batterien%2Caps%2C96&sr=8-10)

## Used Methods

### DC Motor

| Method                | Returned Parameters |  Description                                                                                                             |
| --------------------- | ------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `setSpeed(int speed)` | none                | Set the speed value to control the absolute value and direction of the robots velocity with PWM. Value from -100 to 100. |
| `stop()`              | none                | Stop the motor.                                                                                                          |

### Light Sensor

| Method                                                             | Returned Parameters | Description                                                                                         |
| ------------------------------------------------------------------ | ------------------- | --------------------------------------------------------------------------------------------------- |
| `getAnalogSignal()`                                                | int analogSignal    | Read the analog signal from the light sensor.                                                       |
| `getColor(int blackMin, int blackMax, int whiteMin, int whiteMax)` | char color          | Convert the analog signal into the corresponding color. Value is either black ('b') or white ('w'). |

### Main

| Method                                           | Returned Parameters | Description                                                                                    |
| ------------------------------------------------ | ------------------- | ---------------------------------------------------------------------------------------------- |
| `drive(int leftMotorSpeed, int rightMotorSpeed)` | none                | Drive the robot by controlling both motors at once.                                            |
| `followLine()`                                   | int speed           | Control the steering of the robot using PID controller. Return current speed from both motors. |
