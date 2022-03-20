/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:42:02
 * @LastEditTime: 2022-03-20 14:09:21
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\model\model.h
 */
#ifndef MODEL_H
#define MODEL_H
#include "device.h"
#include "network.h"

int findFirstSemicolon(char* buff, int len);

class model
{
private:
    device* _pdevice;
    network* _pnetwork;
public:
    model();
    ~model();

    void printmodelinfo();
    void printmodelverion();
    void printmodeldeviceinfo();
    void printmodeldeviceversion();
    void printmodeldeviceserial();
    void printallinfo();
    
    bool showImg();
    bool showData();
    bool IsPrime(int n);
};



#endif // MODEL_H
