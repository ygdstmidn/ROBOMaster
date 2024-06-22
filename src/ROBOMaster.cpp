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
        return//2つwriteする．どちらも成功すると1，どちらか一方が失敗すると0．
        (can_bus->write(CANMessage(ROBOMAS_ADDRESS_1,&motor_output[0],8)))*
        (can_bus->write(CANMessage(ROBOMAS_ADDRESS_2,&motor_output[8],8)));
    }//この書き方がキモイことは分かってるんですが，これで動いてるので許してください．

    int ROBOMaster::read()
    {
        while(can_bus->read(readbox))
        {
            int id = readbox.id-ROBOMAS_ADDRESS_READ;
            read_data[id].kikaikaku=(readbox.data[0]<<8)|readbox.data[1];
            read_data[id].sokudo=(readbox.data[2]<<8)|readbox.data[3];
            read_data[id].toruku=(readbox.data[4]<<8)|readbox.data[5];
        }
        return 0;
    }

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed