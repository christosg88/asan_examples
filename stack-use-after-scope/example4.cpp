#include <iostream>

struct A {
  A(const int &v) {
    p = &v;
  }
  void print() {
    std::cout << *p;
  }
  const int *p;
};

void explicit_temp() {
  A a(5); // the temporary for 5 is not alive after the call to the constructor
  a.print();
}

void temp_from_conversion() {
  double v = 5;
  A a(v); // the temporary int v, that was implicitly created to call the constructor, is not alive after the call to
          // the constructor
  a.print();
}

int main() {
  explicit_temp();
  temp_from_conversion();

  return 0;
}
