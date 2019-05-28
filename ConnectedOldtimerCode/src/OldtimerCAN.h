#ifndef __OldtimerCAN_h
#define __OldtimerCAN_h
#include "stdio.h"

typedef struct oldtimermotor {
   uint8_t fuelLevel;
    uint16_t motorTemperature;
    uint16_t motorRPM;
} OldtimerValues;


void canReceive(OldtimerValues* ot);

#endif