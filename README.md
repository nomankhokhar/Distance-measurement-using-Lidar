# Distance-measurement-using-Lidar

This repository contains code for distance measurement using Time-of-Flight (ToF) sensors, providing haptic feedback via vibratory motors. The project involves 2 sensor setups to demonstrate various configurations and applications.

## Table of Contents

- [Overview](#overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project demonstrates the use of Time-of-Flight (ToF) sensors for precise distance measurement. It includes configurations for both 2 sensor setups, integrating vibratory motor haptic feedback to provide tactile responses based on distance readings.

## Hardware Requirements

- Time-of-Flight (ToF) sensors (e.g., VL53L0X, VL53L1X)
- Microcontroller (e.g., Arduino, ESP32)
- Vibratory motors
- Connecting wires
- Breadboard or PCB for prototyping

## Software Requirements

- Arduino IDE or PlatformIO
- Required libraries:
  - Wire
  - VL53L0X or VL53L1X library (Already given in Library Folder)
  - Adafruit Motor library (if using Adafruit vibratory motors)

## Installation

1. Clone the repository:

```sh
git clone https://github.com/nomankhokhar/Distance-measurement-using-Lidar.git
cd Distance-measurement-using-Lidar
```

2. Install necessary libraries:

For Arduino IDE:
- Open the Arduino IDE.
- Go to `Sketch` > `Include Library` > `Manage Libraries`.
- Search for `VL53L0X`, `VL53L1X`, and `Adafruit Motor` libraries and install them.

3. Upload the code to your microcontroller:

- Connect your microcontroller to your computer.
- Open the appropriate `.ino` file for your setup (2 sensor or 3 sensor) in the Arduino IDE or PlatformIO.
- Select the correct board and port.
- Upload the code.

## Usage

1. Connect the hardware as per the instructions in the code comments.
2. Power up the microcontroller.
3. Observe the distance measurements and corresponding haptic feedback from the vibratory motors.

### Example

- The 2 sensor setup provides basic left-right feedback.
- The 3 sensor setup adds a center sensor for more nuanced distance detection and feedback.


## Authors

- [@nomankhokhar](https://www.github.com/nomankhokhar)

## Badges

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

## 🚀 About Me

I'm a full Stack Developer...
