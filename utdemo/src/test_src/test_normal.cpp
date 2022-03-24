/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:40:30
 * @LastEditTime: 2022-03-24 23:43:37
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \utdemo\utdemo\src\test_src\test_normal.cpp
 */
#include "test_normal.h"

#define LEN 64

#pragma region "UT_findFirstSemicolon" {
TEST(fidFirstSemicolonTest, DISABLED_Found) {
    char buff[LEN] = "xxxxxx;xx;xxx";

    EXPECT_EQ(findFirstSemicolon(buff, sizeof(buff)), 6);
}

TEST(fidFirstSemicolonTest, DISABLED_NotFound) {
    char buff[LEN] = "xxxxxxx";

    EXPECT_EQ(findFirstSemicolon(buff, sizeof(buff)), -1);
}

TEST(fidFirstSemicolonTest, DISABLED_DataIsNull) {
    char* buff = NULL;

    EXPECT_EQ(findFirstSemicolon(buff, sizeof(buff)), -1);
}

TEST(fidFirstSemicolonTest, DISABLED_LenLessthan0) {
    char buff[LEN] = "xxxxxx;xxxxx";

    EXPECT_EQ(findFirstSemicolon(buff, 0), -1);
}
#pragma endregion }

//---------------------------------------------------------------------

#pragma region "UTWithTestSuite_findFirstSemicolon" {
TEST_F(FindSemicolonWithSuiteTest, DISABLED_Found) {
    EXPECT_EQ(findFirstSemicolon(buff, sizeof(buff)), 6);
}

TEST_F(FindSemicolonWithSuiteTest, DISABLED_NotFound) {
    memcpy(buff, "xxxxxxnxxnxxx", sizeof("xxxxxxnxxnxxx"));
    EXPECT_EQ(findFirstSemicolon(buff, sizeof(buff)), -1);
}

TEST_F(FindSemicolonWithSuiteTest, DISABLED_DataIsNull) {
    EXPECT_EQ(findFirstSemicolon(pbuff, sizeof(pbuff)), -1);
}

TEST_F(FindSemicolonWithSuiteTest, DISABLED_LenLessthan0) {
    EXPECT_EQ(findFirstSemicolon(buff, 0), -1);
}
#pragma endregion }
