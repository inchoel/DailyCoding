#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int apt[26][26];

int aptNumber(const int i, const int j, int cnt) {
  if (i<0 || j<0)
    return cnt;

  if (apt[i][j]==0)
    return cnt;

  cnt++;
  apt[i][j] = 0;

  cnt = aptNumber(i, j-1, cnt);
  cnt = aptNumber(i, j+1, cnt);
  cnt = aptNumber(i-1, j, cnt);
  cnt = aptNumber(i+1, j, cnt);
  return cnt;
}

int main(void) {
  int n;
  scanf (" %d", &n);

  char input[n+1];
  for (int i=0; i<n; i++) {
    scanf (" %s", input);
    for (int j=0; j<n; j++) {
      apt[i][j] = (int)(input[j] - '0');
    }
  }

  vector<int> ans;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (apt[i][j]) {
        ans.push_back(aptNumber(i, j, 0));
      }
    }
  }

  printf("%d\n", ans.size());
  sort (ans.begin(), ans.end());
  for (auto e : ans)
    printf("%d\n", e);

  return 0;
}
