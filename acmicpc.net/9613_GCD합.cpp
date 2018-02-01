#include <cstdio>
#include <vector>
using namespace std;

int gcd (int a, int b) {
  int tmp;
  do {
    tmp = b % a;
    b = a;
    a = tmp;
  } while (a!=0);

  return b;
}

int main() {
  int t;
  char c;
  int num[101];
  vector<long long int> sum;

  scanf (" %d", &t);
  while (t--) {
    int size;
    scanf (" %d", &size);
    for (int s=0; s<size; s++) {
      scanf (" %d", &num[s]);
    }

    long long int s = 0;
    for (int i=0; i<size-1; i++) {
      for (int j=i+1; j<size; j++) {
        s += gcd (min(num[i], num[j]), max(num[i], num[j]));
      }
    }

    sum.push_back(s);
  }

  for (auto e : sum)
    printf("%lld\n", e);
  return 0;
}
