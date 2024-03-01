#include <assert.h>
#include <stdio.h>

int minmax(int a, int b, int c, int *min, int *max) {
  if (min == NULL || max == NULL) {
    return -1;
  }

  if (a > b) {
    if (a > c) {
      *max = a;
    } else
      *max = c;
  } else {
    if (b > c) {
      *max = b;
    } else {
      *max = c;
    }
  }

  if (a < b) {
    if (a < c) {
      *min = a;
    } else
      *min = c;
  } else {
    if (b < c) {
      *min = b;
    } else {
      *min = c;
    }
  }
  return 0;
}

int main() {
  int min, max = 0;

  minmax(1, 5, 6, &min, &max);
  assert(min == 1 && max == 6);
  printf("min: %d, max %d\n", min, max);

  minmax(10, 15, 16, &min, &max);
  assert(min == 10 && max == 16);
  printf("min: %d, max %d\n", min, max);

  minmax(5, 5, 5, &min, &max);
  assert(min == 5 && max == 5);
  printf("min: %d, max %d\n", min, max);

  minmax(5, 6, 5, &min, &max);
  assert(min == 5 && max == 6);
  printf("min: %d, max %d\n", min, max);
}
