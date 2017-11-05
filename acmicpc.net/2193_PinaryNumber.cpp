#include <iostream>
using namespace std;

long long int pinaryN(const int n)
{
  // pinaryN = pinaryN(n-1) + 0갯수
  if (n <= 2)
    return 1;

  long long int zeros = 1;
  long long int count = 1;
  long long int temp;

  for (int i=3; i<=n; i++) {
    temp = count;
    count += zeros;
    zeros = temp;
  }

  return count;
}

int main()
{
  int n;
  cin >> n;

  cout << pinaryN(n) << endl;
  return 0;
}
