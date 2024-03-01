#include <assert.h>
#include <stdio.h>

void swap3(int* a, int* b, int* c) {
  assert(a != NULL && b != NULL && c != NULL);

  int temp = *c;
  *c = *b;
  *b = *a;
  *a = temp;
}

int main() {
  int x, y, z;
  x = 1;
  y = 4;
  z = 9;

  printf("Before: x = %d, y = %d, z = %d\n", x, y, z);
  swap3(&x, &y, &z);
  printf("After: x = %d, y = %d, z = %d\n", x, y, z);

  // Example of swapping 2 variables when 3 arguments are required
  swap3(&x, &y, &y);
  printf("Swapping 2 variables: x = %d, y = %d, z = %d\n", x, y, z);
  return 0;
}
