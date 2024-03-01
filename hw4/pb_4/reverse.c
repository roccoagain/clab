#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

void reverse_internal(int n, int* n_reversed) {
  if (n == 0) {
    return;
  }
  *n_reversed = (*n_reversed * 10) + (n % 10);
  reverse_internal(n / 10, n_reversed);
}

int reverse(int n, int* n_reversed) {
  if (n < 0 || n_reversed == NULL) {
    return -1;
  }

  *n_reversed = 0;
  reverse_internal(n, n_reversed);

  return 0;
}

int main() {
  int reversed;

  assert(reverse(12345, &reversed) == 0);
  assert(reversed == 54321);
  printf("reverse of %d -> %d\n", 12345, reversed);

  assert(reverse(47291, &reversed) == 0);
  assert(reversed == 19274);
  printf("reverse of %d -> %d\n", 47291, reversed);

  assert(reverse(123123123, &reversed) == 0);
  assert(reversed == 321321321);

  assert(reverse(302, &reversed) == 0);
  assert(reversed == 203);
  printf("reverse of %d -> %d\n", 302, reversed);

  assert(reverse(42, &reversed) == 0);
  assert(reversed == 24);
  printf("reverse of %d -> %d\n", 42, reversed);

  assert(reverse(1, &reversed) == 0);
  assert(reversed == 1);

  assert(reverse(0, &reversed) == 0);
  assert(reversed == 0);

  assert(reverse(-1, &reversed) == -1);
  assert(reverse(12345, NULL) == -1);

  return 0;
}
