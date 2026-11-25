# Obstacle-Avoiding Robot Car

Arduino Nano sketch for a two-motor robot car that drives forward and turns away from obstacles using an ultrasonic sensor.

Written during the hands-on robotics workshop conducted by NEXOBOT (November 2026).

## How it works

- The ultrasonic sensor measures the distance ahead roughly every 100 ms.
- If the distance is **50 cm or more**, the car drives forward.
- If the distance is **under 50 cm**, the car stops for 1 second, then turns left for 0.5 seconds.
- If no echo is received within the timeout, the car keeps driving forward.
- The measured distance (or "No echo") is printed to the Serial Monitor at 9600 baud.

## Pin connections (from the code)

|----------------------------|-----|
|       Function             | Pin |
|----------------------------|-----|
| Ultrasonic trigger         | D2  |
| Ultrasonic echo            | D3  |
| Right motor, forward (PWM) | D5  |
| Right motor, reverse (PWM) | D6  |
| Left motor, forward (PWM)  | D9  |
| Left motor, reverse (PWM)  | D10 |
|----------------------------|-----|

Motor speed is set with `analogWrite` (PWM). The base speed is 125 out of 255.

## Hardware

- Arduino Nano
- Ultrasonic distance sensor
- Two DC motors on a robot car chassis

## Running it

1. Open `obstacle_avoiding_car/obstacle_avoiding_car.ino` in the Arduino IDE.
2. Select the Arduino Nano board and the correct port.
3. Upload the sketch, then open the Serial Monitor at 9600 baud to see the distance readings.
