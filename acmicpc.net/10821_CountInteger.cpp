#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
  char str[101];
  scanf (" %s", str);

  int count = 0;
  char* next = strtok (str, ",");
  while (next != NULL) {
    count++;
    next = strtok(NULL, ",");
  }

  printf("%d\n", count);

  return 0;
}
