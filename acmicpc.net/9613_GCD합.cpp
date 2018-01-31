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
  int num[100];
  vector<int> sum;

  scanf (" %d", &t);
  getchar(); // to get '\n' following 't'
  while (t--) {
    int size;
    scanf (" %d", &size);
    for (int s=0; s<size; s++) {
      scanf (" %d", &num[s]);
    }

    int s = 0;
    for (int i=0; i<size-1; i++) {
      for (int j=i+1; j<size; j++) {
        s += gcd (min(num[i], num[j]), max(num[i], num[j]));
      }
    }

    sum.push_back(s);
  }

  for (auto e : sum)
    printf("%d\n", e);
  return 0;
}
