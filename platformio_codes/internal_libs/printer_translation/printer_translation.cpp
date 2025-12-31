#include "printer_translation.h"

void pin_enable_setup(){
    #ifdef TRONXY
    pinMode(X_ENABLE_PIN, OUTPUT);
    #elif defined(CREALITY_V25)
    pinMode(X_ENABLE_PIN, OUTPUT);
    pinMode(Y_ENABLE_PIN, OUTPUT);
    pinMode(Z_ENABLE_PIN, OUTPUT);
    pinMode(E0_ENABLE_PIN, OUTPUT);
    #elif defined(CREALITY_V114)
    pinMode(X_ENABLE_PIN, OUTPUT);
    pinMode(Z_ENABLE_PIN, OUTPUT);
    #elif defined(ARDUINO_CNC_SHIELD_V3)
    pinMode(X_ENABLE_PIN, OUTPUT);
    #elif defined(CUSTUM_ARDUINO_BOARD)
    pinMode(X_ENABLE_PIN, OUTPUT);
    #endif
    
}

void dis_en_steppers(bool disable_stepper){
    #ifdef TRONXY
    digitalWrite(X_ENABLE_PIN, disable_stepper);
    #elif defined(CREALITY_V25)
    digitalWrite(X_ENABLE_PIN, disable_stepper);
    digitalWrite(Y_ENABLE_PIN, disable_stepper);
    digitalWrite(Z_ENABLE_PIN, disable_stepper);
    digitalWrite(E0_ENABLE_PIN, disable_stepper);
    #elif defined(CREALITY_V114)
    digitalWrite(X_ENABLE_PIN, disable_stepper);
    digitalWrite(Z_ENABLE_PIN, disable_stepper);
    #elif defined(ARDUINO_CNC_SHIELD_V3)
    digitalWrite(X_ENABLE_PIN, disable_stepper);
    #elif defined(CUSTUM_ARDUINO_BOARD)
    digitalWrite(X_ENABLE_PIN, disable_stepper);
    #endif
}