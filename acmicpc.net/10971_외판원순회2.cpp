#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  int w[n][n];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      scanf (" %d", &w[i][j]);
  }

  vector<int> v(n);
  for (int i=0; i<n; i++) 
    v[i] = i;

  int i, j, cost, lowest=numeric_limits<int>::max();
  bool valid;
  do {
    cost = 0;
    valid = true;
    for (int idx=0; idx<n; idx++) {
      i = v[idx];
      j = v[(idx+1)%n];

      if (w[i][j] == 0) {
        valid = false;
        break;
      }

      cost += w[i][j];
    }

    if (valid && lowest > cost)
      lowest = cost;
  } while (next_permutation(v.begin(), v.end()));

  printf("%d\n", lowest);

  return 0;
}
