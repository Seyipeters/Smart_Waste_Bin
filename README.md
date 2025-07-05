# Smart Waste Bin

This project is an Arduino-based smart waste bin that uses an ultrasonic sensor and a servo motor to automatically open and close the lid when an object (such as a hand) is detected nearby. The system is built using PlatformIO and is designed for the Arduino Uno board.

## Features

- **Automatic Lid Opening/Closing:** The lid opens when an object is detected within 15 cm and closes after a short delay.
- **Ultrasonic Distance Sensing:** Accurate distance measurement to detect approaching objects.
- **Servo Motor Control:** Smooth and reliable lid movement.
- **Debouncing and Averaging:** Reduces false triggers by averaging multiple distance readings.

## Hardware Requirements

- Arduino Uno
- Ultrasonic Sensor (HC-SR04 or compatible)
- Servo Motor
- Jumper wires
- Waste bin with a movable lid

## Getting Started

1. Clone this repository.
2. Open the project in [PlatformIO](https://platformio.org/).
3. Connect your hardware as per the pin assignments in `src/main.cpp`.
4. Upload the code to your Arduino Uno.

## Pin Assignments

- **Trig Pin:** D5
- **Echo Pin:** D6
- **Servo Pin:** D7

## Demo Video

[Watch the demo video here](https://your-demo-video-link.com)

## Project Structure

```
.
├── include/
├── lib/
├── src/
│   └── main.cpp   # Main code for the Smart Waste Bin project
├── test/
├── platformio.ini
```
