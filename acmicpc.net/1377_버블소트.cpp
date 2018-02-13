#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf(" %d", &n);

  vector<pair<int, int>> a(n);
  for (int i=0; i<n; i++) {
    scanf (" %d", &(a[i].first));
    a[i].second = i;
  }

  sort (a.begin(), a.end());

  int ans = 0;
  for (int i=0; i<n; i++) {
    if (ans < a[i].second - i)
      ans = a[i].second - i;
  }

  printf("%d\n", ans+1);

  return 0;
}
