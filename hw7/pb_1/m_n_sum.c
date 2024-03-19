#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int m_n_sum(int m, int n) {
  // Sum all integers from m to n
  int sum = 0;
  for (int i = m; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main(int argc, char *argv[]) {
  // Check for malformed input
  if (argc != 3) {
    printf("Usage: %s m n\n", argv[0]);
    return 1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  // Error if m is not less than n
  if (m >= n) {
    printf("m must be less than n\n");
    return 1;
  }

  printf("%d\n", m_n_sum(m, n));
  return 0;
}