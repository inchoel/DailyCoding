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
    // scanf (" %llu", &v[i]);
    v[i] = 1000000;
  }

  int tmp;
  for (int i=0; i<m; i++) {
    sort (v.begin(), v.end());
    tmp = v[0] + v[1];
    v[0] = tmp;
    v[1] = tmp;
  }

  long long unsigned int max =numeric_limits<long long unsigned int>::max();
  long long unsigned int sum = 0;
  for (auto e : v) {
    if ((max - e) < sum)
      printf("overflow----\n");

    sum += e;
  }

  printf("%llu\n", sum);

  return 0;
}
