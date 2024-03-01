#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int unzip(int *a, int *b, int *c, int n) {
  if (a == NULL || b == NULL || c == NULL || n < 2) return -1;
  for (int i = 0; i < n; i++) {
    a[i] = c[i];
    b[i] = c[n + i];
  }

  return 0;
}

int main() {
  int n = 3;
  int c[6] = {1, 2, 3, 4, 5, 6};
  int a[3];
  int b[3];

  assert(unzip(a, b, c, n) == 0);

  printf("c: [");
  for (int i = 0; i < 2 * n; i++) {
    printf("%d ", c[i]);
  }
  printf("]\n");

  printf("a: [");
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("]\n");

  printf("b: [");
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  }
  printf("]\n");

  assert(a[0] == 1);
  assert(b[0] == 4);
  assert(b[2] == 6);

  assert(unzip(NULL, NULL, NULL, 6) == -1);
  assert(unzip(a, b, c, 1) == -1);
}