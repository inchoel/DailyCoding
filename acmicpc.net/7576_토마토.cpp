#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define SIZE (1000)

int M, N;
int box[SIZE][SIZE];
queue<pair<int, int>> q;

void infection(int i, int j) {
  if (i < 0)
    return;
  if (i >= N)
    return;
  if (j < 0)
    return;
  if (j >= M)
    return;

  if (box[i][j]==0) {
    box[i][j] = 1;
    q.push(make_pair(i, j));
  }
}

int countInfectionDay(void) {
  int day = -1;
  pair<int, int> temp;
  size_t q_size = q.size();

  int i, j;
  while (!q.empty()) {
    temp = q.front();
    q.pop();
    i = temp.first;
    j = temp.second;

    infection(i, j-1);
    infection(i, j+1);
    infection(i-1, j);
    infection(i+1, j);

    q_size--;
    if (q_size == 0) {
      day++;
      q_size = q.size();
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (box[i][j]==0)
        return -1;
    }
  }
  return day;
}

int main(void) {
  scanf (" %d %d", &M, &N);
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      scanf (" %d", &box[i][j]);
      if (box[i][j] == 1)
        q.push (make_pair(i, j));
    }
  }

  printf("%d\n", countInfectionDay());

  return 0;
}
