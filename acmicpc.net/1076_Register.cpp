#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

int main()
{
  map<string, int> m = { {"black",  0},
                         {"brown",  1},
                         {"red",    2},
                         {"orange", 3},
                         {"yellow", 4},
                         {"green",  5},
                         {"blue",   6},
                         {"violet", 7},
                         {"grey",   8},
                         {"white",  9},
                       };

  long long int value = 0;
  char color[10];
  scanf(" %s", color);
  value = m[color] * 10;
  scanf(" %s", color);
  value += m[color];
  scanf(" %s", color);
  value = value * static_cast<int>(pow(10, m[color]));

  printf("%lld\n", value);

  return 0;
}
