#include <cstdio>
#include <bitset>
using namespace std;

int main() {
  int m;
  scanf (" %d", &m);

  bitset<21> b;
  char cmd[10];
  int num;
  for (int i=0; i<m; i++) {
    scanf (" %s %d", cmd, &num);
    switch (cmd[0]) {
      case 'a':
        if (cmd[1] == 'd')
          b.set (num);
        else if (cmd[1] == 'l')
          b.set ();
        break;
      case 'r':
        b.set (num, 0);
        break;
      case 'c':
        printf("%d\n", (b.test(num)) ? 1 : 0);
        break;
      case 't':
        b.flip (num);
        break;
      case 'e':
        b.reset ();
        break;
    }
  }

  return 0;
}
