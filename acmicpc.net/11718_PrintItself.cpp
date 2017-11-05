#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define MAX_SIZE (101)

int main()
{
  char input[MAX_SIZE];
  vector<string> in;

  memset(input, 0, MAX_SIZE);
  while (fgets(input, MAX_SIZE, stdin))
  {
    input[strlen(input)-1] = '\0';
    string strinput(input);
    in.push_back(strinput);
    memset(input, 0, MAX_SIZE);
  }

  for (auto s : in)
    printf("%s\n", s.c_str());
  return 0;
}
