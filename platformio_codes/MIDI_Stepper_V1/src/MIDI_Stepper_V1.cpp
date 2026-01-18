#include "MIDI.h"
//#include "MIDIUSB.h"
#include "board_pinout.h"
#include "pitches.h"
#include "printer_translation.h"

/*
 * MIDI STEPPER V1
 * 
 * By Jonathan Kayne / jzkmath
 * April 2018
 * https://github.com/jzkmath/Arduino-MIDI-Stepper-Motor-Instrument
 * 
 * Takes MIDI data and converts it to stepper music!
 * Since the steppers only need to spin in one direction,
 * you only need to control the STEP pin on the A4988 driver
 * and pull DIR to either 5V or GND.
 * You can add more stepper motors to the sketch by specifying more pins
 * and expanding the array.
 * I also tried to put plenty of comments so that you can understand the code
 * and possibly be able to use it or part of it in other projects!
 */

//ARDUINO PINS
//configured for CNC Shield V3
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

//The index corresponds to the MIDI channel/Motor number being used. Index 0 is not used.
unsigned long motorSpeeds[] = {0, 0, 0, 0, 0}; //holds the speeds of the motors. 
unsigned long prevStepMicros[] = {0, 0, 0, 0, 0}; //last time
const bool motorDirection = LOW; //you can use this to change the motor direction, comment out if you aren't using it.
bool disableSteppers = HIGH; //status of the enable pin. disabled when HIGH. Gets enabled when the first note on message is received.
unsigned long WDT; //Will store the time that the last event occured.

//MIDI_CREATE_DEFAULT_INSTANCE(); //use default MIDI settings
//! FOR NOW, ONLY WORK WITH CREALITY_V25
MIDI_CREATE_INSTANCE(MIDI_SERIAL_TYPE, MIDI_SERIAL_PORT, MIDI);

void singleStep(byte motorNum, byte stepPin);
void handleNoteOn(byte channel, byte pitch, byte velocity);
void handleNoteOff(byte channel, byte pitch, byte velocity);

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

  MIDI.begin(MIDI_CHANNEL_OMNI); //listen to all MIDI channels
  MIDI.setHandleNoteOn(handleNoteOn); //execute function when note on message is recieved
  MIDI.setHandleNoteOff(handleNoteOff); //execute function when note off message is recieved
}

void loop() 
{
  MIDI.read(); //read MIDI messages

  // for MIDI over USB
  /*
  midiEventPacket_t rx = MidiUSB.read();
  switch (rx.header) {
    case 0:
      break; //No pending events
      
    case 0x9:
      handleNoteOn(
        rx.byte1 & 0xF,  //channel
        rx.byte2,        //pitch
        rx.byte3         //velocity
      );
      break;
      
    case 0x8:
      handleNoteOff(
        rx.byte1 & 0xF,  //channel
        rx.byte2,        //pitch
        rx.byte3         //velocity
      );
      break;
      
    case 0xB:
      //controlChange(
      //  rx.byte1 & 0xF,  //channel
      //  rx.byte2,        //control
      //  rx.byte3         //value
      //);
      break;
      
    default:
      //unhandled message
      break;
    }
  */

  dis_en_steppers(disableSteppers); //choose whether to enable or disable steppers.
  singleStep(1, stepPin_M1); //run each stepper at specified speed
  singleStep(2, stepPin_M2);
  singleStep(3, stepPin_M3);
  singleStep(4, stepPin_M4);

  if (millis() - WDT >= TIMEOUT)
  {
    disableSteppers = HIGH; //When the time has elapsed, disable the steppers
  }
}

void handleNoteOn(byte channel, byte pitch, byte velocity) //MIDI Note ON Command
{
  disableSteppers = LOW; //enable steppers. 
  motorSpeeds[channel] = pitchVals[pitch]; //set the motor speed to specified pitch
  /*
   * something that you could potentially do is have a grid of steppers
   * and use the velocity value to determine the number of steppers in each
   * collumn should be turned on. Each collumn would have its own MIDI channel.
   * The floppotron essentially does this...
   */
}

void handleNoteOff(byte channel, byte pitch, byte velocity) //MIDI Note OFF Command
{
  motorSpeeds[channel] = 0; //set motor speed to zero
}

void singleStep(byte motorNum, byte stepPin)
{
  if ((micros() - prevStepMicros[motorNum] >= motorSpeeds[motorNum]) && (motorSpeeds[motorNum] != 0)) 
  { //step when correct time has passed and the motor is at a nonzero speed
    prevStepMicros[motorNum] += motorSpeeds[motorNum];
    WDT = millis(); //update watchdog timer
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin, LOW);
  }
}
