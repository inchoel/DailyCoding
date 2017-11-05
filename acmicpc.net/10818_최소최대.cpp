#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf (" %d", &n);

  vector<int> v;
  int num;
  for (int i=0; i<n; i++) {
    scanf (" %d", &num);
    v.push_back(num);
  }

  sort (v.begin(), v.end());

  printf("%d %d\n", v[0], v[v.size()-1]);

  return 0;
}
