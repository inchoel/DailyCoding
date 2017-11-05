#include <cstdio>
#include <vector>
using namespace std;

int main()
{
  int a, b;
  vector<int> v;

  while ( scanf("%d %d", &a, &b) == 2 ) {
    v.push_back(a+b);
  }

  for (auto& e : v)
    printf("%d\n", e);

  return 0;
}
