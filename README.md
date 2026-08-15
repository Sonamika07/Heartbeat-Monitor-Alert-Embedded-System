# Heartbeat Monitor with Alert System

## Project Overview

Heartbeat Monitor with Alert System is an Embedded Systems project developed using an ESP32 DevKit V1. The system monitors a simulated heartbeat signal, calculates the approximate heart rate in BPM (Beats Per Minute), displays the result, and activates visual and audio alerts when the BPM goes outside the configured demonstration range.

The project is implemented as a virtual embedded-system prototype using Wokwi because a physical pulse sensor may not be available during development.

## Objective

The main objectives of this project are:

- Monitor heartbeat-related signal data.
- Calculate approximate BPM.
- Display BPM and system status.
- Detect low and high BPM conditions.
- Activate a red LED and buzzer during an alert condition.
- Activate a green LED during the normal demonstration range.
- Demonstrate real-time embedded decision-making.
- Simulate the complete system virtually using Wokwi.
- Maintain proper project documentation and testing evidence on GitHub.

## Educational Disclaimer

This project is an educational Embedded Systems prototype.

It is NOT a medical diagnostic device and must NOT be used for medical decisions, emergency diagnosis, treatment, or patient monitoring.

The simulated/hobby-grade sensor approach may produce approximate readings. Actual clinical heart-rate interpretation depends on factors such as age, health condition, physical activity, medications, and other medical context.

The threshold values used in this project are demonstration/testing values only.

## Problem Statement

Continuous heart-rate monitoring is an important concept in healthcare, fitness, rehabilitation, and wearable technology.

A monitoring system needs to:

1. Acquire a heartbeat-related signal.
2. Process the signal using a microcontroller.
3. Calculate an approximate BPM value.
4. Compare the value with configured thresholds.
5. Display the current status.
6. Generate an alert when the value is outside the configured range.

This project demonstrates these concepts using an ESP32-based embedded system.

## Industry Relevance

The project demonstrates concepts commonly found in:

- Wearable fitness devices
- Smart watches
- Health monitoring prototypes
- Rehabilitation systems
- Sports monitoring systems
- Remote monitoring systems
- IoT healthcare prototypes

The technical concepts demonstrated include:

- Real-time sensor acquisition
- Analog signal processing
- BPM calculation
- Embedded decision logic
- GPIO control
- Display interfacing
- Alert generation
- Serial communication
- Virtual hardware simulation

## Hardware Components

The project uses the following components:

| Component | Quantity | Purpose |
|---|---:|---|
| ESP32 DevKit V1 | 1 | Main microcontroller |
| Potentiometer | 1 | Simulated heartbeat input in Wokwi |
| 16x2 LCD | 1 | Display BPM/status |
| Buzzer | 1 | Audio alert |
| Green LED | 1 | Normal status indication |
| Red LED | 1 | Alert indication |
| 220Ω Resistor | 2 | LED current limiting |

## Software and Tools

- Arduino IDE
- Wokwi Simulator
- Embedded C / Arduino C++
- Git
- GitHub

## System Architecture

```text
        Simulated Pulse Input
             (Potentiometer)
                    |
                    v
             ESP32 DevKit V1
                    |
          +---------+---------+
          |                   |
          v                   v
     BPM Calculation     Threshold Check
          |                   |
          v                   v
      16x2 LCD          Normal / Alert
                              |
                    +---------+---------+
                    |                   |
                    v                   v
                Green LED       Red LED + Buzzer

Working Principle

The system follows these steps:

The potentiometer is used as a simulated analog heartbeat input in Wokwi.
ESP32 reads the analog value through an ADC-capable GPIO.
The program processes the input signal.
A heartbeat-related event is detected using the programmed logic.
The time interval between detected beats is used for BPM calculation.
BPM is calculated using:
BPM = 60000 / Time Between Two Beats (milliseconds)
The calculated BPM is displayed on the 16x2 LCD.
The BPM value is compared with the configured demonstration thresholds.
If the BPM is within the demonstration normal range:
Green LED = ON
Red LED = OFF
Buzzer = OFF
If the BPM is below the low threshold:
Green LED = OFF
Red LED = ON
Buzzer = ON
If the BPM is above the high threshold:
Green LED = OFF
Red LED = ON
Buzzer = ON
BPM Calculation

The basic formula used is:
BPM = 60000 / Beat Interval in milliseconds
Examples:
Beat interval = 1000 ms
BPM = 60000 / 1000
BPM = 60

Beat interval = 750 ms
BPM = 60000 / 750
BPM = 80

Beat interval = 600 ms
BPM = 60000 / 600
BPM = 100

Multiple heartbeat intervals can be averaged to make the displayed BPM more stable.

Alert Logic

The project uses configurable demonstration thresholds.
BPM < LOW_THRESHOLD
        |
        +--> LOW
        +--> Red LED ON
        +--> Buzzer ON

LOW_THRESHOLD <= BPM <= HIGH_THRESHOLD
        |
        +--> NORMAL
        +--> Green LED ON
        +--> Buzzer OFF

BPM > HIGH_THRESHOLD
        |
        +--> HIGH
        +--> Red LED ON
        +--> Buzzer ON
The threshold values are software demonstration settings and are not clinical limits.

Circuit Connections
ESP32 to Potentiometer

The potentiometer is used as a simulated analog input in Wokwi.
Potentiometer VCC  -> ESP32 5V
Potentiometer GND  -> ESP32 GND
Potentiometer SIG  -> ESP32 GPIO 34

GPIO 34 is used as an analog input.

ESP32 to Buzzer
Buzzer Positive -> ESP32 GPIO 25
Buzzer Negative -> ESP32 GND
ESP32 to Green LED
ESP32 GPIO 26 -> 220Ω Resistor -> Green LED Anode
Green LED Cathode -> ESP32 GND
ESP32 to Red LED
ESP32 GPIO 27 -> 220Ω Resistor -> Red LED Anode
Red LED Cathode -> ESP32 GND
ESP32 to 16x2 LCD

For the I2C version of the 16x2 LCD:

LCD VCC -> ESP32 5V
LCD GND -> ESP32 GND
LCD SDA -> ESP32 GPIO 21
LCD SCL -> ESP32 GPIO 22

The I2C interface reduces the number of GPIO connections required for the display.

Pin Configuration
Component	ESP32 Pin
Potentiometer Signal	GPIO 34
Buzzer	GPIO 25
Green LED	GPIO 26
Red LED	GPIO 27
LCD SDA	GPIO 21
LCD SCL	GPIO 22
LCD VCC	5V
Common Ground	GND
Project Features
ESP32-based embedded system
Simulated heartbeat input
Analog signal acquisition
BPM calculation
Threshold-based monitoring
Normal status indication
Low BPM alert
High BPM alert
Green LED status
Red LED warning
Buzzer alert
16x2 LCD display
Serial Monitor output
Wokwi virtual simulation
Test result documentation
GitHub-ready project structure
Project Folder Structure
HEARTBEAT-MONITOR-ALERT-EMBEDDED-SYSTEM/
│
├── arduino_code/
│   └── heartbeat_monitor.ino
│
├── circuit_diagram/
│   └── 01_complete-circuit.png
│
├── data/
│   └── test-results.csv
│
├── screenshots/
│   ├── 01_complete-circuit.png
│   ├── 04_normal_bpm.png
│   ├── 05_low_bpm_alert.png
│   ├── 06_high_bpm_alert.png
│   ├── 07_serial_monitor.png
│   └── diag.png
│
├── simulation/
│   └── diagram.json
│
├── reports/
│   └── project-report.pdf
│
└── README.md
File Description
arduino_code/

Contains the main ESP32 Arduino source code.

heartbeat_monitor.ino

This file contains:

Sensor input handling
BPM calculation
Threshold comparison
LED control
Buzzer control
LCD output
Serial Monitor output
circuit_diagram/

Contains the complete circuit diagram of the project.

data/

Contains testing information and recorded test results.

test-results.csv
screenshots/

Contains visual proof of the project working in simulation.

Examples include:

Complete circuit
Normal BPM
Low BPM alert
High BPM alert
Serial Monitor
Diagnostic/output screenshots
simulation/

Contains the Wokwi simulation configuration.

diagram.json
reports/

Contains the complete project report in PDF format.

project-report.pdf
Virtual Simulation

The project is designed to be demonstrated using Wokwi.

Simulation Procedure
Open the Wokwi ESP32 project.
Add the ESP32 DevKit V1.
Add the potentiometer.
Add the 16x2 I2C LCD.
Add the buzzer.
Add the green LED.
Add the red LED.
Add two 220Ω resistors.
Complete the circuit connections.
Add the Arduino code.
Start the simulation.
Observe the LCD output.
Observe the LED status.
Observe the buzzer during alert conditions.
Open the Serial Monitor.
Test different simulated input conditions.
Testing

The system is tested under different conditions.

Test Case	Condition	Expected Result
Test 1	System startup	System initializes successfully
Test 2	No valid pulse	BPM is not treated as a valid heartbeat
Test 3	Normal simulated BPM	Green LED ON, buzzer OFF
Test 4	Low simulated BPM	Red LED ON, buzzer ON
Test 5	High simulated BPM	Red LED ON, buzzer ON
Test 6	Changing input	BPM/status updates
Test 7	Serial Monitor	BPM/status information displayed
Test 8	LCD	BPM/status displayed correctly
Expected Output
Normal Condition
BPM: 75
STATUS: NORMAL

Expected hardware behavior:

Green LED  -> ON
Red LED    -> OFF
Buzzer     -> OFF
Low BPM Alert
BPM: LOW
STATUS: ALERT

Expected hardware behavior:

Green LED  -> OFF
Red LED    -> ON
Buzzer     -> ON
High BPM Alert
BPM: HIGH
STATUS: ALERT

Expected hardware behavior:

Green LED  -> OFF
Red LED    -> ON
Buzzer     -> ON
Serial Monitor Example
Heartbeat Monitor Starting...
System Ready


BPM: 74
Status: NORMAL


BPM: 76
Status: NORMAL


BPM: 45
Status: LOW ALERT


BPM: 118
Status: HIGH ALERT

The exact output may vary depending on the simulated input and program logic.

Limitations
The project uses a simulated heartbeat input in Wokwi.
Hobby-grade sensors may produce approximate readings.
Electrical noise can affect signal detection.
Incorrect sensor placement can affect real sensor readings.
The system is not medically certified.
Threshold values are demonstration settings.
The prototype should not be used for diagnosis or treatment.
A real-world healthcare product would require validated sensors, signal processing, safety mechanisms, testing, regulatory compliance, and clinical validation.
Future Improvements

Possible future enhancements include:

MAX30102 optical heart-rate sensor
OLED display
Real pulse waveform visualization
Improved digital filtering
Moving-average BPM calculation
More robust peak detection
Data logging
SD card storage
Bluetooth monitoring
Wi-Fi monitoring
Mobile dashboard
Cloud data storage
Blynk integration
Remote alert notifications
Battery-powered wearable design
Low-power optimization
Enclosure and wearable design
Industry-Level Improvements

For a more advanced version, the system can be extended with:

MAX30102
   ↓
ESP32
   ↓
Signal Filtering
   ↓
Peak Detection
   ↓
BPM Calculation
   ↓
OLED Display
   ↓
Wi-Fi / Bluetooth
   ↓
Mobile / Cloud Dashboard

This would make the project closer to an IoT-based health monitoring prototype while still requiring appropriate validation before any real medical use.

Learning Outcomes

By completing this project, the following Embedded Systems concepts are demonstrated:

ESP32 microcontroller programming
Embedded C / Arduino programming
GPIO control
Analog input
ADC concept
Sensor interfacing
Signal processing basics
BPM calculation
Time-based event detection
Threshold comparison
LED control
Buzzer control
LCD interfacing
Serial communication
Virtual hardware simulation
Embedded-system testing
Git and GitHub workflow
Technical documentation
GitHub Proof of Work

The repository contains:

Complete source code
Circuit diagram
Wokwi simulation
Test results
Simulation screenshots
Project report
Documentation through README

This provides evidence of:

Project planning
Hardware design
Embedded programming
Simulation
Testing
Documentation
Version-control practice
Recommended Git Commit History

Example commits:

Initial project setup
Add ESP32 heartbeat monitoring code
Add circuit diagram
Add BPM calculation and alert logic
Add LCD display integration
Add Wokwi simulation
Add testing results
Add simulation screenshots
Add project report
Update README documentation
How to Run
Using Wokwi
Open the Wokwi ESP32 project.
Verify all components and connections.
Open heartbeat_monitor.ino.
Paste the project code.
Compile the program.
Start the simulation.
Change the potentiometer/input value.
Observe the BPM.
Verify normal and alert conditions.
Open Serial Monitor for additional output.
Using Real Hardware

For a future physical implementation:

Install Arduino IDE.
Select ESP32 DevKit V1.
Connect the required sensor and components.
Install required libraries.
Open heartbeat_monitor.ino.
Select the correct COM port.
Upload the program.
Open Serial Monitor.
Observe the output.
Test the system carefully.

The real hardware version should use an appropriate pulse sensor such as MAX30102 or another compatible sensor rather than relying on the Wokwi potentiometer simulation.

Screenshots Included

The repository includes screenshots showing:

Complete circuit
Normal BPM condition
Low BPM alert
High BPM alert
Serial Monitor output
Simulation/output evidence

These screenshots provide visual proof of the implementation and testing process.

Conclusion

The Heartbeat Monitor with Alert System demonstrates how an embedded microcontroller can acquire an input signal, process it, calculate an approximate BPM value, compare the result with configurable thresholds, display the status, and generate alerts.

The project combines hardware concepts, embedded programming, signal-processing basics, display interfacing, GPIO control, simulation, testing, and GitHub documentation into a single beginner-friendly Embedded Systems project.

Although this project is inspired by real healthcare and wearable monitoring applications, it remains an educational prototype and is not intended for medical diagnosis or clinical decision-making.

Author: Sonamika Anand Samrat

B.Tech – Computer Science and Engineering

Project Type: Embedded Systems Course Project

Platform: ESP32 + Wokwi

Repository: Heartbeat-Monitor-Alert-Embedded-System
Keywords
embedded-systems
arduino
esp32
heartbeat-monitor
pulse-sensor
bpm
biomedical
embedded-c
sensors
wokwi
lcd
iot
alert-system
