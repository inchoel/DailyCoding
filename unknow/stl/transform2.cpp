#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

int foo(int a, int b) { return a+b; }

int main()
{
  list<int> s1 = {1,2,3,4,5};
  list<int> s2 = {1,2,3,4,5};
  list<int> s3 = {0,0,0,0,0};

  // transform( begin(s1), end(s1), begin(s2), begin(s3), foo);
  
  // #include <functional> 
  // transform( begin(s1), end(s1), begin(s2), begin(s3), multiplies<int>());
  transform( begin(s1), end(s1), begin(s2), begin(s3), [](int a, int b){ return a + b; });

  for(auto n : s3)
    cout << n << endl;

  return 0;
}

// transform
//  인자로 전달된 컨테이너의 모든 요소에 연산을 적용 후 다른 컨테이너에 복사하는 알고리즘
//  단항함수 버전과 이항함수 버전 제공
