#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
  vector<int> v2 = {0,0,0,0,0,0,0,0,0,0};

  // 기본버전
  // remove( begin(v1), end(v1), 3);

  // 조건자 버전
  // remove_if( begin(v1), end(v1), [](int a){ return a%3==0; });

  // 복사 버전, 리턴 값 p는 v2의 반복자이다.
  // auto p = remove_copy( begin(v1), end(v1), begin(v2), 3);

  // 조건자 복사 버전
  auto p = remove_copy_if( begin(v1), end(v1), begin(v2),
                           [](int a){ return a%3==0; });

  v2.erase(p, end(v2));

  for (auto n : v2)
    cout << n << endl;
  return 0;
}
