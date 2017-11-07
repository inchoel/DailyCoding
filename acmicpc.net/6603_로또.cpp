#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int LOTTO = 6;
vector<int> vv(LOTTO);

void print () {
  for (auto& e : vv)
    printf("%d ", e);
  printf("\n");
}

void combination (int n, int r, int i, vector<int>& v, int index) {
  if (r == 0) {
    print ();
    return;
  }
  else if (n == index) {
    return;
  }

  vv[i] = v[index];
  combination (n, r-1, i+1, v, index+1);
  combination (n, r, i, v, index+1);
}

int main() {
  int k;
  while (1) {
    scanf (" %d", &k);
    if (k==0)
      break;

    vector<int> vv(LOTTO);
    vector<int> v(k);
    for (int i=0; i<k; i++)
      scanf (" %d", &v[i]);

    combination (k, LOTTO, 0, v, 0);
    printf("\n");
  }

  return 0;
}
