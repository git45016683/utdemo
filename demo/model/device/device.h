/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:44:13
 * @LastEditTime: 2022-03-24 04:38:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\device\device.h
 */
#ifndef DEVICE_H
#define DEVICE_H
#include <string>
#include "com.h"
#include "usb.h"

using std::string;

class device
{
private:
    string _serialno;
    string _version;
    string _firewareversion;
    devicetype _type;
    hardware* _phardware;
public:
    device();
    ~device();

    bool senddatatodevice(unsigned char* buff, int len);
    int receivedatafromdevice(unsigned char* receivedata);
    char* requestdeviceinfo(int requesttype);
    devicetype requestdevicetype();
};




#endif // DEVICE_H
