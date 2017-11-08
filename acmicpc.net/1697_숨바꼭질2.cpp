#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;

int findPath () {
  if (N == K)
    return 0;

  int visited[100001] = {0, };
  queue<int> q;
  q.push(N);
  visited[N] = 1;

  int x;
  while (!q.empty()) {
    x = q.front();
    q.pop();

    if (x == K)
      return visited[x] - 1;

    if (x-1 >= 0 && visited[x-1]==0) {
      q.push(x-1);
      visited[x-1] = visited[x] + 1;
    }

    if (x+1 <= 100000 && visited[x+1]==0) {
      q.push(x+1);
      visited[x+1] = visited[x] + 1;
    }

    if (x*2 <= 100000 && visited[x*2]==0) {
      q.push(x*2);
      visited[x*2] = visited[x] + 1;
    }
  }
}

int main() {
  scanf(" %d %d", &N, &K);

  printf("%d\n", findPath());
}
