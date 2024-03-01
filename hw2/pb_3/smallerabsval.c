#include <assert.h>
#include <stdio.h>

int smallerabsval(int x, int y) {
  if (x < 0) {
    x *= -1;
  }
  if (y < 0) {
    y *= -1;
  }

  if (x <= y) {
    return x;
  } else {
    return y;
  }
}

int main() {
  assert(smallerabsval(3, 5) == 3);
  printf("smallerabsval(3,5) = %d\n", smallerabsval(3, 5));

  assert(smallerabsval(-2, 5) == 2);
  printf("smallerabsval(-2,5) = %d\n", smallerabsval(-2, 5));

  assert(smallerabsval(5, 5) == 5);
  printf("smallerabsval(5,5) = %d\n", smallerabsval(5, 5));

  assert(smallerabsval(-7, -5) == 5);
  printf("smallerabsval(-7,-5) = %d\n", smallerabsval(-7, -5));

  assert(smallerabsval(-5, -5) == 5);
  printf("smallerabsval(-5,-5) = %d\n", smallerabsval(-5, -5));
}
