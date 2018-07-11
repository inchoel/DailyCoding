#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool map[100][100];

void drawDragonCurve(const vector<int>& v)
{
  printf("(%d, %d), direction:%d, generation:%d\n", v[0], v[1], v[2], v[3]);
}

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> d(4);
  for (int i=0; i<n; i++) {
    scanf (" %d %d %d %d", &d[0], &d[1], &d[2], &d[3]);
    // 1. Draw dragon curve on the map
    drawDragonCurve(d);
  }

  // 2. Check 4 vertex

  return 0;
}
