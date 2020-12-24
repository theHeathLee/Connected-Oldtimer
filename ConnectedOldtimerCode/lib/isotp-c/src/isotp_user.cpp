#include "isotp_user.h"
//#include <spark_wiring.h>
#include <Particle.h>
//#include <stdlib.h>
#include <stdint.h>
//#ifdef __cplusplus
//extern "C" {
//#endif
//iso-tp shims
   int  isotp_user_send_can(const uint32_t arbitration_id,
                             const uint8_t* data, const uint8_t size) {
        CANChannel can(CAN_C4_C5);
        CANMessage messageIsoTp;
        messageIsoTp.id = arbitration_id;
        //messageIsoTp.data = *data;
        //uint8_t txData[8];
        //uint8_t txData[8]= {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
        *messageIsoTp.data = *data;
        messageIsoTp.size = size;
        can.transmit(messageIsoTp); 
        
        return 1;
    }

    /* required, return system tick, unit is millisecond */
    uint32_t isotp_user_get_ms(void) {
        return (uint32_t)GetSystem1MsTick();
    }

void isotp_user_debug(const char* message, ...)
{
    //empty function
}
//#ifdef __cplusplus
//}
//#endif