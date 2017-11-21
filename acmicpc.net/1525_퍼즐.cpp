#include <cstdio>
#include <queue>
#include <array>
#include <bitset>
using namespace std;

int getShortestMove(array<int, 9>& a) {
  int ans = -1, pos;
  bitset<9> visited("000000000");
  bitset<9> puzzle("111111111");
  queue<int> q;
  for (int i=0; i<9; i++) {
    if (a[i] == 0) {
      q.push(i);
      visited.set(i);
      puzzle.set(i, 0);
      break;
    }
  }

  int q_size, down, right;
  while (!q.empty()) {
    q_size = q.size();
    // printf("q_size=%d\n", q_size);
    ans++;
    while (q_size--) {
      pos = q.front();
      q.pop();

      down = 3*(pos/3+1) + pos%3;
      right = 3*(pos/3) + (pos%3 + 1);

      // printf("pos=%d, down=%d, right=%d\n", pos, down, right);
      if (down == 9 || right == 9)
        return ans;

      if ((pos/3+1) < 3 && visited.test(down)==0) {
        q.push(down);
        visited.set(down);
      }
      if ((pos%3+1) < 3 && visited.test(right)==0) {
        q.push(right);
        visited.set(right);
      }
    }
  }

  return ans;
}

int main() {
  array<int, 9> a;

  for (int i=0; i<3; i++)
    scanf (" %d %d %d", &a[3*i], &a[3*i+1], &a[3*i+2]);

  printf("%d\n", getShortestMove(a));
  return 0;
}
