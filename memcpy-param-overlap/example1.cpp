#include <cstring>

int main() {
  char buffer[] = "hello";
  std::memcpy(buffer, buffer + 1, 5);

  return 0;
}
