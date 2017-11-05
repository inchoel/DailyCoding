#include <cstdio>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  int dp[21];
  dp[0] = 0;
  dp[1] = 1;
  for (int i=2; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  printf("%d\n", dp[n]);

  return 0;
}
