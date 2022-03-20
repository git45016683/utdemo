/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:49:01
 * @LastEditTime: 2022-03-20 12:39:25
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

int network::requestUrl(string url, unsigned char* data)
{
    // 请求网络数据并返回
    for(int i = 0; i < (int)sizeof(data); i++)
    {
        data[i] = i;
    }
    return 0;
}
