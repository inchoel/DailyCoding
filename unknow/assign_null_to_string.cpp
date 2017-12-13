#include <cstdio>
#include <string>
using namespace std;

int main() {
  string str = "xxx";
  printf("%s\n", str.c_str());
  str = nullptr;
  // printf("%d\n", str.empty());
  return 0;
}
