#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int N;
  scanf (" %d", &N);

  vector<int> dp(N+1, N);

  dp[0] = 0;
  for (int i=1; i*i<=N; i++) {
    for (int j=i*i; j<=N; j++) {
      dp[j] = min(dp[j], dp[j-i*i]+1);
    }
  }

  cout << dp[N] << endl;

  return 0;
}
