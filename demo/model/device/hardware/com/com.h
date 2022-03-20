/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:44:13
 * @LastEditTime: 2022-03-20 12:39:09
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\com\com.h
 */
#ifndef COM_H
#define COM_H
#include "hardware.h"

class com : public hardware
{
private:
    /* data */
public:
    com(/* args */);
    ~com();
    virtual bool senddata(unsigned char* buff, int len);
    virtual int receivedata(unsigned char* receivedata);
    virtual char* requestinfo(int requesttype);
    virtual devicetype requesttype();
};




#endif // COM_H
