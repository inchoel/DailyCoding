#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test
{
  public:
    int data = 10;
};

int main()
{
  Test t1, t2;

  // 참조를 리턴하면 lvalue가 될 수 있다.
  function<int&()> f1;

  f1 = bind(&Test::data, &t1);
  f1() = 20;

  cout << f1() << endl;



  // 2. 객체를 function인자로 전달하는 방식
  function<int&(Test*)> f2;

  f2 = bind(&Test::data, _1);
  f2(&t1) = 30;
  f2(&t2) = 40;

  cout << t1.data << endl;
  cout << t2.data << endl;
}
