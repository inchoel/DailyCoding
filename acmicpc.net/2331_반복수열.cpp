#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int a, p;

int calcNext(int num) {
  int next=0;
  while (num) {
    next += (int)pow(num%10, p);
    num = num / 10;
  }
  // printf("%d\n", next);
  return next;
}

int main(void) {
  scanf (" %d %d", &a, &p);

  vector<int> v;
  v.push_back(a);

  int next = a;
  int ans=-1;
  while (ans==-1) {
    next = calcNext (next);
    for (int i=0; i<v.size(); i++) {
      if (next == v[i]) {
        ans = i;
        break;
      }
    }

    v.push_back(next);
  }

  printf("%d\n", ans);
  return 0;
}
