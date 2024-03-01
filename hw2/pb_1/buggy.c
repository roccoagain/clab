#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
  assert(!(x == NULL));
  assert(!(y == NULL));
  int t = *x;
  int s = *y;
  *x = s;
  *y = t;
}

int main() {
  int a = 0;
  int b = 1;
  printf("Before: a = %d, b = %d\n", a, b);
  swap(&a, &b);
  assert(a == 1);
  assert(b == 0);
  printf("After: a = %d, b = %d\n", a, b);
}
