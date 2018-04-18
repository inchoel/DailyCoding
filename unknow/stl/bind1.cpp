#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  modulus<int> m;

  int n = m(10, 3);  // 10 % 3 = 1

  int x[5] = {9, 9, 2, 4, 3};

  // 3의 배수가 아닌것을 찾고 싶다.
  find_if (x, x+5, 단항);
  return 0;
}


// std::bind
//
// modulus<>는 2항 함수객체이다.
// find_if의 조건자는 단항이어야 한다.
// 이항을 단항으로 변경할 수 없을까?
