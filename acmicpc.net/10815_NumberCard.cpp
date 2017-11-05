#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main()
{
  int n, m, num;
  set<int> s;
  vector<int> v;

  scanf(" %d", &n);
  for (int i=0; i<n; i++) {
    scanf(" %d", &num);
    s.emplace(num);
  }

  scanf (" %d", &m);
  for (int j=0; j<m; j++) {
    scanf (" %d", &num);
    if (s.find(num) != s.end())
      v.push_back(1);
    else
      v.push_back(0);
  }

  for (auto& e : v)
    printf("%d ", e);
  printf("\n");

  return 0;
}
