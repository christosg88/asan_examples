#include <alloca.h>

int main() {
  char *str = (char *)alloca(10);
  str[10] = '1';

  return 0;
}
