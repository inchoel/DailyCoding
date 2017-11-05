#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <limits>

#include <thread>
#include <chrono>
using namespace std;

int H;
int W;
int elapsed_time;
char map[500][510];

void input_data() {
  int i;
  cin >> H >> W;
  for(i=0 ; i<H ; i++) {
    cin >> map[i];
  }
}

bool isValid (vector<pair<pair<int, int>, vector<pair<int, int>>>>& v, int h, int w) {
  bool valid = true;
  for (auto& p : v) {
    if (p.first.first == h && p.first.second == w) {
      valid = false;
      break;
    }

    for (auto& pp : p.second) {
      if (pp.first == h && pp.second == w) {
        valid = false;
        break;
      }
    }
  }
  return valid;
}

void getPath (pair<int, int> cur, vector<pair<pair<int, int>, vector<pair<int, int>>>>& v, int& ans) {
  int h = cur.first;
  int w = cur.second;
  vector<pair<int, int>> vv;
  if (h-1 >= 0 && map[h-1][w]!='X') {
    if (isValid(v, h-1, w))
      vv.push_back(make_pair(h-1, w));
  }
  if (h+1 < H && map[h+1][w]!='X') {
    if (isValid(v, h+1, w))
      vv.push_back(make_pair(h+1, w));
  }
  if (w-1 >= 0 && map[h][w-1]!='X') {
    if (isValid(v, h, w-1))
      vv.push_back(make_pair(h, w-1));
  }
  if (w+1 < W && map[h][w+1]!='X') {
    if (isValid(v, h, w+1))
      vv.push_back(make_pair(h, w+1));
  }

  v.push_back(make_pair(cur, vv));
  elapsed_time++;

  // printf("cur (%d, %d), path=%lu\n", cur.first, cur.second, vv.size());
  for (auto& e : vv) {
    // printf("neighbor : (%d %d), elapsed=%d\n", e.first, e.second, elapsed_time);
    // this_thread::sleep_for(chrono::seconds(1));
    if (e.first == H-1 && e.second == W-1) {
      if (ans == -1 || (ans > 0 && ans > elapsed_time)) {
        ans = elapsed_time;
        printf("find path: %d\n", ans);
      }
      continue;
    }

    getPath (e, v, ans);
  }

  // map[cur.first][cur.second] = 'X';

  elapsed_time--;
}

void solve(int& ans) {
  vector<pair<pair<int, int>, vector<pair<int, int>>>> v;
  getPath (make_pair(0, 0), v, ans);
}

int main() {
  int ans = -1;
  input_data();

  solve(ans);

  cout << ans << endl;
  return 0;
}
