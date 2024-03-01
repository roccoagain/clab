#include <assert.h>
#include <stddef.h>

// internal
int factorial_internal(int n) {
  if (n == 0) return 1;

  return n * factorial_internal(n - 1);
}

// external
int factorial(int n, int *fact) {
  if (n < 0 || fact == NULL) return -1;

  *fact = factorial_internal(n);
  return 0;
}

int main() {
  int result;
  assert(factorial(5, &result) == 0);
  assert(result == 120);

  assert(factorial(3, &result) == 0);
  assert(result == 6);

  assert(factorial(0, &result) == 0);
  assert(result == 1);

  assert(factorial(-5, &result) == -1);

  return 0;
}
