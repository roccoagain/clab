#include <assert.h>

int isPrime(int num) {
  if (num <= 1) return 0;

  for (int j = 2; j * j <= num; j++) {
    if (num % j == 0) return 0;
  }

  return 1;
}

int primesum(int n, int *sum) {
  if (!(n >= 1)) {
    return -1;
  }

  *sum = 0;

  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      *sum += i;
    }
  }

  return 0;
}

int main() {
  int sum;

  assert(primesum(11, &sum) == 0 && sum == 28);
  assert(primesum(30, &sum) == 0 && sum == 129);
  assert(primesum(-10, &sum) == -1);
  assert(primesum(2, &sum) == 0 && sum == 2);
}