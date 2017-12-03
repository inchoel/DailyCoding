#include <cstdio>
#include <queue>
#include <array>
#include <bitset>
using namespace std;

inline void swap (int& a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int getShortestMove(array<int, 9>& a) {
  int ans = 0;
  array<int, 9> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  if (goal == a)
    return 0;

  queue<pair<int, array<int, 9>>> q;
  for (int i=0; i<9; i++) {
    if (a[i] == 0) {
      q.push(make_pair(i, a));
      break;
    }
  }

  int q_size, x, y, up, down, left, right;
  array<int, 9> puzzle;
  while (!q.empty()) {
    q_size = q.size();
    ans++;
    while (q_size--) {
      pair<int, array<int, 9>> p = q.front();
      q.pop();
      x = p.first/3;
      y = p.first%3;
      puzzle = p.second;

      up = 3*(x-1) + y;
      down = 3*(x+1) + y;
      left = 3*x + (y-1);
      right = 3*x + (y+1);

      if ((x-1) >= 0) {
        array<int, 9> puz = puzzle;
        swap (puz[p.first], puz[up]);
        q.push(make_pair(up, puz));
        if (goal==puz)
          return ans;
      }
      if ((x+1) < 3) {
        array<int, 9> puz = puzzle;
        swap (puz[p.first], puz[down]);
        q.push(make_pair(down, puz));
        if (goal==puz)
          return ans;
      }
      if ((y-1) >= 0) {
        array<int, 9> puz = puzzle;
        swap (puz[p.first], puz[left]);
        q.push(make_pair(left, puz));
        if (goal==puz)
          return ans;
      }
      if ((y+1) < 3) {
        array<int, 9> puz = puzzle;
        swap (puz[p.first], puz[right]);
        q.push(make_pair(right, puz));
        if (goal==puz)
          return ans;
      }
    }
  }

  return -1;
}

int main() {
  array<int, 9> a;

  for (int i=0; i<3; i++)
    scanf (" %d %d %d", &a[3*i], &a[3*i+1], &a[3*i+2]);

  printf("%d\n", getShortestMove(a));
  return 0;
}
