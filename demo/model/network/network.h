/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:49:01
 * @LastEditTime: 2022-03-24 05:59:41
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\network\network.h
 */
#ifndef NETWORK_H
#define NETWORK_H
#include <string>
using std::string;

class simulateSocket
{
public:
    simulateSocket(){}
    virtual ~simulateSocket(){}
    virtual int send(unsigned char* buff) = 0;
    virtual void recv(unsigned char* buff, int& len) = 0;
};


class network: public simulateSocket
{
private:

public:
    network();
    ~network();
    virtual int send(unsigned char* buff);
    virtual void recv(unsigned char* buff, int& len);

    int requestUrl(string url, unsigned char* data);
};



#endif // NETWORK_H
