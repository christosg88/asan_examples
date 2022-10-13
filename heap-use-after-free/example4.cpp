#include <cstdlib>

int main() {
  volatile int *x = (int *)malloc(sizeof(int));
  free((void *)x);
  *x = 42;

  return 0;
}
