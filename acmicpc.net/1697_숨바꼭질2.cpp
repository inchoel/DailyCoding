#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

void findPath (int x, int time, int& ans) {
  if (x < 0)
    return;

  if (x == N && time != 0)
    return;

  if (ans <= time)
    return;

  if (x == K) {
    ans = time;
    return;
  }

  time++;

  vector<int> v(3);
  v[0] = x-1;
  v[1] = x+1;
  v[2] = x*2;
  for (auto& xx : v) {
    findPath (xx, time, ans);
  }
}

int main() {
  scanf(" %d %d", &N, &K);

  int ans = abs(N-K);
  findPath (N, 0, ans);

  printf("%d\n", ans);
}
