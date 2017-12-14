#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

static vector<int> v = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
int l, c;

void bfs (int i, vector<char>& c, vector<bool>& visited) {
  do {
    lock[lock_i] = crypto[i];
    lock_i++;
  } while (lock_i<4);
}

int main() {
  scanf (" %d %d", &l, &c);

  vector<char> crypto(c);
  for (int i=0; i<c; i++)
    scanf (" %c", &crypto[i]);

  sort (crypto.begin(), crypto.end());

  vector<bool> isVisited(c, false);

  for (int i=0; i<4; i++) {
    bfs (i, crypto, isVisited);
  }

  return 0;
}
