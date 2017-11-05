#include <iostream>
#include <limits>
using namespace std;

int main()
{
  int N=0;
  cin >> N;

  int a[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  int max_row = 0;
  int min_col = 0;
  long long sum = 0;

  long long min_sum = numeric_limits<long long>::max();
  for (int j = 0; j < N; j++) {
    sum = 0;
    for (int i = 0; i < N; i++) {
      sum += a[i][j];
    }
    if (sum < min_sum) {
      min_sum = sum;
      min_col = j;
    }
  }

  long long max_sum = numeric_limits<long long>::min();
  for (int i = 0; i < N; i++) {
    sum = 0;
    for (int j = 0; j < N; j++) {
      sum += a[i][j];
    }
    if (sum > max_sum) {
      max_sum = sum;
      max_row = i;
    }
  }

  cout << (max_row+1) << " " << (min_col+1) << endl;

  return 0;
}

