#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main()
{
  int n, x;
  set<int> s;
  vector<int> v;

  scanf (" %d", &n);
  for (int i=0; i<n; i++) {
    scanf (" %d", &x);
    if (x)
      s.emplace (x);
    else {
      if (s.empty())
        v.push_back(0);
      else {
        auto it = s.begin();
        v.push_back(*it);
        s.erase(it);
      }
    }
  }

  for (auto& e : v)
    printf("%d\n", e);

  return 0;
}
