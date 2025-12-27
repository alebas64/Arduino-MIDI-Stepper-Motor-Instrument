#define TRONXY

#ifdef TRONXY
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT

    #define STEPPER_X_STEP (15) //PD7
    #define STEPPER_X_DIR (21) //PC5
    #define STEPPER_X_EN (18) //PC2

    #define STEPPER_Y_STEP 22 //PC6
    #define STEPPER_Y_DIR 23 //PC7
    #define STEPPER_Y_EN 14 //PD6

    #define STEPPER_Z_STEP 3 //PB3
    #define STEPPER_Z_DIR 2 //PB2
    #define STEPPER_Z_EN 14 //PD6

    #define STEPPER_E0_STEP PB1
    #define STEPPER_E0_DIR PB0
    #define STEPPER_E0_EN 14 //PD6
  #endif
#endif

#ifdef CREALITY_V25
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT

    #define STEPPER_X_STEP PD7
    #define STEPPER_X_DIR PC5
    #define STEPPERX_EN PC2

    #define STEPPER_Y_STEP PC6
    #define STEPPER_Y_DIR PC7
    #define STEPPER_Y_EN PD6

    #define STEPPER_Z_STEP PB3
    #define STEPPER_Z_DIR PB2
    #define STEPPER_Z_EN PD6

    #define STEPPER_E0_STEP PB1
    #define STEPPER_E0_DIR PB0
    #define STEPPER_E0_EN PD6
  #endif
#endif

#ifdef CREALITY_V114
  #ifndef MAINBOARD3DPINOUT
    #define MAINBOARD3DPINOUT

    #define STEPPER_X_STEP PD7
    #define STEPPER_X_DIR PC5
    #define STEPPERX_EN PC2

    #define STEPPER_Y_STEP PC6
    #define STEPPER_Y_DIR PC7
    #define STEPPER_Y_EN PD6

    #define STEPPER_Z_STEP PB3
    #define STEPPER_Z_DIR PB2
    #define STEPPER_Z_EN PD6

    #define STEPPER_E0_STEP PB1
    #define STEPPER_E0_DIR PB0
    #define STEPPER_E0_EN PD6
  #endif
#endif