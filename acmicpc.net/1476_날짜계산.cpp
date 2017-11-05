#include <cstdio>
using namespace std;

int main() {
  int e, s, m;
  int ee=1, ss=1, mm=1, year=1;
  scanf (" %d %d %d", &e, &s, &m);

  while (!(e==ee && s==ss && m==mm)) {
    ee++;
    ss++;
    mm++;

    if (ee >= 16)
      ee = 1;
    if (ss >= 29)
      ss = 1;
    if (mm >= 20)
      mm = 1;

    year++;
    // printf("%d %d %d\n", ee, ss, mm);
  }

  printf("%d\n", year);

  return 0;
}
