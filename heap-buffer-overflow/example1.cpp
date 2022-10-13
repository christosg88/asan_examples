#include <cstdlib>

int main() {
  int *x = (int *)calloc(10, sizeof(int));
  int res = x[10];
  free(x);

  return res;
}
