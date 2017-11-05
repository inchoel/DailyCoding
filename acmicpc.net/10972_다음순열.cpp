#if 0
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    v[i] = i+1;

  vector<int> given(n);
  for (int i=0; i<n; i++)
    scanf (" %d", &given[i]);

  do {
    if (v == given)
      break;
   
  } while (next_permutation(v.begin(), v.end()));

  if (next_permutation (v.begin(), v.end())) {
    for (auto& e : v)
      printf("%d ", e);
    printf("\n");
  }
  else
    printf("-1\n");

  return 0;
}
#else
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

  if (next_permutation(v.begin(), v.end())) {
    for (auto& e : v)
      printf("%d ", e);
    printf("\n");
  }
  else
    printf("-1\n");
  return 0;
}
#endif
