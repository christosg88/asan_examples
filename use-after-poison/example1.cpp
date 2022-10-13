#include <sanitizer/asan_interface.h>

int main() {
  int *x = new int[16];
  x[15] = 0;

  // manually poison the 16 ints allocated memory
  ASAN_POISON_MEMORY_REGION(x, 16 * sizeof(int));

  int res = x[15];

  delete[] x;

  return res;
}
