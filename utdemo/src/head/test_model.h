/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:40:58
 * @LastEditTime: 2022-03-21 01:01:49
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\src\head\test_model.h
 */
#ifndef TEST_MODEL_H
#define TEST_MODEL_H

#include "inc.h"

class modelTest : public testing::Test {
protected:
    void SetUp() override {
        pm = new model;
    }

    void TearDown() override {
        if (pm) {
            delete pm;
            pm = NULL;
        }
    }

    model* pm;
};

#endif // TEST_MODEL_H
