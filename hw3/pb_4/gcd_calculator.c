#include <assert.h>
#include <stddef.h>

int gcd_calculator(int a, int b, int *gcd) {
  if (a <= 0 || b <= 0 || gcd == NULL) return -1;

  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }

  *gcd = a;
  return 0;
}

int main() {
  int gcd;

  assert(gcd_calculator(48, 18, &gcd) == 0);
  assert(gcd == 6);

  assert(gcd_calculator(18, 48, &gcd) == 0);
  assert(gcd == 6);

  assert(gcd_calculator(17, 13, &gcd) == 0);
  assert(gcd == 1);

  assert(gcd_calculator(0, 18, &gcd) == -1);
  assert(gcd_calculator(18, 0, &gcd) == -1);
  assert(gcd_calculator(18, 18, NULL) == -1);

  return 0;
}
