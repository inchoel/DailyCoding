#include <cstdio>
#include <vector>
using namespace std;

int main() {
  unsigned int n;
  scanf (" %d", &n);

  vector<unsigned int> v;

  unsigned int num = n;
  unsigned int tmp;
  unsigned int i=2;
  while (num!=1 && i<=10000000) {
    tmp = num % i;
    if (tmp) {
      i++;
      continue;
    }

    num = num / i;
    v.push_back(i);
  }

  for (auto e : v)
    printf("%u\n", e);

  return 0;
}
