/*
 * @Author: icemaple
 * @Date: 2022-03-20 09:20:42
 * @LastEditTime: 2022-03-20 12:37:23
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\qt\utdemo\utdemo\main.cpp
 */
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

int main(int argc, char *argv[])
{
    printf("qt: hello gtest\r\n");
    testing::InitGoogleMock(&argc, argv);
    testing::InitGoogleTest(&argc, argv);
    int l_iRet = RUN_ALL_TESTS();
    printf("RUN_ALL_TESTS = %d\r\n", l_iRet);
    return l_iRet;
}
