#include <iostream>

int add (int x, int y) {
  return x + y;
}

int main(void) {

  int (*fp) (int, int) = add;

  std::cout << add << '\n';
  std::cout << fp(1, 1) << ": " << (fp) << '\n';
  std::cout << (*fp)(1, 1) << ": " << (*fp) << '\n';

  return 0;
}
