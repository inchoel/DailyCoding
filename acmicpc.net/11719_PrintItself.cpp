#if 0
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define MAX_SIZE (101)
int main()
{
  char a[MAX_SIZE];
  vector<string> v;
  memset(a, 0, MAX_SIZE);
  while (fgets(a, MAX_SIZE, stdin)) {
    a[strlen(a)-1] = '\0';
    // string str = a;
    // v.push_back(str);
    printf("%s\n", a);
  }

  // for (auto s : v)
  //   printf("%s\n", s.c_str());

  return 0;
}
#else
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
  char buffer[10000];
  vector<string> v;

  while (fgets(buffer, 10000, stdin) != NULL) {
    string s = buffer;
    v.push_back(s);
    printf("%s", s.c_str());
  }

  // for (auto s : v)
 //    printf("%s", s.c_str());


  return 0;
}

#endif
