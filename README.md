# Smart Car Parking Lot Project

## Overview

This **Smart Car Parking Lot Project** aims to create an automated system for managing a parking lot with 4 slots. The system is built using an Arduino, IR sensors, a servo motor, and a Liquid Crystal Display (LCD) to control and display the parking slot availability. The project uses basic logic to detect car entries and exits, and update the available slots dynamically.

The system provides real-time updates on available parking spaces and handles car entry and exit using sensors. It features a servo motor for controlling the entry gate, and LEDs to indicate the status of each parking slot.

## Features

- **Car Slot Management**: Tracks the occupancy of 4 parking slots using IR sensors.
- **Real-Time Display**: Updates and displays the parking lot's status on an LCD.
- **Car Entry & Exit**: Handles the opening and closing of the parking gate using a servo motor when a car enters or exits.
- **Parking Full Warning**: Displays a message when the parking lot is full.
- **Automatic Slot Update**: Dynamically updates available slots as cars enter or exit.

## Components Used

- **Arduino Board**: For controlling the parking system and reading sensor inputs.
- **IR Sensors**: For detecting car presence in the parking slots.
- **Servo Motor**: Controls the parking gate (entry/exit).
- **LCD (Liquid Crystal Display)**: Displays real-time parking status and slot availability.
- **LEDs**: Indicate the status of each parking slot (Empty or Full).
- **Push Buttons**: For simulating car entry and exit (optional for testing).

## Circuit Diagram

Ensure to wire the components correctly as per the circuit diagram. You can find the details of each component below:

- **IR Sensors** connected to digital pins 2 to 8.
- **Servo Motor** connected to pin 3.
- **LEDs** connected to pins 9 to 13.
- **LCD Display** connected via I2C (pins SDA and SCL).
  
## Code Explanation

### 1. Setup

The system begins by initializing the components:
- The IR sensors are set to input mode to detect car presence.
- The servo motor is initialized to control the parking gate.
- The LCD screen is initialized to display welcome messages and project details.

### 2. Parking Slot Management

The system uses 4 parking slots, monitored by IR sensors. Each slot has a corresponding LED to indicate whether the slot is empty (E) or full (F). The status is updated based on the input from the IR sensors.

### 3. Car Entry and Exit

- **Car Entry**: When the entry IR sensor is triggered (simulating a car entering), the servo motor is activated to open the parking gate if there is an available slot. The slot count decreases.
- **Car Exit**: When the exit IR sensor is triggered (simulating a car exiting), the servo motor is activated to open the gate, and the slot count increases.

### 4. Slot Availability Display

The LCD displays:
- The number of available parking slots.
- The status of each slot (empty or full).

### 5. Parking Full Condition

If there are no available slots, the system displays "Parking Full" on the LCD and turns on the warning LED.

## Installation

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/ChandraPrakashC/smart-car-parking.git

Open the project in the Arduino IDE.
Connect the hardware components (IR sensors, servo motor, LCD, etc.) to the Arduino board as described above.
Upload the parking_lot_project.ino code to your Arduino.
Power up the system and observe the behavior of the parking lot management system.
Usage
When a car enters, the system will open the gate and decrement the available slots.
When a car exits, the system will open the gate and increment the available slots.
The LCD screen will display the number of available slots and the status of each slot.
If the parking lot is full, the system will display "Parking Full" on the LCD screen.
Troubleshooting
Servo Motor Not Working: Ensure the servo is connected correctly to the Arduino and that the servo motor is powered properly.
IR Sensors Not Detecting Cars: Check if the IR sensors are aligned correctly and ensure they are receiving power.
LCD Not Displaying: Make sure the I2C connection between the Arduino and the LCD is correctly set up.
Contributing
Feel free to fork this repository and submit issues or pull requests if you have suggestions for improvements.

License
This project is licensed under the MIT License - see the LICENSE file for details.
