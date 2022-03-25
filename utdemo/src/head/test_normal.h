/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:40:58
 * @LastEditTime: 2022-03-20 14:29:39
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\src\head\test_model.h
 */
#ifndef TEST_MODEL_H
#define TEST_MODEL_H

#include "inc.h"

class FindSemicolonWithSuiteTest : public testing::Test {
protected:
    void SetUp() override {
        memcpy(buff, "xxxxxx;xx;xxx", sizeof("xxxxxx;xx;xxx"));
        pbuff = NULL;
    }

    void TearDown() override {
        memset(buff, 0, sizeof(buff));
    }

    char buff[64];
    char* pbuff;
};

#endif // TEST_MODEL_H
