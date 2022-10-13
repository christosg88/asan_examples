#include <cstdlib>

int main() {
  int *x = (int *)calloc(10, sizeof(int));
  free(x);

  return x[0];
}
