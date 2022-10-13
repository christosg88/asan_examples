int main() {
  int *x = new int[42];
  delete[] x;
  delete[] x;

  return 0;
}
