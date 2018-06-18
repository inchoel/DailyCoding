#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int tc, w, h;
  scanf (" %d", &tc);

  while (tc--) {
    scanf (" %d %d", &w, &h);
    bool map[h][w];
    bool isVisited[h][w];
    for (int i=0; i<h; i++) {
      for (int j=0; j<w; j++) {
        scanf (" %d", &map[i][j]);
        isVisited[i][j] = false;
      }
    }
  }

  return 0;
}
