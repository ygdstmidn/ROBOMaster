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
                motor_output[motor_no-1]=speed;
            }
        }
    }

    void ROBOMaster::write()
    {
        can_bus->write(CANMessage(ROBOMAS_ADDRESS_1,));
    }

} // namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed