int main() {
  int *buffer = new int[10];
  delete[] buffer;

  buffer[0] = 0;
  return 0;
}
