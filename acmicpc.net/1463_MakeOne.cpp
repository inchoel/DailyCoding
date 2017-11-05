#include <iostream>
#include <array>
using namespace std;

#define ARR_MAX (1000001)

int main()
{
  int input;
  array<int, ARR_MAX> dp;
  cin >> input;
  // dp[i] = dp[i-1] + 1 or dp[i/3] + 1 or dp[i/2] + 1
  dp[1] = 0;
  for (size_t i=2; i<=input; i++) {
    dp[i] = dp[i-1] + 1;
    if ( i % 2 == 0 )
      dp[i] = min (dp[i], dp[i/2]+1);
    if ( i % 3 == 0 )
      dp[i] = min (dp[i], dp[i/3]+1);
  }

  cout << dp[input] << endl;
  return 0;
}
