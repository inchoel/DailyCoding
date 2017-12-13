#include <cstdio>
#include <string>
using namespace std;

#if 0
void foo(string* sp) {
  if (sp)
    printf("O.O - string pointer always have a value\n");
}

int main() {
  string str;

  foo(&str);
  return 0;
}
#else
void foo(string& sp) {
  if (sp.empty())
    printf("O.O - empty\n");

  sp = "foo";
}

int main() {
  string str;

  foo(str);

  printf("%s\n", str.c_str());
  return 0;
}
#endif
