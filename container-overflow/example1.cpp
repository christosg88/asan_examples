#include <vector>

int main() {
  std::vector<int> v(10);  // construct a vector of size 10 and capacity 10
  v.reserve(20);  // increase capacity from 10 to 20

  v[10] = 1;  // write within allocated capacity, but outside size, not yet detected by compilers other than MSVC

  v[20] = 1;  // write outside allocated capacity
}
