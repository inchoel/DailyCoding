#include <iostream>
#include <memory>
using namespace std;

class Car
{
  int color;
public:
  ~Car() { cout << "~Car()" << endl; }

  void Go() { cout << "Car go" << endl; }
};

int main()
{
  shared_ptr<Car> p (new Car);

  p->Go();
  (*p).Go();
}


// 스마트 포인터 개념
// 포인터와 유사하게 동작하는 추상화된 타입으로 포인터의 기능외에 자동화된
// 자원관리 등의 기능을 추가로 제공한다.
//
// Raw Pointer: 생성자, 소멸자 등을 가질수 없다.
// Smart Pointer: 생성자, 소멸자를 가진다.
//                생성/복사/대입/소멸의 과정에서 추가적인 기능을 수행할 수 있다. 일반적으로 소멸자에서 자동화된 자원관리를 수행한다.
//
//
//
// 스마트 포인터의 원리
// shared_ptr은 개체이지만 내부적으로 객체의 주소를 보관하기 위한 포인터 맴버를 가지고 있다.
// ->, * 연산자를 재정의 되어 있기 때문에 포인터 처럼 사용할 수 있다.
