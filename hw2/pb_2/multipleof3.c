#include <assert.h>
#include <stdio.h>

int multipleof3(int n) {
  return (n % 3 == 0);
}

int main() {
  assert(multipleof3(9));
  assert(!(multipleof3(7)));
  assert(!(multipleof3(14)));
  assert((multipleof3(27)));

  if (multipleof3(9)) {
    printf("9 is a multiple of 3!\n");
  } else {
    printf("9 is not a multiple of 3!\n");
  }

  if (!multipleof3(7)) {
    printf("7 is not a multiple of 3!\n");
  } else {
    printf("7 is a multiple of 3!\n");
  }

  if (!multipleof3(14)) {
    printf("14 is not a multiple of 3!\n");
  } else {
    printf("14 is a multiple of 3!\n");
  }

  if (multipleof3(27)) {
    printf("27 is a multiple of 3!\n");
  } else {
    printf("27 is not a multiple of 3!\n");
  }
}
