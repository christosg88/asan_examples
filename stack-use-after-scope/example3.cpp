#include <iostream>

struct IntHolder {
  IntHolder() = default;
  explicit IntHolder(int *val) : m_val(val) {}

  ~IntHolder() {
    std::cout << *m_val << "\n";
  }

  void set(int *val) {
    m_val = val;
  }

  int *m_val{nullptr};
};

int main() {
  // It's incorrect to use "x" inside the IntHolder destructor,
  // because the lifetime of "x" ends earlier. Per the C++ standard,
  // local lifetimes end in reverse order of declaration.
  IntHolder holder;
  int x = 10;
  holder.set(&x);
  return 0;
}
