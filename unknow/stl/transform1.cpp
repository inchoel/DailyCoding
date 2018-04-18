#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int foo(int a) { return a+10; }

int main()
{
  list<int> s1 = {1,2,3,4,5};
  // list<int> s2 = {0,0,0,0,0};
  list<int> s2;

  // transform( begin(s1), end(s1), begin(s2), foo);

  // s2 리스트가 비어 있는 경우에 begin(s2)는 유효하지 않으므로 back_inserter, front_inserter 등을 사용한다.
  transform( begin(s1), end(s1), back_inserter(s2), foo);

  for(auto n : s2)
    cout << n << endl;

  return 0;
}

// transform
//  인자로 전달된 컨테이너의 모든 요소에 연산을 적용 후 다른 컨테이너에 복사하는 알고리즘
//  단항함수 버전과 이항함수 버전 제공
