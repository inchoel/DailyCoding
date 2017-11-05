#if 0
// 시간초과 ㅜ.ㅜ
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, type;
  scanf (" %d", &n);

  vector<int> v(n);
  for (int i=0; i<n; i++)
    v[i] = i+1;

  scanf (" %d", &type);
  switch (type) {
    case 1:
      {
        int count;
        scanf (" %d", &count);

        while (count--) {
          next_permutation(v.begin(), v.end());
        }
        for (auto& e : v)
          printf("%d ", e);
        printf("\n");
      }
      break;

    case 2:
      {
        int cnt = 1;
        vector<int> vv(n);
        for (int i=0; i<n; i++)
          scanf (" %d", &vv[i]);

        do {
          if (v == vv)
            break;

          cnt++;
        } while (next_permutation(v.begin(), v.end()));
        printf("%d\n", cnt);
      }
      break;

    default:
      break;
  }

  return 0;
}
#else
#include <cstdio>
#include <vector>
using namespace std;

#define MAX (1000)
int factorial[21];

int main() {
  int n, type;
  scanf (" %d", &n);

  factorial[0] = 1;
  factorial[1] = 1;
  for (int i=2; i<=n; i++) {
    factorial[i] = i * factorial[i-1];
  }

  vector<int> v(n);
  for (int i=0; i<n; i++)
    v[i] = i+1;

  scanf (" %d", &type);
  switch (type) {
    case 1:
      {
        int count;
        scanf (" %d", &count);
        for (int i=1; i<=n; i++) {
          int j=1;
          while (factorial[n-i] < k) {
            j++;
            k -= factorial[i-1];
          }
          int h=0;
          while (j > 0) {
            if (v[h--] != MAX)
              j--;
          }
          printf("%d", v[h]);
          v[h] = MAX;
        }
      }
      break;

    case 2:
      {
        int cnt = 1;
        vector<int> vv(n);
        for (int i=0; i<n; i++)
          scanf (" %d", &vv[i]);

        do {
          if (v == vv)
            break;

          cnt++;
        } while (next_permutation(v.begin(), v.end()));
        printf("%d\n", cnt);
      }
      break;

    default:
      break;
  }

  return 0;
}
#endif
