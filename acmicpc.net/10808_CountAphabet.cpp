#include <cstdio>
#include <cstring>
#include <array>
using namespace std;

int main()
{
  char word[101];
  array<int, 100> arr;
  arr.fill(0);

  scanf (" %s", word);

  size_t len = strlen(word);
  for (size_t i=0; i<len; i++) {
    arr[(int)(word[i]-'a')] = arr[(int)(word[i]-'a')] + 1;
  }

  for (int j=0; j<26; j++)
    printf("%d ", arr[j]);
  printf("\n");

  return 0;
}
