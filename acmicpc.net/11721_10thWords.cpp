#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  char c[101];
  scanf ("%s", c);

  int j = 0;
  for (int i=0; i<strlen(c); i++) {
    if (j == 10) {
      j = 0;
      printf("\n");
    }

    printf("%c", c[i]);
    j++;
  }
  printf("\n");

  return 0;
}
