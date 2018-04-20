#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v(10, 0); // 10개를 0으로 초기화
  vector<int> v2{10, 0}; // 2개를 0으로 초기화

  v.push_back(10);
  v.push_back(20);

  v.insert(begin(v)+1, 30); // 10, 30, 20
  for (auto n : v)
    printf("%d\n", n);

  // 요소 꺼내기
  int n = v.front();
  int n1 = v[0];

  int x[5] = {1,2,3,4,5};
  v.assign(x, x+5);

  v[100] = 10;    // 예외 없이 runtime error
  v.at(100) = 10; // 예외 발생

  for (auto n : v)
    printf("%d\n", n);
}
// vector
/*
template<typename T, typename Allocator = allocator<T>>
class vector;


push_front()         insert()          push_back()
pop_front()          erase()           pop_back()
front()                                back()
 --------------------------------------------
 |      |     |     |     |     |     |     |
 --------------------------------------------

 */
