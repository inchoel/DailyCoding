#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
  int n;
  int sum = 0;
  char number[101];
  char c;

  scanf("%d", &n);
  scanf("%s", number);

  for (size_t i=0; i<strlen(number); i++) {
    c = number[i];
    sum += atoi(&c);
  }

  printf("%d\n", sum);
  return 0;
}

