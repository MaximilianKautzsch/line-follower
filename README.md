# Line Follower &middot; ![Project Status](https://img.shields.io/badge/project_status-building-cyan) [![Feedback is welcome](https://img.shields.io/badge/feedback-welcome-green)](https://github.com/MaximilianKautzsch) [![GitHub License](https://img.shields.io/github/license/MaximilianKautzsch/line-follower?color=blue)](https://github.com/MaximilianKautzsch/line-follower/blob/main/LICENSE)

Source code for robot that can follow a black line using a PID controller.

**To-Do's:**

- [ ] Finish program
- [ ] Test out robot
- [ ] Finish documentation
- [ ] Set project status to closed
- [ ] Upload all programs with submodules as one .zip file into the `src/main` directory

## Used Methods

### DC Motor

| Method                                           | Returned Parameters |  Description                                                                                                             |
| ------------------------------------------------ | ------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| `setSpeed(int speed)`                            | none                | Set the speed value to control the absolute value and direction of the robots velocity with PWM. Value from -100 to 100. |
| `stop()`                                         | none                | Stop the motor.                                                                                                          |
| `getSpeed()`                                     | int speed           | Get the current speed of the motor.                                                                                      |
| `drive(int leftMotorSpeed, int rightMotorSpeed)` | none                | Drive the robot by controlling both motors at once.                                                                      |

### Light Sensor

| Method              | Returned Parameters | Description                                                                             |
| ------------------- | ------------------- | --------------------------------------------------------------------------------------- |
| `getAnalogSignal()` |  int analogSignal   | Read the analog signal from the light sensor.                                           |
| `getColor()`        | char color          | Convert the analog signal into the corresponding color. Value is either black or white. |

### Main

| Method                                           | Returned Parameters | Description                                                                                    |
| ------------------------------------------------ | ------------------- | ---------------------------------------------------------------------------------------------- |
| `drive(int leftMotorSpeed, int rightMotorSpeed)` | none                | Drive the robot by controlling both motors at once.                                            |
| `followLine()`                                   | none                | Control the steering of the robot using PID controller. Return current speed from both motors. |
