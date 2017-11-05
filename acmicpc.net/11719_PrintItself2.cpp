#include <cstdio>
#include <cstring>
// #include <vector>
// #include <string>
using namespace std;

int main()
{
  // vector<string> v;
  char s[101];

  while (scanf("%[^\n]\n", s) == 1 ) {
    // v.push_back(s);
    printf("%s, %d\n", s, strlen(s));
  }

  // for (auto& s : v)
  //  printf("%s\n", s.c_str());

  return 0;
}
