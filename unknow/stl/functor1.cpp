#include <iostream>
using namespace std;

// 함수객체(Function Object, Functor)
// ()연산자를 사용해서 함수 처럼 호출가능한 모든 객체
// 함수객체의 장점
// --> 알고리즘에 전달시 일반 ㅎ마수는 인라인 치환이 안되지만 함수객체는 인라인 치환 가능.
// --> 상태를 가질수 있다.

// ()를 사용해서 호출하는 것들..
// 1. 함수
// 2. 함수 포인터
// 3. ()를 재정의한 클래스
// 4. 람다표현식...

struct Plus
{
  int operator() (int a, int b) const
  {
    return a + b;
  }
};

int main()
{
  Plus p;
  int n = p(1,2);  // p.operator()(1,2);
  cout << n << endl;

  // a + b;   a.operator+(b);
  // a - b;   a.operator-(b);
  // a();     a.operator();
  // a(1,2);  a.operator()(1,2);
}

