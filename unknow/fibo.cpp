#include <iostream>
#include <vector>
using namespace std;

long long fibo(const int n) {
  vector<long long> v(100);
  v[0] = 0;
  v[1] = 1;

  cout << "test" << endl;
  for (int i=2; i<=n; i++) {
    v[i] = v[i-1] + v[i-2];
  }
  cout << "test2" << endl;

  return v[n];
}

int main()
{
  int n;

  cin >> n;
  cout << fibo(n) << endl;
  return 0;
}
