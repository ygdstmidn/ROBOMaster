/**
 * 使用例です．
 * 自由に使ってね．
 * 使用したマイコン:NUCLEO-F303K8
 * ロボマスモータを一つ繋げ，IDを1にセットして動作しました．
*/

#if(0)

#include "mbed.h"
#include "ROBOMaster.h"

#define PC_BAUDRATE 115200
#define CAN_RD PA_11
#define CAN_TD PA_12
#define CONNECTED_MOTOR 1

UnbufferedSerial pc(USBTX,USBRX,PC_BAUDRATE);
ROBOMaster myrobomas(CAN_RD,CAN_TD);

char pcSendStringData[64];
size_t pcSendStringLength;

int main()
{
	pc.write("3\n",2);
    wait_us(1*1000*1000);
    pc.write("2\n",2);
    wait_us(1*1000*1000);
    pc.write("1\n",2);
    wait_us(1*1000*1000);
    pc.write("start\n",6);
	while(1)
	{
		for(int16_t i=500;i<=10000;i+=10)
        {
            myrobomas.set_speed(CONNECTED_MOTOR,i);
            //pcに送るデータ
            if(myrobomas.write())
            {
                pcSendStringLength = snprintf(pcSendStringData,64,"[  OK  ],%d\n",i);
            }else
            {
                pcSendStringLength = snprintf(pcSendStringData,64,"[FAILED],%d\n",i);
            }
            pc.write(pcSendStringData, pcSendStringLength); 
            //200ms待つ
            wait_us(200 * 1000);
        }
	}
}

#endif