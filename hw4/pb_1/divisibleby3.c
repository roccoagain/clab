#include <assert.h>
#include <stdio.h>

// internal
void divisibleby3_internal(int lower, int current) {
  if (current < lower) {
    return;
  }  // base case

  printf("%d ", current);
  divisibleby3_internal(lower, current - 3);
}

// external
void divisibleby3(int lower, int upper) {
  if (lower > upper) {
    printf("Error, lower is greater than upper.\n");
    return;
  }

  if (upper % 3 != 0) {
    upper -= upper % 3;
  }

  divisibleby3_internal(lower, upper);
}

int main() {
  divisibleby3(-5, 18);
  printf("\n");

  return 0;
}
