#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  vector<int> v1 = {1,2,3};

  // _if 가 붙는 이유는 마지막 3번째 인자가 템플릿 인자로 넘어가기 때문에 구분이 어려워 함수명을 변경할 수 밖에 없음.
  find (begin(v1), end(v1), 3);
  find_if(begin(v1), end(v1), foo);

  // sort 의 경우에는 인자의 갯수가 다르기 때문에 오버로딩 가능하여 함수명이 같음.
  sort( begin(v1), end(v1) );
  sort( begin(v1), end(v1), goo );

  vector<int> v1 = {0,0,0};
  remove_copy( begin(v1), end(v1), begin(v2), 3 );

  // sort_copy가 존재하지 않는 이유는 sort, copy 각각의 처리속도가 차이나기 때문이다. sort가 처리시간이 훨씬 길기 때문에 sort, copy둘을 합쳐봐야 성능에 이득이 없다.
  // 그러나 remove_copy의 경우, remove, copy는 유사하고 한번에 처리하는 하는 것이 성능에 이득이 있기 때문에 해당 함수가 존재한다. 
  sort_copy( begin(v1), end(v1) , begin(v2)); // error

  for (auto n : v2)
    cout << n << endl;
  return 0;
}
