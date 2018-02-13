#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <stack>
using namespace std;

int n, m, v;

void bfs (const vector<pair<int,int>>& data) {
  array<bool, 1000> a;
  a.fill(false);
  queue<int> q;
  q.push(v);

  int vv;
  while (!q.empty()) {
    vv = q.front();
    q.pop();
    if (a[vv])
      continue;

    printf("%d ", vv);
    a[vv] = true;

    int first, second;
    for (int i=0; i<m; i++) {
      first = data[i].first;
      second = data[i].second;
      if (first == vv) {
        if (a[second] == false)
          q.push(second);
      }
      else if (second == vv) {
        if (a[first] == false)
          q.push(first);
      }
    }
  }
  printf("\n");
}

void dfs (const vector<pair<int, int>>& data) {
  array<bool, 1000> a;
  a.fill(false);
  stack<int> s;

  s.push (v);
  a[v] = true;
  printf("%d ", v);

  int vv;
  while (!s.empty()) {
    vv = s.top();

    bool found = false;
    int first, second;
    for (int i=0; i<m; i++) {
      first = data[i].first;
      second = data[i].second;
      if (first == vv) {
        if (a[second] == false) {
          s.push(second);
          a[second] = true;
          found = true;
          printf("%d ", second);
          break;
        }
      }
      else if (second == vv) {
        if (a[first] == false) {
          s.push(first);
          a[first] = true;
          found = true;
          printf("%d ", first);
          break;
        }
      }
    }

    if (found == false)
      s.pop();
  }
  printf("\n");
}

int main() {
  scanf (" %d %d %d", &n, &m, &v);

  vector<pair<int,int>> data(m);
  for (int i=0; i<m; i++) {
    scanf (" %d %d", &data[i].first, &data[i].second);
  }

  dfs(data);
  bfs(data);

  return 0;
}
