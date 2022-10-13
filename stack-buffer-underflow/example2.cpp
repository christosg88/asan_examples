#include <thread>
#include <future>

int worker(int idx) {
  int nums[10] = {0};
  return nums[idx];
}

int main() {
  std::future<int> ret = std::async(worker, -1);
  return ret.get();
}
