/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:44:13
 * @LastEditTime: 2022-03-20 12:38:52
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\hardware\hardware.h
 */
#ifndef HARDWARE_H
#define HARDWARE_H

enum devicetype
{
    noDevice = 0,
    comDevice = 1,
    usbDevice = 2
};

class hardware
{
private:
    /* data */
public:
    hardware(/* args */){}
    ~hardware(){}
    virtual bool senddata(unsigned char* buff, int len) = 0;
    virtual int receivedata(unsigned char* receivedata) = 0;
    virtual char* requestinfo(int requesttype) = 0;
    virtual devicetype requesttype() = 0;
};




#endif // HARDWARE_H
