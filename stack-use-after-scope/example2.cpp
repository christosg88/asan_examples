#include <functional>

int main() {
  std::function<int()> f;

  {
    int x = 0;
    f = [&x]() {
      return x;
    };
  }

  return f();
}
