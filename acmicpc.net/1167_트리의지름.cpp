#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <array>

#define SIZE (100001)
using namespace std;

int V;
vector<pair<int, int>> a[SIZE];

int dfs (int& v) {
  int sum=0, max=0;
  stack<pair<int, int>> s;
  s.push(make_pair(v, 0));
  array<bool, SIZE> isVisited;
  isVisited.fill(false);

  // printf("root: %d\n", v);
  int vtx, dist;
  pair<int, int> tmp;
  do {
    tmp = s.top();
    vtx = tmp.first;
    dist = tmp.second;
    if (isVisited[vtx]==false) {
      sum += dist;
      isVisited[vtx] = true;
    }
    // printf("v:%d d:%d s:%d\n", vtx, dist, sum);

    size_t i;
    for (i=0; i<a[vtx].size(); i++) {
      if (isVisited[a[vtx][i].first])
        continue;

      s.push (a[vtx][i]);
      break;
    }

    if (i==a[vtx].size()) {
      if (sum > max) {
        max = sum;
        v = vtx;
      }
      sum -= dist;
      s.pop();
    }
  } while (!s.empty());

  return max;
}

int getDiameter(void) {
  int root = a[1][0].first; // 임의의 정점
  dfs (root);

  return dfs(root);
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
