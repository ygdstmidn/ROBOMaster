#ifndef INCLUDE_ROBOMASTER_H
#define INCLUDE_ROBOMASTER_H

#define DEVICE_CAN 1//ソースコードに赤文字が出ちゃうので
#include "mbed.h"
#include "ROBOMaster_config.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace ROBOMaster
{

class ROBOMaster
{
    private:
        CAN *can_bus;
        char motor_output[16];
        CANMessage  *readbox=new CANMessage();
    public:
        /**
         * ロボマスモータを使うためのインスタンスを作成します．
         * @param rd read from transmitter (TDピン)
         * @param td transmit to transmitter (RDピン)
        */
        ROBOMaster(PinName rd,PinName td);

        /**
         * ロボマスモータを使うためのインスタンスを作成します．
         * @param pinmap reference to structure which holds static pinmap
         */
        ROBOMaster(const can_pinmap_t &pinmap);
        ROBOMaster(const can_pinmap_t &&) = delete; // prevent passing of temporary objects

        ~ROBOMaster();

        /**
         * ロボマスモータの制御電流値を設定します．
         * @param motor_no 設定するモータ番号(1～8)
         * @param speed    設定したい制御電流値(-10000～10000)
        */
        void set_speed(int motor_no,int16_t speed);

        /**
         * ロボマスモータにCANでデータを送ります．
         * @return 
         * 0 if write failed (失敗),
         * 1 if write was successful (成功)
        */
        int write();

        int read();
};//class ROBOMaster

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed

using namespace mbed::lib_ygdstmidn::ROBOMaster;

#endif