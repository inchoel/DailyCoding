#include <cstdio>
#include <bitset>
using namespace std;

#define SIZE (100000)
int main()
{
  char a[SIZE+1];
  char b[SIZE+1];
  scanf (" %s", a);
  scanf (" %s", b);

  bitset<SIZE> A(a);
  bitset<SIZE> B(b);

  printf("%s\n", (A & B).to_string().c_str());
  printf("%s\n", (A | B).to_string().c_str());
  printf("%s\n", (A ^ B).to_string().c_str());
  printf("%s\n", (~A).to_string().c_str());
  printf("%s\n", (~B).to_string().c_str());
  return 0;
}
