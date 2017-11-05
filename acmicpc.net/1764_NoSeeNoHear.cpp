#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  char name[30];
  set<string> s;
  vector<string> v;

  scanf (" %d %d", &n, &m);
  for (int i=0; i<n; i++) {
    scanf (" %s", name);
    s.emplace (name);
  }

  for (int j=0; j<m; j++) {
    scanf (" %s", name);
    auto it = s.find(name);
    if (it != s.end())
      v.push_back(*it);
  }

  sort (v.begin(), v.end());
  printf("%lu\n", v.size());
  for (auto& e : v)
    printf("%s\n", e.c_str());

  return 0;
}
