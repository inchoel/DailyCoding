#if 1
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define ROOT (1)

int n;
vector<pair<int, int>> v;

bool isConnectedRoot(const int node) {
  int n1, n2;
  for (int i=0; i<n-1; i++) {
    n1 = v[i].first;
    n2 = v[i].second;
    if (n1 == node) {
      if (n2 == ROOT)
        return true;
      else
        return isConnectedRoot(n2);
    }
    else if (n2 == node) {
      if (n1 == ROOT)
        return true;
      else
        return isConnectedRoot(n1);
    }
  }
  return false;
}

int findParent(const int node) {
  int n1, n2;
  for (int i=0; i<n-1; i++) {
    n1 = v[i].first;
    n2 = v[i].second;

    if (n1 == node) {
      if (isConnectedRoot(n2))
        return n2;
    }
    else if (n2 == node) {
      if (isConnectedRoot(n1))
        return n1;
    }
  }
  return -1;
}

int main(void) {
  scanf (" %d", &n);

  int a, b;
  for (int i=0; i<n-1; i++) {
    scanf (" %d %d", &a, &b);
    v.push_back (make_pair(a, b));
  }

  for (int i=2; i<=n; i++)
    printf("%d\n", findParent(i));

  return 0;
}

#else
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> m;

bool isConnectedRoot(const int node) {
  vector<int> v = m[node];
  for (auto e : v) {
    if (e==1 || isConnectedRoot(e))
      return true;
  }

  return false;
}

int findParent(int node) {
  vector<int> v = m[node];
  size_t size = v.size();

  if (size == 1)
    return v[0];

  for (auto e: v) {
    if (e==1)
      return 1;

    if (isConnectedRoot(e))
      return e;
  }

  return -1;
}

int main(void) {
  int n;
  scanf (" %d", &n);

  vector<int> v;
  int n1, n2;
  for (int i=1; i<n; i++) {
    scanf (" %d %d", &n1, &n2);
    v = m[n1];
    v.push_back(n2);
    m[n1] = v;

    v = m[n2];
    v.push_back(n1);
    m[n2] = v;
  }

  for (int j=2; j<=n; j++) {
    printf("%d\n", findParent(j));
  }

  return 0;
}
#endif
