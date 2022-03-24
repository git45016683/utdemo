/*
 * @Author: icemaple
 * @Date: 2022-03-19 05:42:05
 * @LastEditTime: 2022-03-24 05:40:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \demo\model\model.cpp
 */
#include <iostream>
#include "model.h"
using namespace std;
#define MAXLEN 1024

int findFirstSemicolon(char* buff, int len)
{
    int ret = -1;
    if (buff == NULL || len <= 0)
    {
        return ret;
    }

    for (int i = 0; i < len; i++)
    {
        if (';' == buff[i])
        {
            ret = i;
            break;
        }
    }

    return ret;
}

model::model()
{
    _pdevice = new device;
    _pnetwork = new network;
}

model::~model()
{
}

void model::printmodelinfo()
{
    cout << "icemaple Model" << endl;
}

void model::printmodelverion()
{
    cout << "version 2.22.6" << endl;
}

void model::printmodeldeviceinfo()
{
    cout << "hwModel make in China" << endl;
}

void model::printmodeldeviceversion()
{
    cout << "hwModel V6.66" << endl;
}

void model::printmodeldeviceserial()
{
    cout << "hwSerial 6.66.666.6666" << endl;
}

void model::printallinfo()
{
    printmodelinfo();
    printmodelverion();
    printmodeldeviceinfo();
    printmodeldeviceversion();
    printmodeldeviceserial();
}

bool model::showImg()
{
    // 1.请求图片
    // 2.处理图片
    // 3.下发图片
    return true;
}

bool model::showData()
{
    unsigned char recv[MAXLEN] = {0};
    unsigned char send[MAXLEN] = {0};
    // 1.请求数据
    string url = "abc";
    int len = _pnetwork->requestUrl(url, recv);
    if (len <= 0)
    {
        return false;
    }
    // 2.处理数据
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (IsPrime(recv[i]))
        {
            send[j++] = recv[i];
        }
    }
    // 3.下发数据
    _pdevice->senddatatodevice(send, j);
    return true;
}

// 这里借用gtest官方的素数例子
// Returns true iff n is a prime number.
bool model::IsPrime(int n)
{
  // Trivial case 1: small numbers
  if (n <= 1) return false;

  // Trivial case 2: even numbers
  if (n % 2 == 0) return n == 2;

  // Now, we have that n is odd and n >= 3.

  // Try to divide n by every odd number i, starting from 3
  for (int i = 3; ; i += 2) {
    // We only have to try i up to the square root of n
    if (i > n/i) break;

    // Now, we have i <= n/i < n.
    // If n is divisible by i, n is not prime.
    if (n % i == 0) return false;
  }

  // n has no integer factor in the range (1, n), and thus is prime.
  return true;
}
// 这里借用gtest官方的阶乘例子
int model::Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }

  return result;
}
