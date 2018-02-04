#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

void converter (unsigned long long int decimal, int base, stack<int> &s) {
  do {
    s.push(decimal % base);
    decimal = decimal / base;
  } while (decimal != 0);
}

int main() {
  int a, b;
  scanf (" %d %d", &a, &b);

  int m;
  scanf (" %d", &m);

  unsigned long long int decimal=0;
  int posNum[26];
  for (int i=1; i<=m; i++) {
    scanf (" %d", &posNum[i]);
    decimal += (posNum[i] * pow(a, m-i));
  }

  stack<int> s;
  converter (decimal, b, s);

  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
  printf ("\n");

  return 0;
}
