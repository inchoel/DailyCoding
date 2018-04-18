#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v = {6,9,3,1,2};

  // auto p = find( begin(v), end(v), 3);
  auto p = find_if( begin(v), end(v),
                    [](int a){ return (a%3 == 0);} );

  cout << *p << endl;
  return 0;
}


// 조건자 (Predicator)
//    bool 타입을 리턴하는 함수(함수 객체)
//
//
// find vs find_if
// find    :인자로 전달된 값을 검색
// find_if :조건을 만족하는 값을 검색 (활용도가 높다)
