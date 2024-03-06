#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int unzip(int *a, int *b, int *c, int n) {
  if (a == NULL || b == NULL || c == NULL || n < 2) return -1;

  // Unzip c into a and b
  for (int i = 0; i < n; i++) {
    a[i] = c[i];
    b[i] = c[n + i];
  }

  return 0;
}

int main() {
  // Test cases
  int n = 3;
  int c[6] = {1, 2, 3, 4, 5, 6};
  int a[3];
  int b[3];

  assert(unzip(a, b, c, n) == 0);

  assert(a[0] == 1);
  assert(b[0] == 4);
  assert(b[2] == 6);

  assert(unzip(NULL, NULL, NULL, 6) == -1);
  assert(unzip(a, b, c, 1) == -1);
}