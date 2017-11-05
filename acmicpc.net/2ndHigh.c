#include <stdio.h>

int main(void)
{
  int i, j;
  int temp;
  int input[3];
  scanf("%d %d %d", input, input+1, input+2);

  for(i=0; i<2; i++) {
    for(j=0; j<(2-i); j++) {
      temp = input[j];
      if (temp > input[j+1]) {
        // swap
        input[j] = input[j+1];
        input[j+1] = temp;
      }
    }
  }

  printf("%d\n", input[1]);
  return 0;
}
