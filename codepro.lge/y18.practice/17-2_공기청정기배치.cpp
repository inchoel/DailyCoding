#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int H, W;
int v[50][50];
bool isVisited[50][50];
int area;
int count;
int max_count;

void InputData() {
  scanf (" %d", &H);
  scanf (" %d", &W);
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      scanf (" %d", &v[i][j]);
    }
  }
}

void findOpen(pair<int,int> wall, queue<pair<int,int>>& q) {
  int open = 0;
  for (int i=0; i<4; i++) {
    open = 1<<i;
    if (v[wall.first][wall.second] & open)
      continue;

    // w:1, n:2, e:4, s:8
    switch(open) {
      case 1:
        if (isVisited[wall.first][wall.second-1] == false) {
          q.push(make_pair(wall.first, wall.second-1));
          count++;
        }
        break;
      case 2:
        if (isVisited[wall.first-1][wall.second] == false) {
          q.push(make_pair(wall.first-1, wall.second));
          count++;
        }
        break;
      case 4:
        if (isVisited[wall.first][wall.second+1] == false) {
          q.push(make_pair(wall.first, wall.second+1));
          count++;
        }
        break;
      case 8:
        if (isVisited[wall.first+1][wall.second] == false) {
          q.push(make_pair(wall.first+1, wall.second));
          count++;
        }
        break;
    }
  }
}

int main() {
  InputData();
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (isVisited[i][j])
        continue;

      count = 0;
      queue<pair<int,int>> q;
      q.push(make_pair(i, j));
      count++;

      while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        isVisited[p.first][p.second] = true;

        findOpen(p, q);

      }

      if (max_count < count)
        max_count = count;
      area++;
    }
  }

  printf("%d\n", area);
  printf("%d\n", max_count);
  return 0;
}
