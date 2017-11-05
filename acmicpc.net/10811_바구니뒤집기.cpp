#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int a[100];
  int n, m, i, j;
  scanf (" %d %d", &n, &m);

  for (int h=0; h<n; h++) {
    a[h] = h+1;
  }

  for (int k=0; k<m; k++) {
    scanf (" %d %d", &i, &j);
    reverse(a+i-1, a+j);
  }

  printf("%d", a[0]);
  for (int x=1; x<n; x++)
    printf(" %d", a[x]);
  printf("\n");

  return 0;
}
