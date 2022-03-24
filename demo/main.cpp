/*
 * @Author: your name
 * @Date: 2022-03-19 05:42:02
 * @LastEditTime: 2022-03-19 06:56:51
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\main.cpp
 */
#include <stdio.h>
#include "model.h"

int main() {
    printf("hello model");

    model* pmodel = new model();
    pmodel->printallinfo();
    
    delete pmodel;
    pmodel = 0;
    return 0;
}
