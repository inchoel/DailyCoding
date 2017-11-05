#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
  int n, m, start, end, val;
  scanf(" %d %d", &n, &m);

  char* arr = (char*) malloc (sizeof(char)*(n+1));
  memset (arr, sizeof(char)*n, 0);
  for (int i=1; i<=m; i++) {
    scanf (" %d %d %d", &start, &end, &val);
    for (int j=start; j<=end; j++)
      arr[j] = val;
  }

  for (int k=1; k<=n; k++)
    printf("%d ", arr[k]);
  printf("\n");

  free(arr);
  arr = NULL;

  return 0;
}
