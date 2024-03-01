#include <assert.h>
#include <stdio.h>

int flip(int x[], int y[], int len) {
  if (x == NULL || y == NULL || len <= 0) return -1;

  for (int i = 0; i < len; i++) {
    y[i] = x[len - 1 - i];
  }

  return 0;
}

int main() {
  int x[5] = {1, 2, 3, 4, 5};
  int y[5];

  int length = sizeof(x) / sizeof(x[0]);

  flip(x, y, length);

  assert(x[0] == y[length - 1]);

  // print x
  printf("x: [");
  for (int i = 0; i < length; i++) {
    printf("%d", x[i]);

    if (i != length - 1) {
      printf(", ");
    }
  }
  printf("]\n");

  // print y
  printf("y: [");
  for (int i = 0; i < length; i++) {
    printf("%d", y[i]);

    if (i != length - 1) {
      printf(", ");
    }
  }
  printf("]\n");

  assert(flip(NULL, y, length) == -1);
  assert(flip(x, NULL, length) == -1);
  assert(flip(x, y, 0) == -1);
}