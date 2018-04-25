#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

void f1(int a)  { printf("f1: %d\n", a); }
void f2(int a, int b, int c)  { printf("f2: %d, %d\n", a, b); }

class Test
{
  public:
    int data = 0;

    void f(int a, int b)
    {
      data = a;
      printf("f: %d, %d\n", a, b);
    }
};

int main()
{
  Test t;

  function<void(int)> f1;

  f1 = bind(&Test::f, &t, _1, 20);
  f1(10);


  function<void(Test*, int)> f2;
  f2 = bind(&Test::f, _1, _2, 20);
  f2(&t, 100);
  cout << t.data << endl;

  function<void(Test, int)> f3;
  f3 = bind(&Test::f, _1, _2, 20);
  f3(t, 200);
  cout << t.data << endl;
}


// std::function
// 함수포인터를 일반화한 개념
// callable object를 보관했다가 나중에 호출할때 사용.
