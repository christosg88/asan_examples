#include <cstdlib>

int main() {
  int *buffer = (int*)realloc(nullptr, 10);
  free(buffer);

  buffer[0] = 42;

  return 0;
}
