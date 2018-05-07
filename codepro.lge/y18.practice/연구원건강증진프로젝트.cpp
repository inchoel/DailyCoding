#include <iostream>
using namespace std;

int N;
int P[310];
int dp[310];

int Solve() {
  int sol=0;

  for (int i = 1; i <= 3 && i <= N; i++)
    if (i!=3)
      dp[i] = dp[i - 1] + P[i];
    else
      dp[i] = max(P[i] + dp[i - 2], P[i] + P[i - 1]);


  for (int i=4; i<=N; i++) {
    dp[i] = max(dp[i-2], dp[i-3]+P[i-1]) + P[i];
  }
  sol = dp[N];

  return sol;
}

void InputData() {
  cin >> N;
  for(int i=1 ; i<=N ; i++) {
    cin >> P[i];
  }
}

int main() {

  InputData();

  int sol = Solve();

  cout << sol << endl;
  return 0;
}

