#include <cstdio>
#include <string>
using namespace std;

const char* foo() {
  // return NULL;
  return 0;
}

int main() {
  string str = "xxx";
  printf("%s\n", str.c_str());
  // str = 0; // compile error
  // str = nullptr; // runtime error
  //
  str = foo();
  return 0;
}
