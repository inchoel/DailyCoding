#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v(100000+1);

int main() {
  int n, m;
  scanf (" %d %d", &n, &m);

  int m_cur, m_pre=0, count=1;
  scanf (" %d", &m_cur);
  m_pre = m_cur;
  v[m_cur] = make_pair(1, 1);

  for (int i=1; i<n; i++) {
    scanf (" %d", &m_cur); 

    pair<int, int> d = v[m_cur];
    d.first++;
    v[m_cur] = d;

    if (m_cur == m_pre) {
      count++;
    }
    else {
      pair<int, int> data = v[m_pre];
      if (data.second < count)
        data.second = count;

      v[m_pre] = data;

      count = 1;
    }

    m_pre = m_cur;
  }

  int max = 0, value, popular;
  for (int i=1; i<=m; i++) {
    pair<int, int> e = v[i];
    value = e.first * e.second;
    if (max < value) {
      max = value;
      popular = i;
    }
    else if (max == value) {
      if (popular > i)
        popular = i;
    }
  }

  printf("%d\n", popular);

  return 0;
}
