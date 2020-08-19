#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> data = {1, 2, 3};

const std::vector<int>& get_data(void) {
  std::cout << "Called get_data()" << '\n';
  return data;
}

int main(void) {
  std::vector<int> output(3);

  std::transform (data.begin(), data.end(), output.begin(), [](int elem) -> int { return (elem+1); });

  std::for_each (output.begin(), output.end(), [](int n) -> void { std::cout << n << '\n'; });


  for (const auto& e : get_data()) {
    std::cout << e << '\n';
  }

  return 0;
}
