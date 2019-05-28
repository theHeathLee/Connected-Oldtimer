#include "OldtimerCAN.h"

void canReceive(OldtimerValues* ot){
  
  CANMessage message;

  switch (message.id)
  {
  case 0x100:
    ot->motorTemperature = message.data[0];
    break;
  case 0x200:
    ot->motorRPM = message.data[0];
  case 0x300:
    ot->fuelLevel = message.data[0];
  default:
    break;
  }

  
}  