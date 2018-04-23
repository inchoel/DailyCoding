#include <iostream>
#include <memory>
#include "car.h"
using namespace std;

int main()
{
  int a = 0; // copy initialization
  int a(0);  // direct initialization

  shared_ptr<Car> p = new Car;
  shared_ptr<Car> p(new Car);

  shared_ptr<Car> p1 (new Car);
  shared_ptr<Car> p2 = p1;
}


// shared_ptr 기본
// <memory> 헤더
// copy 초기화 될 수 없고, direct 초기화만 가능하다. -explicit 생성자
//
// shared_ptr 의 메모리 구조
// shared_ptr<Car> p1
// -------            ----------
// | p1  |            | Car    |
// -------            ----------
//
// -------            ----------
// | p2  |            | vptr   |
// -------            ----------
