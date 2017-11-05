#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
  int n, input;
  scanf(" %d", &n);

  vector<int> v;
  for (int i=0; i<n; i++) {
    scanf(" %d", &input);
    v.push_back(input);
  }

  // sort(v.begin(), v.end(), greater<int>());
  sort(v.begin(), v.end());

  int tmp = v[0];
  printf("%d", tmp);
  for (auto& e : v) {
    if (tmp != e) {
      printf(" %d", e);
      tmp = e;
    }
  }
  printf("\n");

  return 0;
}
