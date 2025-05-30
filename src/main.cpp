/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/
#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo

#define potpin  0  // analog pin used to connect the potentiometer

//declaration des variables
int val;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(115200);
  myservo.attach(27);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);           // reads the value of the potentiometer (value between 0 and 4095)
  val = map(val, 0, 4095, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}

