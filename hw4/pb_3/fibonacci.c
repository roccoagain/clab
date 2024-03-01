#include <assert.h>
#include <stddef.h>

// internal
int fibonacci_internal(int n) {
  if (n <= 0) return 0;
  if (n == 1) return 1;

  return fibonacci_internal(n - 1) + fibonacci_internal(n - 2);
}

// external
int fibonacci(int n, int *fibo_n) {
  if (n < 0 || fibo_n == NULL) return -1;

  *fibo_n = fibonacci_internal(n);
  return 0;
}

int main() {
  int fibo_value;

  assert(fibonacci(0, &fibo_value) == 0);
  assert(fibo_value == 0);

  assert(fibonacci(1, &fibo_value) == 0);
  assert(fibo_value == 1);

  assert(fibonacci(10, &fibo_value) == 0);
  assert(fibo_value == 55);

  assert(fibonacci(-1, &fibo_value) == -1);
  assert(fibonacci(5, NULL) == -1);

  return 0;
}
