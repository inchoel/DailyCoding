#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  bool ret;

  if (a.first == b.first) {
    ret = (a.second < b.second) ? true : false;
  }
  else {
    ret = (a.first < b.first) ? true : false;
  }

  return ret;
}

int main()
{
  int n;
  scanf (" %d", &n);

  vector<pair<int, int>> v;
  int x, y;
  for (int i=0; i<n; i++) {
    scanf (" %d %d", &x, &y);
    v.push_back(make_pair(x, y));
  }

  sort (v.begin(), v.end(), comp);

  for (auto& p : v)
    printf("%d %d\n", p.first, p.second);

  return 0;
}
