#include <alloca.h>

int main() {
  char *a = (char *)alloca(10);
  char *b = (char *)alloca(10);
  a[10] = '1';
  b[0] = '2';

  return 0;
}
