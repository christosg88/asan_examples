#include <cstdlib>

int main() {
  int *x = (int *)std::aligned_alloc(15, 10 * sizeof(int));
  return x[0];
}
