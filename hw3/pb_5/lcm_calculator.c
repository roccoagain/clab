#include <assert.h>
#include <stddef.h>

int lcm_calculator(int a, int b, int *lcm) {
  if (a <= 0 || b <= 0 || lcm == NULL) return -1;

  int max = (a > b) ? a : b;

  for (*lcm = max;; *lcm += max) {
    if (*lcm % a == 0 && *lcm % b == 0) {
      break;
    }
  }

  return 0;
}

int main() {
  int lcm;

  assert(lcm_calculator(4, 6, &lcm) == 0);
  assert(lcm == 12);

  assert(lcm_calculator(21, 6, &lcm) == 0);
  assert(lcm == 42);

  assert(lcm_calculator(0, 6, &lcm) == -1);
  assert(lcm_calculator(6, 0, &lcm) == -1);
  assert(lcm_calculator(6, 6, NULL) == -1);

  return 0;
}
