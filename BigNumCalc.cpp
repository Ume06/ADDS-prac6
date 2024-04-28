#include <list>
#include <iostream>
#include "BigNumCalc.h"

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
  std::list<int> bigNum;
  for (int i = 0; i < numString.length(); i++) {
    bigNum.push_back(numString[i] - '0');
  }
  return bigNum;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  if (num1.empty() || num2.empty())
    return num1.empty() ? num2 : num1;
  std::list<int> result;
  int carry = 0;
  while(!num1.empty() || !num2.empty()) {
    int temp = num1.back() + num2.back() + carry;
    if (num1.empty())
      temp = num2.back() + carry;
    if (num2.empty())
      temp = num1.back() + carry;
    std::cout << temp << std::endl;
    num1.pop_back();
    num2.pop_back();
    if (temp > 9) {
      carry = 1;
      temp %= 10;
    } else {
      carry = 0;
    }
    result.push_front(temp);
  }
  if (carry > 1) {
    result.push_front(1);
  }
  return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> result;
  int borrow = 0;
  while(!num1.empty() || !num2.empty()) {
    int temp = num1.back() - num2.back() - borrow;
    num1.pop_back();
    num2.pop_back();
    if (temp < 0) {
      borrow = 1;
      temp += 10;
    } else {
      borrow = 0;
    }
    result.push_front(temp);
  }
  return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
  std::list<int> result{0};
  int zeroes = 0, carry = 0;

  while(!num1.empty()) {
    if (num1.empty() || num2.empty() || num1.back() == 0 || num2.back() == 0)
      return {0};
    std::list<int> temp, tempNum2 = num2;

    while(!tempNum2.empty()) {
      int num = num1.back() * tempNum2.back() + carry;
      if (num > 9) {
        carry = num / 10;
        num %= 10;
      } else {
        carry = 0;
      }

      temp.push_front(num);
      tempNum2.pop_back();
    }

    if (carry > 0)
      temp.push_front(carry);

    for (int i = 0; i < zeroes; i++) {
      temp.push_back(0);
    }
    zeroes++;

    result = add(temp, result);

    num1.pop_back();
  }
    

  return result;
}