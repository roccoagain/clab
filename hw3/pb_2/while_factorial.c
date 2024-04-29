#include <assert.h>
#include <stddef.h>

int while_factorial(int n, int *factorial) {
  if (n < 0 || !factorial) {
    return -1;
  }

  *factorial = 1;

  while (n > 1) {
    *factorial *= n;
    n--;
  }

  return 0;
}

int main() {
  int factorial;

  while_factorial(1, &factorial);
  assert(factorial == 1);

  while_factorial(5, &factorial);
  assert(factorial == 120);

  while_factorial(7, &factorial);
  assert(factorial == 5040);

  while_factorial(0, &factorial);
  assert(factorial == 1);

  assert(while_factorial(-1, &factorial) == -1);
  assert(while_factorial(7, NULL) == -1);
}
