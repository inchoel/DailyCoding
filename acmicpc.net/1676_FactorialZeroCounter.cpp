#include <iostream>
using namespace std;

int getZeroLength(const int n)
{
  int zeroCount = 0;

  for (int i=2; i<=n; i++) {
    if (i % 5 == 0)
      zeroCount++;
    if (i % 25 == 0)
      zeroCount++;
    if (i % 125 == 0)
      zeroCount++;
  }

  return zeroCount;
}

int main()
{
  int n;
  cin >> n;

  cout << getZeroLength(n) << endl;
  return 0;
}
