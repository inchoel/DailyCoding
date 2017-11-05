#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
  int n, m, num;
  scanf(" %d", &n);

  set<int> s;
  map<int, int> dup;
  pair<set<int>::iterator, bool> ret;
  for (int i=0; i<n; i++) {
    scanf(" %d", &num);
    ret = s.emplace(num);
    if (ret.second == false)
      dup[num]++;
    else
      dup[num] = 1;
  }

  vector<int> v;
  scanf (" %d", &m);
  for (int j=0; j<m; j++) {
    scanf(" %d", &num);
    if (s.find(num) != s.end())
      v.push_back(dup[num]);
    else
      v.push_back(0);
  }

  for (auto& e : v)
    printf("%d ", e);
  printf("\n");

  return 0;
}
