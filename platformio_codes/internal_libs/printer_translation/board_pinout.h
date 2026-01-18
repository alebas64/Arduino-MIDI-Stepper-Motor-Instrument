//USE "SANGUINO" pinout!!!!
#ifndef BOARD_PINOUT_H
#define BOARD_PINOUT_H

#ifdef TRONXY
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT
    #define X_STEP_PIN                            15 //PD7
    #define X_DIR_PIN                             21 //PC5
    #define X_ENABLE_PIN                          14 //PD6

    #define Y_STEP_PIN                            22 //PC6 
    #define Y_DIR_PIN                             23 //PC7
    #define Y_ENABLE_PIN                          14 //PD6
  
    #define Z_STEP_PIN                             3 //PB3
    #define Z_DIR_PIN                              2 //PB2
    #define Z_ENABLE_PIN                          14 //PD6
  
    #define E0_STEP_PIN                            1 //PD6
    #define E0_DIR_PIN                             0 //PB0 
    #define E0_ENABLE_PIN                         14 //PD6
  
  #endif
#endif

#ifdef CREALITY_V25
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT
    #define X_STEP_PIN                            54 //PF0
    #define X_DIR_PIN                             55 //PF1
    #define X_ENABLE_PIN                          38 //PD7

    #define Y_STEP_PIN                            60 //PF6 
    #define Y_DIR_PIN                             61 //PF7
    #define Y_ENABLE_PIN                          56 //PF2
  
    #define Z_STEP_PIN                            46 //PL3
    #define Z_DIR_PIN                             48 //PL1
    #define Z_ENABLE_PIN                          62 //PK0
  
    #define E0_STEP_PIN                           26 //PA4
    #define E0_DIR_PIN                            28 //PA6 
    #define E0_ENABLE_PIN                         24 //PA2
    #define MIDI_SERIAL_PORT Serial2
    #define MIDI_SERIAL_TYPE HardwareSerial
  #endif
#endif

#ifdef CREALITY_V114
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT
    #define X_STEP_PIN                            15 //PD7
    #define X_DIR_PIN                             21 //PC5
    #define X_ENABLE_PIN                          14 //PD6

    #define Y_STEP_PIN                            22 //PC6 
    #define Y_DIR_PIN                             23 //PC7
    #define Y_ENABLE_PIN                          14 //PD6
  
    #define Z_STEP_PIN                             3 //PB3
    #define Z_DIR_PIN                              2 //PB2
    #define Z_ENABLE_PIN                          26 //PA5
  
    #define E0_STEP_PIN                            1 //PD6
    #define E0_DIR_PIN                             0 //PB0
    #define E0_ENABLE_PIN                         14 //PD6
    
  #endif
#endif

#ifdef ARDUINO_CNC_SHIELD_V3
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT
    #define X_STEP_PIN                             2
    #define X_DIR_PIN                              5
    #define X_ENABLE_PIN                           8

    #define Y_STEP_PIN                             3
    #define Y_DIR_PIN                              6
    #define Y_ENABLE_PIN                           8
  
    #define Z_STEP_PIN                             4
    #define Z_DIR_PIN                              7 
    #define Z_ENABLE_PIN                           8
  
    #define E0_STEP_PIN                           12 
    #define E0_DIR_PIN                            13 
    #define E0_ENABLE_PIN                          8
    
  #endif
#endif

#ifdef CUSTUM_ARDUINO_BOARD
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT
    #define X_STEP_PIN                             2
    #define X_DIR_PIN                              5
    #define X_ENABLE_PIN                           8

    #define Y_STEP_PIN                             3
    #define Y_DIR_PIN                              6
    #define Y_ENABLE_PIN                           8
  
    #define Z_STEP_PIN                             4
    #define Z_DIR_PIN                              7 
    #define Z_ENABLE_PIN                           8
  
    #define E0_STEP_PIN                           12 
    #define E0_DIR_PIN                            13 
    #define E0_ENABLE_PIN                          8
    #define MIDI_SERIAL_PORT Serial2
    #define MIDI_SERIAL_TYPE HardwareSerial
  #endif
#endif

#endif