#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n, num;
  scanf (" %d", &n);

  vector<int> v;
  for (int i=0; i<n; i++) {
    scanf (" %d", &num);
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for (auto& e : v)
    printf("%d\n", e);

  return 0;
}
