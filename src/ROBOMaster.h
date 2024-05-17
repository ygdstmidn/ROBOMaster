#ifndef INCLUDE_ROBOMASTER_H
#define INCLUDE_ROBOMASTER_H

#define DEVICE_CAN 1
#include "mbed.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace ROBOMaster
{

#define ROBOMAS_BAUDRATE        1*1000*1000
#define ROBOMAS_OUTPUT_MAX      1*100*100
#define ROBOMAS_OUTPUT_MIN      -1*100*100
#define ROBOMAS_ADDRESS_1       0X200
#define ROBOMAS_ADDRESS_2       0X1FF

union ROBOMAS_OUTPUT
{
    int16_t speed_data;
    int8_t  send_data[2];
};


class ROBOMaster
{
    private:
        CAN *can_bus;
        int16_t motor_output[8];
    public:
        /**
         * ロボマスモータを使うためのインスタンスを作成します．
         * @param rd read from transmitter
         * @param td transmit to transmitter
        */
        ROBOMaster(PinName rd,PinName td);

        /**
         * ロボマスモータを使うためのインスタンスを作成します．
         * @param pinmap reference to structure which holds static pinmap
         * @param td the transmit pin
         * @param hz the bus frequency in hertz
         */
        ROBOMaster(const can_pinmap_t &pinmap);
        ROBOMaster(const can_pinmap_t &&) = delete; // prevent passing of temporary objects

        ~ROBOMaster();

        void set_speed(int motor_no,int16_t speed);

        void write();
};//class ROBOMaster

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed

#endif