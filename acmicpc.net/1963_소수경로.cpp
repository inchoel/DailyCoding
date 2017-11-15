#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void findPrime (vector<int>& v) {
  int num[10001];
  for (int i=0; i<=9999; i++) {
    num[i] = i;
  }

  for (int i=2; i<=sqrt(9999); i++) {
    for (int j=i+i; j<=9999; j+=i) {
      if (num[j] == -1)
        continue;

      num[j] = -1;
    }
  }

  for (int i=1000; i<=9999; i++) {
    if (num[i] == -1)
      continue;

    v.push_back(num[i]);
  }
}

int main() {
  int t;
  scanf (" %d", &t);

  vector<int> prime;
  findPrime(prime);

  while (t--) {
    scanf (" %d %d", &old_pw, &new_pw);
  }

  return 0;
}
