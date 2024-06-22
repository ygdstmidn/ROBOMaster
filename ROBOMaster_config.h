#ifndef INCLUDE_ROBOMASTER_CONFIG_H
#define INCLUDE_ROBOMASTER_CONFIG_H

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
#define ROBOMAS_ADDRESS_READ    0X200

}//namespace ROBOMaster
}//namespace lib_ygdstmidn
}//namespace mbed

#endif