#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    v[i] = i+1;

  do {
    for (auto& e : v)
      printf ("%d ", e);
    printf("\n");
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}
