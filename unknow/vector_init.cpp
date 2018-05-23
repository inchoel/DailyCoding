#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> v(10, 2);

  for (auto e : v)
    printf("%d\n", e);
  return 0;
}
