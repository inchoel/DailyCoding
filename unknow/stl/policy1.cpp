#include <iostream>
using namespace std;

template<typename T, typename Allocator=allocator<T> > class vector
{
  //...
  Allocator ax;
  public:
    void push_back(const T& a)
    {
      // 메모리 할당이 필요한다.
      // new, malloc, shared mem, pool 등 여러방법이 있음.
      T* p = ax.allocate(1);
      ax.deallocate(p, 1);
    }
};

int main()
{
  vector<int, MyAlloc> v;

  v.push_back(10);
}

// STL과 Policy Base Design
// Allocator
//    메모리 할당 정책을 담은 클래스 
//    c++ 표준 메모리 할당기 : allocator
//    STL의 대부분의 컨테이너는 allocator를 사용해서 메모리를 할당한다.
//
// 단위 전략 디자인 (Policy Base Design)
//    클래스가 사용하는 다양한 정책을 '템플릿 인자'를 통해서 교체할 수 있게 하는 디자인 기법
