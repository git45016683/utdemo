/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:40:30
 * @LastEditTime: 2022-03-21 01:02:51
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\src\test_src\test_model.cpp
 */
#include "test_model.h"

// using ::testing::Return;
// using ::testing::_;
// using ::testing::DoAll;
// using ::testing::AtLeast;
// using ::testing::SetArgReferee;  // for function's output param via reference
// using ::testing::AnyNumber;


#pragma region "UT_IsPrime"\
{
// Tests negative input.
TEST_F(modelTest, IsPrimeNegative) {
    // This test belongs to the IsPrimeTest test case.
    EXPECT_FALSE(pm->IsPrime(-1));
    EXPECT_FALSE(pm->IsPrime(-2));
    EXPECT_FALSE(pm->IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST_F(modelTest, IsPrimeTrivial) {
    EXPECT_FALSE(pm->IsPrime(0));
    EXPECT_FALSE(pm->IsPrime(1));
    EXPECT_TRUE(pm->IsPrime(2));
    EXPECT_TRUE(pm->IsPrime(3));
}

// Tests positive input.
TEST_F(modelTest, IsPrimePositive) {
    EXPECT_FALSE(pm->IsPrime(4));
    EXPECT_TRUE(pm->IsPrime(5));
    EXPECT_FALSE(pm->IsPrime(6));
    EXPECT_TRUE(pm->IsPrime(23));
}
#pragma endregion }
