#include <cstdio>
#include <map>
using namespace std;

int main()
{
  int n, v, num;
  map<int, int> m;

  scanf (" %d", &n);

  for (int i=0; i<n; i++) {
    scanf (" %d", &num);
    m[num]++;
  }

  scanf (" %d", &v);

  printf("%d\n", m[v]);

  return 0;
}
