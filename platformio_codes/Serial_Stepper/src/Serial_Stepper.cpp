#include "board_pinout.h"
#include "pitches.h"
#include "printer_translation.h"

/*
 * Serial Stepper
 * 
 * By Jonathan Kayne
 * April 2018
 * 
 * This program allows the user to input a MIDI pitch value through the serial monitor 
 * and runs that motor at the speed corresponding to that in the pitches.h file.
 * Use an instrument tuner to figure out what speed value is correct and put it in
 * the pitches.h file
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

#define TIMEOUT 10000 //Number of milliseconds for watchdog timer

unsigned long motorSpeed = 0;
unsigned long prevStepMicros = 0;
unsigned int midiNote = 0;
bool stepState = false;
const bool motorDirection = LOW;

// this is for the program to work.
// todo: change the program to enable choosing the motor on runtime
int stepPin = stepPin_M1;

void setup(){
  Serial.begin(SERIAL_DEBUG_SPEED);

  pinMode(stepPin_M1, OUTPUT);
  pinMode(stepPin_M2, OUTPUT);
  pinMode(stepPin_M3, OUTPUT);
  pinMode(stepPin_M4, OUTPUT);

  //Remove this comment if not using direction control /*
  pinMode(dirPin_M1, OUTPUT);
  pinMode(dirPin_M2, OUTPUT);
  pinMode(dirPin_M3, OUTPUT);
  pinMode(dirPin_M4, OUTPUT);
  digitalWrite(dirPin_M1, motorDirection);
  digitalWrite(dirPin_M2, motorDirection);
  digitalWrite(dirPin_M3, motorDirection);
  digitalWrite(dirPin_M4, motorDirection); //and this one too. */

  pin_enable_setup(); //setup enable pin / pins

  Serial.println("\nPlease Enter a Stepper MIDI number.");  
}

void loop() 
{
  if (motorSpeed == 0)
  {
    dis_en_steppers(true);
  }
  else
  {
    dis_en_steppers(false);
  }
  while(Serial.available() > 0) //taking in the speed value
  {
    midiNote = Serial.parseInt();
    motorSpeed = pitchVals[midiNote];
    Serial.print("MIDI Note entered: ");
    Serial.println(midiNote);
    Serial.print("motor Speed is: ");
    Serial.println(motorSpeed);
    Serial.println("\nPlease Enter a Stepper MIDI number.");
  }
  if ((micros() - prevStepMicros >= motorSpeed) && motorSpeed != 0)//stepper motor speed control
  {
    prevStepMicros += motorSpeed;
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin, LOW);
  }
}