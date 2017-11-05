#include <cstdio>
#include <cstdlib>
#include <utility>
using namespace std;

int main()
{
  int n, m, i, j, k;
  scanf (" %d %d", &n, &m);

  int* a = (int *)malloc(sizeof(int)*(n+1));
  for (k=0; k<n; k++)
    a[k] = (k+1);

  for (k=0; k<m; k++) {
    scanf (" %d %d", &i, &j);
    swap (a[i-1], a[j-1]);
  }

  printf("%d", a[0]);
  for (k=1; k<n; k++)
    printf(" %d", a[k]);
  printf("\n");

  return 0;
}
