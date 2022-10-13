#include <cstdlib>

int main() {
  char *x = (char *)calloc(10, sizeof(char));
  int res = x[1];
  free(x);
  free(x);
  free(x + 1);

  return res;
}
