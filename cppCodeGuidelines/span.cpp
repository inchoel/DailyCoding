#include <gsl/span>
#include <gsl/gsl_narrow>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>

void array_print (gsl::span<int> d) {
    std::cout << "size = " << d.size() << '\n';
    std::for_each (d.begin(), d.end(), [] (const int& n) { std::cout << n << '\n'; });
}

int main (void) {
  int data[3] = {1, 2, 3};
  gsl::span<int> s = {&data[0], gsl::narrow_cast<std::size_t>(3)};
  array_print(s);

  std::array<int, 3> data2 = {4, 5, 6};
  gsl::span<int> s2 = {data2.begin(), gsl::narrow_cast<std::size_t>(data2.size())};
  array_print(s2);

  return 0;
}
