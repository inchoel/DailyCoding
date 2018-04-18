#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

//4항 함수
void foo( int a, int b, int c, int d)
{
  printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
  foo(1,2,3,4);

  // 4항 함수 --> 2항 으로
  // bind(&foo, 10, _2, _1, 20)(1,2); // 10, 2, 1, 20

  // 4 -> 3항 으로
  bind(&foo, _3, _2, _1, 100)(30, 20, 10);  // 10, 20, 30, 100

  // 4 -> 0항 으로
  bind(&foo, 1,2,3,4)();

  modulus<int> m;
  cout << m(10, 3) << endl;

  bind(m, 10, 3)();
  bind(m, _1, 3)(10);

  int x[3] = {1,2,3};

  //3의 배수가 아닌것 찾기.
  auto p = find_if( x, x+3, bind(m, _1, 3) );
  cout << *p << endl;

  return 0;
}

// std::bind
//    M항 함수(함수객체)의 인자를 고정한 새로운 함수(함수객체)를 생성
//    #include <functional>
//    placeholder(_1, _2, ...)는 std::placeholders 이름공간에 있다.
//    일반함수 뿐 아니라 함수객체, 맴버함수, 람다표현식 등에도 사용할 수 있다.
