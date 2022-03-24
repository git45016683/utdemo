/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:40:30
 * @LastEditTime: 2022-03-24 23:43:16
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\src\test_src\test_model.cpp
 */
#include "test_model.h"

using ::testing::Return;
using ::testing::_;
// using ::testing::DoAll;
// using ::testing::AtLeast;
using ::testing::SetArgReferee;  // for function's output param via reference
// using ::testing::AnyNumber;


#pragma region "UT_Public_IsPrime"\
{
// Tests negative input.
TEST_F(modelTest, DISABLED_IsPrimeNegative) {
    // This test belongs to the IsPrimeTest test case.
    EXPECT_FALSE(pm->IsPrime(-1));
    EXPECT_FALSE(pm->IsPrime(-2));
    EXPECT_FALSE(pm->IsPrime(INT_MIN));
}

// Tests some trivial cases.
TEST_F(modelTest, DISABLED_IsPrimeTrivial) {
    EXPECT_FALSE(pm->IsPrime(0));
    EXPECT_FALSE(pm->IsPrime(1));
    EXPECT_TRUE(pm->IsPrime(2));
    EXPECT_TRUE(pm->IsPrime(3));
}

// Tests positive input.
TEST_F(modelTest, DISABLED_IsPrimePositive) {
    EXPECT_FALSE(pm->IsPrime(4));
    EXPECT_TRUE(pm->IsPrime(5));
    EXPECT_FALSE(pm->IsPrime(6));
    EXPECT_TRUE(pm->IsPrime(23));
}
#pragma endregion }

#pragma region "UT_Protected_Factorial"\
{
// Tests factorial of negative numbers.
TEST_F(modelTest, DISABLED_Negative) {
  // This test is named "Negative", and belongs to the "FactorialTest"
  // test case.
  EXPECT_EQ(1, pm->Factorial(-5));
  EXPECT_EQ(1, pm->Factorial(-1));
  EXPECT_GT(pm->Factorial(-10), 0);

}

// Tests factorial of 0.
TEST_F(modelTest, DISABLED_Zero) {
  EXPECT_EQ(1, pm->Factorial(0));
}

// Tests factorial of positive numbers.
TEST_F(modelTest, DISABLED_Positive) {
  EXPECT_EQ(1, pm->Factorial(1));
  EXPECT_EQ(2, pm->Factorial(2));
  EXPECT_EQ(6, pm->Factorial(3));
  EXPECT_EQ(40320, pm->Factorial(8));
}
#pragma endregion }

#pragma region "UT_showData" \
{
TEST_F(modelTest, showData_requestUrlFail) {
    EXPECT_FALSE(pm->showData());
}

TEST_F(modelTest, showData_requestUrlFail_sendSuccess_recvFailed) {
    MockSimulateSocket mock;
    EXPECT_CALL(mock, send(_)).Times(1).WillOnce(Return(32));
    EXPECT_CALL(mock, recv(_,_)).Times(1).WillOnce(SetArgReferee<1>(0));
    pm->setNetwork((network*)&mock);
    EXPECT_FALSE(pm->showData());
}

TEST_F(modelTest, showData_requestUrlSuccess_sendSuccess_recvSuccess) {
    MockSimulateSocket mock;
    EXPECT_CALL(mock, send(_)).Times(1).WillOnce(Return(32));
    EXPECT_CALL(mock, recv(_,_)).Times(1).WillOnce(SetArgReferee<1>(64));
    pm->setNetwork((network*)&mock);
    EXPECT_TRUE(pm->showData());
}

TEST_F(modelTest, showData_requestUrlFail_sendSuccess_nocallMockrecv) {
    MockSimulateSocket mock;
    EXPECT_CALL(mock, send(_)).Times(1).WillOnce(Return(32));
    pm->setNetwork((network*)&mock);
    EXPECT_TRUE(pm->showData());
}
#pragma endregion }