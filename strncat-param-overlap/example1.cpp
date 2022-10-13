#include <cstring>

int main() {
  char buffer[] = "hello";
  strncat(buffer, buffer + 1, 3);

  return 0;
}
