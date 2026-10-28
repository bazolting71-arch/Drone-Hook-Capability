// Drone payload hook - servo test
// Closed = 0 deg (hook hanging straight down, keeper closes the mouth)
// Open   = 90 deg (hook swings sideways, mouth facing down, load drops)
//
// Arduino Nano: uses <Servo.h>, signal on D6.
// ESP32: install the ESP32Servo library, change the include to
//        #include <ESP32Servo.h> and use a PWM pin such as GPIO 13.
//
// Power the servo from its own 5-6 V, 3 A+ supply (BEC or buck converter).
// Join the servo supply ground to the controller ground.

#include <Servo.h>

Servo hook;

const int SERVO_PIN = 6;
const int CLOSED = 0;   // if your servo turns the hook toward the keeper, use 180
const int OPEN   = 90;  // and keep this at 90 (try 100 if the load doesn't drop)

void setup() {
  hook.attach(SERVO_PIN);
  hook.write(CLOSED);
  delay(3000);
  hook.write(OPEN);
  delay(3000);
  hook.write(CLOSED);
}

void loop() {}
