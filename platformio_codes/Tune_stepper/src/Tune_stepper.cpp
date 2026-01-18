#include "board_pinout.h"
#include "printer_translation.h"

/*
 * TuneStepper
 * 
 * By Jonathan Kayne
 * April 2018
 * 
 * This program allows the user to input a speed value through the serial monitor 
 * and runs that motor at that speed.
 * You should compare the sound with the value on the pitches.h file
 * and check for the resonant frequency of your stepper. 
 * The resonant frequency will cause the motor to produce a garbled tone.
 * It will appear as if the motor has stalled. If this happens, raise/lower the pitch value
 * by an octave.
 */

//ARDUINO PINS
#define stepPin_M1 X_STEP_PIN
#define stepPin_M2 Y_STEP_PIN
#define stepPin_M3 Z_STEP_PIN
#define stepPin_M4 E0_STEP_PIN

//note that Direction Pins aren't necessary
//comment out if you don't plan on using them
#define dirPin_M1 X_DIR_PIN
#define dirPin_M2 Y_DIR_PIN
#define dirPin_M3 Z_DIR_PIN
#define dirPin_M4 E0_DIR_PIN

//? Note: EN pins are in separate header file now

// this is for the program to work.
// todo: change the program to enable choosing the motor on runtime
#define stepPin (X_STEP_PIN)
#define dirPin (X_DIR_PIN)
#define enPin (X_ENABLE_PIN)

unsigned long motorSpeed = 0;
unsigned long prevStepMicros = 0;
bool stepState = false;

void setup(){
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(dirPin, LOW);

  Serial.begin(SERIAL_DEBUG_SPEED);
  while(!Serial) {/*do nothing*/;}

  Serial.println("\n\nPlease Enter a Stepper Motor Speed Value.");
}

//? it does appear that it does nothing...?
void loop(){
  if (motorSpeed == 0)
  {
    digitalWrite(enPin, HIGH);
  }
  else
  {
    digitalWrite(enPin, LOW);
  }
  while(Serial.available() > 0) //taking in the speed value
  {
    motorSpeed = Serial.parseInt();
    Serial.print("Stepper Motor Speed set to: ");
    Serial.println(motorSpeed);
    Serial.println("\nPlease Enter a Stepper Motor Speed Value.");
  }
  if ((micros() - prevStepMicros >= motorSpeed) && motorSpeed != 0)//stepper motor speed control
  {
    prevStepMicros += motorSpeed;
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin, LOW);
  }
}