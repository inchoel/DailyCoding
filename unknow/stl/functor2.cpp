#include <iostream>
#include <functional>
using namespace std;

int main()
{
  plus<int> p;
  int n = p(1,2);  // p.operator()(1,2);
  cout << n << endl;

  multiplies<int> m;
  cout << m(3,4) << endl;

  return 0;
}

