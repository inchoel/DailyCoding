#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  // 1. 일반 함수 전달
  for_each(begin(v), end(v), foo);
  // 2. 함수 객체 전달
  Show s(cout, "\t");
  for_each(begin(v), end(v), s);

  // 3. 람다 표현식
  // 익명의 함수 객체를 만드는 표현식
  // []: 람다 표현식이 시작 됨을 알리는 "lambda introducer"
  for_each( begin(v), end(v), [](int a){ cout << a << endl; } );
  

  return 0;
}


