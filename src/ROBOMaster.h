#ifndef INCLUDE_ROBOMASTER_H
#define INCLUDE_ROBOMASTER_H

# include "mbed.h"

namespace mbed
{
namespace lib_ygdstmidn
{
namespace ROBOMaster
{

class ROBOMaster
{
    private:
        int16_t motor_output[8];
    public:
        /**
         * ロボマスモータを使うためのインスタンスを作成します．
         * 
        */
        ROBOMaster();
        ~ROBOMaster();
};//class ROBOMaster

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed

#endif