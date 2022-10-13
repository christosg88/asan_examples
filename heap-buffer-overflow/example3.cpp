#include <stdlib.h>
#include <string.h>

int main() {
  char *short_buffer = (char *)malloc(9);
  strncpy(short_buffer, "Hello, world!", 10);
  free(short_buffer);

  return 0;
}
