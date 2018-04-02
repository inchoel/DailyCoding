#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define SIZE (100001)
using namespace std;

int V;
vector<pair<int, int>> a[SIZE];

int dfs (int root) {
}

int getDiameter(void) {
  int diameter = 0;
  vector<int> end;
  for (int i=1; i<=V; i++) {
    if (a[i].size() == 1)
      end.push_back(i);
  }

  int sum_dist=0;
  for (auto e : end) {
    sum_dist = dfs (e);
    if (diameter < sum_dist)
      diameter = sum_dist;
  }

  return diameter;
}

int main(void) {
  scanf (" %d", &V);

  int vv, vvv, dist;
  for (int i=1; i<=V; i++) {
    scanf (" %d", &vv);

    do {
      scanf (" %d", &vvv);
      if (vvv == -1)
        break;
      scanf (" %d", &dist);

      a[vv].push_back(make_pair(vvv, dist));
    } while (1);
  }

  printf("%d\n", getDiameter());

  return 0;
}
