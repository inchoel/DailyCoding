/*
1) 형틀은 수평부분과 수직부분으로 구성되며, 모두 연결되어야 한다.
2) 형틀의 수평부분은 반드시 어떤 기둥의 윗면과 닿아야 한다.
3) 형틀의 수직부분은 반드시 어떤 기둥의 옆면과 닿아야 한다.
4) 형틀의 가장자리는 땅에 닿아야 한다.
5) 비가 올 때 물이 고이지 않도록 형틀의 어떤 부분도 오목하게 들어간 부분이 없어야 한다.
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool comp (const pair<int, int>& a, const pair<int, int>& b) {
  return (a.second > b.second) ? true : false;
}

int main()
{
  int n;
  scanf (" %d", &n);

  int l, h;
  pair<int, int> highest(0, 0);
  vector<pair<int, int>> v;
  for (int i=0; i<n; i++) {
    scanf (" %d %d", &l, &h);
    v.push_back(make_pair(l, h));
    if (highest.second < h) {
      highest.first = l;
      highest.second = h;
    }
    else if (highest.second == h) {
      if (highest.first > l)
        highest.first = l;
    }
  }

  sort (v.begin(), v.end());
  auto it_high = v.begin();
  for(it_high=v.begin(); it_high!=v.end(); it_high++) {
    if (*it_high == highest)
      break;
  }
  sort (v.begin(), it_high, comp);
  sort (it_high+1, v.end(), comp);
  // for (auto& e : v)
  //   printf("%d %d\n", e.first, e.second);

  int area = highest.second;
  int loc = highest.first;
  for (auto it=v.begin(); it!=it_high; it++) {
    if (loc < it->first)
      continue;

    area += (loc - it->first) * it->second;
    loc = it->first;
  }
  loc = highest.first;
  for (auto it2=it_high; it2!=v.end(); it2++) {
    if (loc > it2->first)
      continue;

    area += (it2->first - loc) * it2->second;
    loc = it2->first;
  }

  printf("%d\n", area);

  return 0;
}
