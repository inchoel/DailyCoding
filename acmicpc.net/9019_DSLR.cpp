#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

array<bool, 10000> visited;
vector<string> op = {"D", "S", "L", "R"};

int D (const int n) {
  return (n*2 % 10000);
}

int S (const int n) {
  return ((n-1)!=0 ? n : 9999);
}

int L (const int n) {
  vector<int> v(4);
  v[0] = n/1000;
  v[1] = n%1000/100;
  v[2] = n%100/10;
  v[3] = n%10;
  return (v[1]*1000 + v[2]*100 + v[3]*10 + v[0]);
}

int R (const int n) {
  vector<int> v(4);
  v[0] = n/1000;
  v[1] = n%1000/100;
  v[2] = n%100/10;
  v[3] = n%10;
  return (v[3]*1000 + v[0]*100 + v[1]*10 + v[2]);
}

void DSLR(const int n, vector<int>& v) {
  v[0] = D(n);
  v[1] = S(n);
  v[2] = L(n);
  v[3] = R(n);
}

void getConvertCommand(const int a, const int b, vector<string>& ans) {
  int q_size, n;
  queue<pair<int, string>> q;
  q.push(make_pair(a, ""));

  visited.fill(false);
  vector<int> v(4);
  string cmd, c;
  while (!q.empty()) {
    q_size = q.size();
    pair<int, string> d = q.front();
    q.pop();
    n = d.first;
    cmd = d.second;
    while (q_size--) {
      DSLR(n, v);
      for (int i=0; i<4; i++) {
        if (visited[v[i]] == true)
          continue;

        c = cmd + op[i];
        if (v[i] == b) {
          ans.push_back(c);
          return;
        }
        q.push(make_pair(v[i], c));
        visited[v[i]] = true;
      }
    }
  }
}

int main() {
  int T, a, b;
  vector<string> ans;

  scanf (" %d", &T);
  while (T--) {
    scanf (" %d %d", &a, &b);
    getConvertCommand(a, b, ans);
  }

  for (auto& e : ans)
    printf("%s\n", e.c_str());

  return 0;
}
