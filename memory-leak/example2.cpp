#include <cstdlib>

struct S {
  S() : m_nums(new int[100]) {
    m_nums[1] = 0;
  }

  int *m_nums;
};

int main() {
  S *s = new S();

  void *x = std::malloc(50 * sizeof(int));

  int *ret = new int(0);

  return *ret + *(int *)x + s->m_nums[1];
}
