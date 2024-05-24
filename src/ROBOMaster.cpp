#include "ROBOMaster.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace ROBOMaster
{
    ROBOMaster::ROBOMaster(PinName rd, PinName td)
    {
        can_bus=new CAN(rd,td,ROBOMAS_BAUDRATE);
    }

    ROBOMaster::ROBOMaster(const can_pinmap_t &pinmap)
    {
        can_bus=new CAN(pinmap,ROBOMAS_BAUDRATE);
    }

    ROBOMaster::~ROBOMaster()
    {
    }

    void ROBOMaster::set_speed(int motor_no, int16_t speed)
    {
        if(1<=motor_no&&motor_no<=8)
        {
            if (ROBOMAS_OUTPUT_MIN<=speed&&speed<=ROBOMAS_OUTPUT_MAX)
            {
                motor_output[motor_no*2-2]=(speed&0XFF00)>>8;
                motor_output[motor_no*2-1]=(speed&0X00FF);
            }
        }
    }

    int ROBOMaster::write()
    {
        return
        (can_bus->write(CANMessage(ROBOMAS_ADDRESS_1,&motor_output[0],8)))*
        (can_bus->write(CANMessage(ROBOMAS_ADDRESS_2,&motor_output[8],8)));
    }

    int ROBOMaster::read()
    {
        int i=0;
        while(can_bus->read(*readbox))
        {
            i++;
        }
        return readbox->len;
    }

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed