#include <assert.h>
#include <stdio.h>

int smallerabsval(int x, int y) {
  int absX = (x < 0) ? -x : x;
  int absY = (y < 0) ? -y : y;

  if (absX < absY) {
    return x;
  } else if (absY < absX) {
    return y;
  } else {
    return (x > 0) ? x : y;
  }
}

int main() {
  assert(smallerabsval(-8, -5) == -5);
  printf("smallerabsval(-8,-5) = %d\n", smallerabsval(-8, -5));
  assert(smallerabsval(-5, -8) == -5);
  printf("smallerabsval(-5,-8) = %d\n", smallerabsval(-5, -8));
  assert(smallerabsval(5, 8) == 5);
  printf("smallerabsval(5,8) = %d\n", smallerabsval(5, 8));
  assert(smallerabsval(8, 5) == 5);
  printf("smallerabsval(8,5) = %d\n", smallerabsval(8, 5));
  assert(smallerabsval(-5, 5) == 5);
  printf("smallerabsval(-5,5) = %d\n", smallerabsval(-5, 5));
}
