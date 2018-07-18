#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, H;

int main() {
  scanf (" %d %d %d", &N, &M, &H);

  vector<vector<pair<int, int>>> v(N+1);
  int x, y;
  for (int i=0; i<M; i++) {
    scanf (" %d %d", &x, &y);
    v[x].push_back(make_pair(y, y+1));
    v[y+1].push_back(make_pair(y, x));
  }

  for (int i=1; i<=N; i++) {
    printf("row : %d\n", i);
    for (auto e : v[i])
      printf("%d->%d\n", e.first, e.second);
  }

  return 0;
}
