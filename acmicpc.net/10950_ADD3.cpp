#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int n;
  int a, b;
  vector<int> sum;
  scanf ("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d %d", &a, &b);
    sum.push_back(a+b);
  }

  for (int i=0; i<n; i++)
    printf("Case #%d: %d\n", i+1, sum[i]);

  return 0;
}
