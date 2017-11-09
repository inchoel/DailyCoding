#include <cstdio>
#include <algorithm>

#include <thread>
#include <chrono>
using namespace std;

void findPrime (vector<int>& v) {
  int num[10001];
  for (int i=0; i<=9999; i++) {
    num[i] = i;
  }

  int idx;
  for (int i=2; i<=sqrt(9999); i++) {
    for (int j=2; j<=9999; j++) {
      idx = j*j;

      if (num[idx] == -1)
        continue;

      if (num[idx] != i && (num[idx] % i) == 0) {
        num[idx] = -1;
      }
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
  // scanf (" %d", &t);

  // 우선 소수를 구하자
  vector<int> prime;
  findPrime(prime);

  for (size_t i=0; i<prime.size()-500; i++)
    printf("%d ", prime[i]);

  // 구간내의  소수들 중에서 old, new 조건에 맞는 수를 찾으면서 간격을 구하자
  // while (t--) {
  //   scanf (" %d %d", &old_pw, &new_pw);
  // }

  return 0;
}
