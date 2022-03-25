/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:42:02
 * @LastEditTime: 2022-03-25 02:07:31
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\model\model.h
 */
#ifndef MODEL_H
#define MODEL_H
#include "device.h"
#include "network.h"

 #ifdef UT
 #define protected public
 #define private public
 #endif  // UT


int findFirstSemicolon(char* buff, int len);

class model
{
private:
    device* _pdevice;
    network* _pnetwork;
public:
    model();
    ~model();
    
    void setNetwork(network* nw){_pnetwork = nw;}
    void printmodelinfo();
    void printmodelverion();
    void printmodeldeviceinfo();
    void printmodeldeviceversion();
    void printmodeldeviceserial();
    void printallinfo();
    
    bool showImg();
    bool showData();
    bool IsPrime(int n);
    void hardwardResponse();

private:
    int Factorial(int n);

private:
    int m_iHardwareErrCode;  // 硬件错误码 正常为0，错误为负数
    unsigned char m_aRecvResponse[1024];  // 硬件错误码 正常为0，错误为负数
public:
    void setHardwardCode(int iCode) {m_iHardwareErrCode = iCode;}
    int getHardwardCode() {return m_iHardwareErrCode;}
    unsigned char* getResponseData() {return m_aRecvResponse;}
};



#endif // MODEL_H
