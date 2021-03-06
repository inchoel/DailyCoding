#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int n, m;

int main() {
  scanf (" %d %d", &n, &m);

  vector<long long unsigned int> v(n);
  for (int i=0; i<n; i++) {
    scanf (" %llu", &v[i]);
  }

  long long unsigned int tmp;
  for (int i=0; i<m; i++) {
    sort (v.begin(), v.end());
    tmp = v[0] + v[1];
    v[0] = tmp;
    v[1] = tmp;
  }

  long long unsigned int sum = 0;
  for (auto e : v) {
    sum += e;
  }

  printf("%llu\n", sum);

  return 0;
}
