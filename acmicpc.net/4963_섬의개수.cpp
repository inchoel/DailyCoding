#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int w, h;
  vector<int> islands;
  while (1) {
    scanf (" %d %d", &w, &h);
    if (w==0 && h==0)
      break;

    int map[h][w];
    bool isVisited[h][w];
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        scanf (" %d", &map[i][j]);
        isVisited[i][j] = false;
      }
    }

    int island = 0;
    queue<pair<int, int>> q;
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        if (map[i][j]==1 && isVisited[i][j]==false) {
          q.push(make_pair(i, j));
          isVisited[i][j] = true;
          while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if (x-1 >= 0 && isVisited[x-1][y]==false && map[x-1][y]) {
              q.push(make_pair(x-1, y));
              isVisited[x-1][y] = true;
            }
            if (x+1 < h && isVisited[x+1][y]==false && map[x+1][y]) {
              q.push(make_pair(x+1, y));
              isVisited[x+1][y] = true;
            }
            if (y-1 >= 0 && isVisited[x][y-1]==false && map[x][y-1]) {
              q.push(make_pair(x, y-1));
              isVisited[x][y-1] = true;
            }
            if (y+1 < w && isVisited[x][y+1]==false && map[x][y+1]) {
              q.push(make_pair(x, y+1));
              isVisited[x][y+1] = true;
            }
            if (x-1 >= 0 && y-1 >= 0 && isVisited[x-1][y-1]==false && map[x-1][y-1]) {
              q.push(make_pair(x-1, y-1));
              isVisited[x-1][y-1] = true;
            }
            if (x+1 < h && y+1 < w && isVisited[x+1][y+1]==false && map[x+1][y+1]) {
              q.push(make_pair(x+1, y+1));
              isVisited[x+1][y+1] = true;
            }
            if (x+1 < h && y-1 >= 0 && isVisited[x+1][y-1]==false && map[x+1][y-1]) {
              q.push(make_pair(x+1, y-1));
              isVisited[x+1][y-1] = true;
            }
            if (x-1 >= 0 && y+1 < w && isVisited[x-1][y+1]==false && map[x-1][y+1]) {
              q.push(make_pair(x-1, y+1));
              isVisited[x-1][y+1] = true;
            }
          }

          island++;
        }
      }
    }

    islands.push_back(island);
  }

  for (auto e : islands)
    printf("%d\n", e);

  return 0;
}
