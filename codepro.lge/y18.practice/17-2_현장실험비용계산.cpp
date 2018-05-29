#include <cstdio>
#include <vector>
using namespace std;

int N;
int ans;
vector<int> v;

void Solve() {
  int daytotal = 0;

  for (int i=0; i<N; i++) {
    daytotal = 0;
    if (v[i] < 3)
      continue;

    if (v[i] >= 3 && v[i] <= 6) {
      daytotal = 100;
    }
    else if (v[i] > 6 && v[i] <=24) {
      daytotal = (v[i] - 6)*50 + 100;
    }

    if (daytotal > 500)
      daytotal = 500;

    ans += daytotal;
  }

  if (ans >= 10000) {
    ans -= (ans/10);
  }
}

int main() {
  scanf (" %d", &N);
  v.resize(N);
  for (int i=0; i<N; i++) {
    scanf(" %d", &v[i]);
  }

  Solve();

  printf("%d\n", ans);
  return 0;
}
