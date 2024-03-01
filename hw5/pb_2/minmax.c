#include <assert.h>
#include <stdio.h>

int minmax(int x[], int len, int *min, int *max) {
  if (x == NULL || min == NULL || max == NULL) return -1;

  *min = 0;
  *max = 0;

  for (int i = 0; i < len; i++) {
    if (x[i] < *min) {
      *min = x[i];
    }

    if (x[i] > *max) {
      *max = x[i];
    }
  }
  return 0;
}

int main() {
  int min, max;

  int x[5] = {1, 100, -1, 0};
  int length = sizeof(x) / sizeof(x[0]);

  assert(minmax(x, length, &min, &max) == 0);
  assert(min == -1);
  assert(max == 100);

  assert(minmax(NULL, 0, &min, &max) == -1);
  assert(minmax(x, length, NULL, &max) == -1);
  assert(minmax(x, length, &min, NULL) == -1);

  minmax(x, length, &min, &max);
  printf("Min: %d\nMax: %d\n", min, max);
}