/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:49:01
 * @LastEditTime: 2022-03-24 05:59:56
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\student\network\network.cpp
 */
#include "network.h"


network::network()
{
}

network::~network()
{
}

int network::send(unsigned char* buff)
{
    return 0;
}

void network::recv(unsigned char* buff, int& len)
{
    len = 0;
}

int network::requestUrl(string url, unsigned char* data)
{
    // 请求网络数据
    int ret = -1;
    if (url != "")
    {
        unsigned char tempRequest[32] = {0x8};
        ret = send(tempRequest);
    }
    // 接受返回数据
    if (ret > 0)
    {
        unsigned char tempRecv[1024] = {0x00};
        recv(tempRecv, ret);
    }
    // 返回数据给请求发起者
    if (ret > 0)
    {
        for(int i = 0; i < (int)sizeof(data); i++)
        {
            data[i] = i;
        }
        return ret;
    }
    
    return ret;
}
