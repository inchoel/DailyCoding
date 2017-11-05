#include <cstdlib>
#include <algorithm>
using namespace std;

void showData(const int* a, const int n)
{
  printf("%d", a[0]);
  for (int h=1; h<n; h++)
    printf(" %d", a[h]);
  printf("\n");
}

int main()
{
  int n, m;
  int i, j, k;
  int a[100], tmp[100];

  scanf (" %d %d", &n, &m);

  int h;
  for (h=0; h<n; h++) {
    a[h] = h+1;
    tmp[h] = h+1;
  }

  for (h=0; h<m; h++) {
    scanf (" %d %d %d", &i, &j, &k);

    rotate(a+i-1, a+k-1, a+j);
#if 0
    copy (a+k-1, a+j, tmp+i-1);
    copy (a+i-1, a+k-1, tmp+i+(j-k));
    copy (tmp+i-1, tmp+j+1, a+i-1);
#endif
  }

  showData(a, n);

  return 0;
}
