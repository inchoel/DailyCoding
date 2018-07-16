#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool map[102][102];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int end_x = 0;
int end_y = 0;

vector<int> dragon;


void drawDragon(vector<int>& dragon) {
  int size = (int)dragon.size();

  for (int i=size-1; i>=0; i--) {
    int dir = (dragon[i]+1)%4;

    end_x = end_x + dx[dir];
    end_y = end_y + dy[dir];

    map[end_x][end_y] = true;

    dragon.push_back(dir);
  }
}

int main(void) {
  int n;
  scanf (" %d", &n);

  for (int i=0; i<n; i++) {
    int x, y, d, g;
    // scanf (" %d %d %d %d", &x, &y, &d, &g);
    scanf (" %d %d %d %d", &y, &x, &d, &g);
    end_x = x;
    end_y = y;
    map[end_x][end_y] = true;
    end_x = x + dx[d];
    end_y = y + dy[d];
    map[end_x][end_y] = true;
    dragon.clear();
    dragon.push_back(d);

    for (int i=0; i<g; i++)
      drawDragon(dragon);
  }

  int ans = 0;
  for (int i=0; i<=100; i++) {
    for (int j=0; j<=100; j++) {
      if (map[i][j]==true &&
          map[i][j+1]==true &&
          map[i+1][j]==true &&
          map[i+1][j+1]==true)
        ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
