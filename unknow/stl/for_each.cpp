#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
/*
// void foo(int a)
void foo(int& a)
{
  // cout << a << endl;
  a = a* 2;
}
*/
struct Show
{
  string sep;
  ostream& os;

  // 생성자 및 맴버변수를 이용하여 여러가지를 할 수 있다.
  Show(ostream& o = cout, string s = "\n") : os(o), sep(s) {}
  void operator()(int a) const
  {
    os << a << sep;
  }
};

int main()
{
  vector<int> v = {1,2,3,4,5,6,7,8,9,10};

  // for_each(begin(v), end(v), foo);
  //
  Show s(cout, "\t");
  for_each(begin(v), end(v), s);

  for (auto n : v)
    cout << n << endl;

  return 0;
}

// STL알고리즘은 함수를 인자로 가지는 경우가 많이 있다.
//    알고리즘의 활용도를 높여준다.
//    for_each, transform
//    
//    단항 함수 :인자가 한 개인 함수
//    이항 함수 :인자가 두 개인 함수
//
//    일반 함수 뿐 아니라, 함수 객체, 람다 표현식을 사용할 수 있다. - ()로 호출가능한 모든 객체를 사용 가능.
