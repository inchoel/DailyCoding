#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define ARR_MAX_SIZE (500001)

int main() {
  int a[ARR_MAX_SIZE];
  int n;
  scanf (" %d", &n);

  for (int k=1; k<=n; k++)
    scanf (" %d", &a[k]);

  bool change = false;
  int i;
  for (i=1; i<=n+1; i++) {
    change = false;
    for (int j=1; j<=n-i; j++) {
      if (a[j] > a[j+1]) {
        change = true;
        swap(a[j], a[j+1]);
      }
    }
    if (change == false) {
      break;
    }
  }
  cout << i << '\n';

  return 0;
}
