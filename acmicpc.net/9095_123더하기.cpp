#include <cstdio>
using namespace std;

// N의 범위가 충분히 작다. 그래서 완전탐색으로도 무리가 없다.
// 중복순열의 문제이다.

int N;

void multisetPermutation (const int sum, int& count) {
  for (int i=1; i<=3; i++) {
    if ((sum+i) == N) {
      count++;
      break;
    }
    else if ((sum+i) > N) { // i 의 값은 1->2->3과 같이 증가함으로 다음 i를 비교할 필요는 없다.
      break;
    }

    multisetPermutation (sum+i, count);
  }
}

int main() {
  int tc, ans;
  scanf (" %d", &tc);

  while (tc--) {
    scanf (" %d", &N);
    ans = 0;
    multisetPermutation (0, ans);
    printf ("%d\n", ans);
  }

  return 0;
}
