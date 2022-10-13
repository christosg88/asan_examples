#include <cstdlib>
#include <cstring>

int main() {
  static constexpr int size = 1000;
  char *buffer = (char *)std::malloc(size * size * size * size);
  std::memcpy(buffer, buffer + 1, (size - 1) * sizeof(char));

  return 0;
}
