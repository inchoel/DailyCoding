#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int a, p;

int pow (int n, const int p) {
  for (int i=1; i<p; i++) {
    n *= n;
  }
  return n;
}

int calcNext(int num) {
  int next=0;
  while (num) {
    next += pow(num%10, p);
    num = num / 10;
  }
  return next;
}

int main(void) {
  scanf (" %d %d", &a, &p);

  vector<int> v;
  int next = a;
  v.push_back(next);

  size_t ans=0;
  while (ans==0) {
    next = calcNext (next);
    for (size_t i=0; i<v.size(); i++) {
      if (v[i] == next) {
        ans = i;
        break;
      }
    }
    v.push_back(next);
  }

  printf("%lu\n", ans);
  return 0;
}
