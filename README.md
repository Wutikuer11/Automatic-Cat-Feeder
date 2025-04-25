# 🐱 Automatic Cat Feeder with Time Scheduling (Arduino)

This is a simple automatic cat feeder project using an Arduino, a servo motor, and a DS3231 Real-Time Clock (RTC) module. It dispenses food for your cat at a scheduled time every day.

## 🚀 Features
- Dispenses food at a specific time (e.g., 8:00 AM).
- Uses DS3231 RTC for accurate timekeeping.
- Uses a servo motor to rotate and drop food.
- Prevents multiple feedings within the same minute.

## 🧰 Hardware Required
- Arduino Uno (or compatible board)
- DS3231 RTC Module
- SG90 Servo Motor
- Jumper Wires
- Breadboard or soldered board
- Power supply (USB or battery pack)

## 🔧 Wiring Diagram

| Component      | Arduino Pin |
| -------------- | ----------- |
| Servo Signal   | D9          |
| Servo VCC      | 5V          |
| Servo GND      | GND         |
| RTC SDA        | A4 (Uno)    |
| RTC SCL        | A5 (Uno)    |
| RTC VCC        | 5V          |
| RTC GND        | GND         |

> Note: For boards other than Uno, check I2C pins.

## 💾 Installation
1. Install Arduino IDE: https://www.arduino.cc/en/software
2. Install required libraries via Library Manager:
   - `RTClib` by Adafruit
3. Upload the `cat_feeder.ino` sketch to your Arduino.

##

