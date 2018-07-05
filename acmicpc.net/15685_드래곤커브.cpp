#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int N;
bool map[50][50];

// generate dragon curve

int main() {
  scanf (" %d", &N);

  vector<vector<int>> d(N, vector<int>(4));
  for (int i=0; i<N; i++)
    scanf (" %d %d %d %d", &d[i][0], &d[i][1], &d[i][2], &d[i][3]);

  // 1. Draw dragon curve on the map
  // 2. Check 4 vertex

  return 0;
}
