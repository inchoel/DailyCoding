#include <cstdio>
#include <vector>
using namespace std;

int N;

int main() {
  scanf (" %d", &N);

  vector<int> d(N+1);
  d[0] = 1; // 2번째 루프에서 i=4, j=4인 경우고려를 위한것임.
  d[1] = 0;
  d[2] = 3;
  for(int i=4; i<=N; i+=2) {
    d[i] = d[i-2]*3;

    for (int j=4; j<=i; j+=2) {
      d[i] += d[i-j]*2;
    }
  }

  printf("%d\n", d[N]);
  return 0;
}
