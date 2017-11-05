#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    scanf (" %d", &v[i]);

  if (prev_permutation(v.begin(), v.end())) {
    for (auto& e : v)
      printf("%d ", e);
  }
  else
    printf("-1");

  printf("\n");

  return 0;
}
