#include "isotp_user.h"
#include <spark_wiring_can.h>
#include <stdint.h>

//iso-tp shims
   int  isotp_user_send_can(const uint32_t arbitration_id,
                             const uint8_t* data, const uint8_t size) {
        CANMessage messageIsoTp;
        messageIsoTp.id = arbitration_id;
        messageIsoTp.data = *data;
        messageIsoTp.size = size;
        can.transmit(messageIsoTp); 
        return 1;
    }

    /* required, return system tick, unit is millisecond */
    uint32_t isotp_user_get_ms(void) {
        return GetSystem1MsTick();
    }