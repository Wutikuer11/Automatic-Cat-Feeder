#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

RTC_DS3231 rtc;
Servo feederServo;

// Set feeding time (24-hour format)
const int feedHour = 8;  // Feed at 8 AM
const int feedMinute = 0;

bool hasFed = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting time to compile time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  feederServo.attach(9); // Connect servo to pin 9
  feederServo.write(0);  // Start at 0 degrees

  Serial.println("Cat feeder ready!");
}

void loop() {
  DateTime now = rtc.now();

  Serial.print("Current Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());

  if (now.hour() == feedHour && now.minute() == feedMinute && !hasFed) {
    dispenseFood();
    hasFed = true;
  }

  // Reset hasFed flag after the minute passes
  if (now.minute() != feedMinute) {
    hasFed = false;
  }

  delay(1000); // Check every second
}

void dispenseFood() {
  Serial.println("Dispensing food...");
  feederServo.write(90);  // Turn servo to open position
  delay(1000);            // Wait for food to drop
  feederServo.write(0);   // Return to closed position
  Serial.println("Feeding done.");
}
