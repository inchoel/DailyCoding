#include <iostream>
using namespace std;

int GCD(const int a, const int b)
{
  if (a == 0)
    return b;

  GCD(b%a, a);
}

int LCM(const int a, const int b)
{
  return (a * b) / GCD(min(a, b), max(a, b));
}

int main() {
  int A, B;
  cin >> A >> B;

  cout << GCD(min(A, B), max(A, B)) << endl;
  cout << LCM(A, B) << endl;
  return 0;
}
