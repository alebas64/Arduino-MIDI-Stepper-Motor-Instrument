#include "board_pinout.h"
#include "printer_translation.h"

/*
Stepper Test
By: Jonathan Kayne
April 2018

Use this code to make sure that your stepper motors are wired up
properly to the A4988 drivers. 
Pin are set up for the Arduino CNC Shield V3 (X-axis)
so change them to match the correct wiring you use.
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

const int Time_1      = 500; //duration between pulses
const int Time_2      = 500;
const long int step_1 = 10000; //steps per revolution
const long int step_2 = 10000;
unsigned int do_it_again = 0, end_loop = 0;

void setup(){
  Serial.begin(SERIAL_DEBUG_SPEED);

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
}

void loop(){
  digitalWrite(enPin, LOW);
  Serial.println("First test");
  digitalWrite(dirPin, HIGH);

  for (long int i = 0; i < step_1; i++)
  {
    digitalWrite(stepPin, HIGH);
    //delayMicroseconds(Time_1);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Time_1);
  }
  Serial.println("end first test");
  delay(2000);
  Serial.println("Second test");
  digitalWrite(dirPin, LOW);
  for (long int i = 0; i < step_2; i++)
  {
    digitalWrite(stepPin, HIGH);
    //delayMicroseconds(Time_2);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(Time_2);
  }

  digitalWrite(enPin, HIGH);
  Serial.println("end second test");
  //stop loop
  Serial.print("You wanna do the tests again? \n1 SPIIIIIN AGAAAAAAIN!, 0 NAHHH LET ME SLEEEEEEEP: ");
  while(!end_loop){
    while(Serial.available() > 0 && !end_loop){
      do_it_again = Serial.parseInt();
      Serial.print("\nYou chose: ");Serial.println(do_it_again);
      if(do_it_again == 1){
        end_loop = 1;
        do_it_again = 0;
      }
    }
  }  
  end_loop= 0;
  Serial.println("OKAY LET'S GO");
}