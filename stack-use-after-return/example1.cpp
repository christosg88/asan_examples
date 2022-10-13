// must be compiled with -fsanitize-address-use-after-return=runtime
// and enabled at runtime with ASAN_OPTIONS=detect_stack_use_after_return=1

char *foo() {
  char stack_buffer[5];
  return &stack_buffer[0];
}

int main() {
  char *x = foo();
  *x = 42;

  return 0;
}
