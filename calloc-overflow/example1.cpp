#include <cstdlib>
#include <iostream>

int main() {
  static constexpr int element_count = -1;
  static constexpr int element_size = 1000;

  void *p = std::calloc(element_count, element_size);
  std::cout << "calloc returned: " << p << std::endl;

  return 0;
}
