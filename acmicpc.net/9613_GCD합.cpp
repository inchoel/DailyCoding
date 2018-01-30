#include <cstdio>
#include <vector>
using namespace std;

int gcd (int a, int b) {
  if (a==0)
    return b;

  int c;
  do {
    c = b % a;
    b = a;
    a = c;
  } while (a!=0);

  return b;
}

int main() {
  int t;
  char c;
  vector<char> num;
  vector<int> sum;

  scanf (" %d", &t);
  getchar(); // to get '\n' following 't'
  while (t--) {
    do {
      c = getchar();
      if (c != ' ' && c != '\n')
        num.push_back(c);
    } while (c != '\n');

    int s = 0;
    int num_size = num.size();
    for (int i=0; i<num_size-1; i++) {
      for (int j=i+1; j<num_size; j++) {
        s += gcd (min(num[i], num[j]), max(num[i], num[j]));
      }
    }

    sum.push_back(s);
    num.clear();
  }

  for (auto e : sum)
    printf("%d\n", e);
  return 0;
}
