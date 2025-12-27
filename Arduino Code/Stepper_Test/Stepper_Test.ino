/*
Stepper Test
By: Jonathan Kayne
April 2018

Use this code to make sure that your stepper motors are wired up
properly to the A4988 drivers. 
Pin are set up for the Arduino CNC Shield V3 (X-axis)
so change them to match the correct wiring you use.
*/
#define X_STEP_PIN                             26 //PB1
    #define X_DIR_PIN                          28 //PB0
    #define X_ENABLE_PIN                       24 //PD6


#define stepPin (X_STEP_PIN)
#define dirPin (X_DIR_PIN)
#define enPin (X_ENABLE_PIN)

const int Time_1 = 80; //duration between pulses
const int Time_2 = 80;
const long int step_1 = 10000; //steps per revolution
const long int step_2 = 50000;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
  Serial.begin(115200);
}

void loop() {
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
  while(1); //stop loop 

}
