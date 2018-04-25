#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

class Test
{
public:
  int data = 0;

  void f (int a, int b) // void f(Test* this, int a, int b)
  {
    data = a;
    printf("f : %d, %d\n", a, b);
  }
};

int main()
{
  Test t;

  // 객체를 고정하는 경우
  bind(&Test::f, &t, 1, 2)(); // t.f(1,2);
  cout << t.data << endl;

  bind(&Test::f, t, 4, 2)(); // t.f(1,2);
  cout << t.data << endl;  // <-- t 복사본이 전달되어 t.data는 변화가 없다.

  bind(&Test::f, ref(t), 4,2)();
  cout << t.data << endl;

  // 객체를 인자로 전달하는 경우에는 ref, cref를 사용하지 않아도 된다.
  bind(&Test::f, _1, 8, 2)(&t);
  cout << t.data << endl;


  // 맴버변수를 bind하는 경우
  bind(&Test::data, &t)() = 10; // t.data = 10;
  cout << t.data << endl;
}


