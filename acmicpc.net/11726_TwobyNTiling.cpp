#include <iostream>
#include <array>
using namespace std;

int main() {
  int input;
  cin >> input;

  array<int, 1001> DP;
  DP[1] = 1;
  DP[2] = 2;
  for (int i=3; i<=input; i++) {
    DP[i] = (DP[i-1] + DP[i-2]) / 10007;
  }

  cout << DP[input] << endl;
  return 0;
}
