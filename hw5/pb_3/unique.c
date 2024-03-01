#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int unique(int x[], int len, int *p) {
  if (x == NULL || p == NULL || len <= 0) return -1;

  int n = 0;

  for (int i = 0; i < len; i++) {
    int j;
    for (j = 0; j < i; j++) {
      if (x[i] == x[j]) {
        break;
      }
    }

    if (i == j) {
      n++;
    }
  }

  *p = n;

  return 0;
}

int main() {
  int unique_counter;

  int x[] = {1, 1, 1, 2, 3, 5};
  int len_x = sizeof(x) / sizeof(x[0]);

  unique(x, len_x, &unique_counter);
  printf("%d unique numbers in x\n", unique_counter);

  int x2[] = {2, 5, 2, 5, 2, 5};
  int len_x2 = sizeof(x2) / sizeof(x2[0]);
  assert(unique(x2, len_x2, &unique_counter) == 0);
  assert(unique_counter == 2);

  int x3[] = {2, 5, 7, 5, 2, 5};
  int len_x3 = sizeof(x3) / sizeof(x3[0]);
  assert(unique(x3, len_x3, &unique_counter) == 0);
  assert(unique_counter == 3);
}