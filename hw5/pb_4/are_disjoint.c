#include <assert.h>
#include <stdio.h>

int are_disjoint(int x[], int y[], int lx, int ly) {
  if (x == NULL || y == NULL || lx <= 0 || ly <= 0) return -1;

  // Check if there are any common elements
  for (int i = 0; i < lx; i++) {
    for (int j = 0; j < ly; j++) {
      if (x[i] == y[j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  // Test cases
  int x[] = {0, 1, 2, 3};
  int y[] = {4, 5, 6};
  int lx = sizeof(x) / sizeof(x[0]);
  int ly = sizeof(y) / sizeof(y[0]);
  assert(are_disjoint(x, y, lx, ly) == 1);

  if (are_disjoint(x, y, lx, ly)) {
    printf("The arrays are disjoint.\n");
  } else {
    printf("The arrays are not disjoint.\n");
  }

  int x2[] = {0, 1, 5, 3};
  int y2[] = {4, 5, 6, 0, 6, 7, 8};
  int lx2 = sizeof(x2) / sizeof(x2[0]);
  int ly2 = sizeof(y2) / sizeof(y2[0]);
  assert(are_disjoint(x2, y2, lx2, ly2) == 0);

  if (are_disjoint(x2, y2, lx2, ly2)) {
    printf("The arrays are disjoint.\n");
  } else {
    printf("The arrays are not disjoint.\n");
  }

  assert(are_disjoint(NULL, NULL, 5, 5) == -1);
  assert(are_disjoint(x2, y2, 0, -1) == -1);

  return 0;
}