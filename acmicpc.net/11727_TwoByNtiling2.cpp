#include <iostream>
#include <array>
using namespace std;

int numOfTiling(int n) {
  array<int, 1001> dp;

  if (n == 1)
    return 1;
  if (n == 2)
    return 3;

  dp[1] = 1;
  dp[2] = 3;

  for(int i=3; i<=n; i++)
    dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;

  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  cout << numOfTiling(n) << endl;
  return 0;
}
