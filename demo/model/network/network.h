/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:49:01
 * @LastEditTime: 2022-03-20 12:39:29
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\network\network.h
 */
#ifndef NETWORK_H
#define NETWORK_H
#include <string>
using std::string;

class network
{
private:

public:
    network();
    ~network();

    int requestUrl(string url, unsigned char* data);
};



#endif // NETWORK_H
