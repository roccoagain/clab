#include <assert.h>

int for_factorial(int n, int *factorial) {
  if (n < 0) {
    return -1;
  }

  *factorial = 1;
  for (int i = 1; i <= n; i++) {
    *factorial *= i;
  }

  return 0;
}

int main() {
  int factorial;

  for_factorial(1, &factorial);
  assert(factorial == 1);

  for_factorial(5, &factorial);
  assert(factorial == 120);

  for_factorial(7, &factorial);
  assert(factorial == 5040);

  for_factorial(0, &factorial);
  assert(factorial == 1);

  assert(for_factorial(-1, &factorial) == -1);
}
