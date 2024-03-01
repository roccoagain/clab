#include <assert.h>
#include <stddef.h>

int power(int a, int n, int *p) {
  if (n < 0 || p == NULL) {
    return -1;
  }

  *p = 1;

  for (int i = 0; i < n; i++) {
    *p *= a;
  }

  return 0;
}

int main() {
  int pow;

  power(3, 5, &pow);
  assert(pow = 243);

  power(2, 2, &pow);
  assert(pow = 4);

  power(255, 0, &pow);
  assert(pow = 1);

  assert(power(5, -1, &pow) == -1);
  assert(power(5, 5, NULL) == -1);
}
