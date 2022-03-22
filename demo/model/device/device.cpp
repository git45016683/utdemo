/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:44:13
 * @LastEditTime: 2022-03-20 12:38:48
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\device\device.cpp
 */
#include "device.h"

device::device()
{
}

device::~device()
{
}

bool device::senddatatodevice(unsigned char* buff, int len)
{
    return true;
}

int device::receivedatafromdevice(unsigned char* receivedata)
{
    return 0;
}

char* device::requestdeviceinfo(int requesttype)
{
    char a[512];
    return a;
}

devicetype device::requestdevicetype()
{
    return noDevice;
}
