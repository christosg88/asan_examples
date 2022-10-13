int main() {
  int *gp = nullptr;
  {
    int x[5];
    gp = x + 1;
  }

  return *gp;
}
