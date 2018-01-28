#include <cstdio>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  int c;

  while (b!=0) {
    c = a % b;
    a = b;
    b = c;
  }

  return a;
}

int main(void) {
  vector<int> ans;
  int t, a, b;
  scanf (" %d", &t);
  while (t--) {
    scanf (" %d %d", &a, &b);
    ans.push_back(a*b/gcd(max(a, b), min(a, b)));
  }

  for (auto e : ans)
    printf("%d\n", e);

  return 0;
}

