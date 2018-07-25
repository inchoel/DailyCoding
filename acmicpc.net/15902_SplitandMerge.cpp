#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int l, n, m;

int main(void) {
  scanf (" %d", &l);
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    scanf (" %d", &v[i]);

  scanf (" %d", &m);
  vector<int> vv(m);
  for (int i=0; i<m; i++)
    scanf (" %d", &vv[i]);

  return 0;
}
