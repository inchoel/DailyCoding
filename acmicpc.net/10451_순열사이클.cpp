#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int countCycle (const vector<int>& v, size_t n) {
  int start, temp, cnt=0;
  bool isVisited[n];
  for (size_t i=1; i<=n; i++)
    isVisited[i] = false;
  
  for (size_t i=1; i<=n; i++) {
    if (isVisited[i] == true)
      continue;

    start = temp = v[i];
    isVisited[temp] = true;
    do {
      temp = v[temp];
      isVisited[temp] = true;
    } while (start != temp);
    cnt++;
  }

  return cnt;
}

int main() {
  vector<int> ans;
  int t, n;
  scanf (" %d", &t);
  while (t--) {
    scanf (" %d", &n);
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
      scanf (" %d", &v[i]);
    }
    ans.push_back(countCycle (v, n));
  }

  for (auto e : ans)
    printf("%d\n", e);

  return 0;
}
