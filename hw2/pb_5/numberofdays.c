#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int numberofdays(int year, int month, int *days) {
  if (year < 1582) {
    return -1;
  }
  if (month < 1 || month > 12) {
    return -1;
  }
  if (days == NULL) {
    return -1;
  }

  if (month == 4 || month == 6 || month == 9 || month == 11) {
    *days = 30;
  } else if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      *days = 29;
    } else {
      *days = 28;
    }
  } else {
    *days = 31;
  }

  return 0;
}

int main() {
  int days;

  assert(0 == numberofdays(1582, 2, &days));
  assert(days == 28);
  printf("The number of days in year 1582, month 2, is %d\n", days);

  assert(0 == numberofdays(2000, 2, &days));
  assert(days == 29);
  printf("The number of days in year 2000, month 2, is %d\n", days);

  assert(0 == numberofdays(2023, 2, &days));
  assert(days == 28);
  printf("The number of days in year 2023, month 2, is %d\n", days);

  assert(0 == numberofdays(2024, 2, &days));
  assert(days == 29);
  printf("The number of days in year 2024, month 2, is %d\n", days);

  assert(0 == numberofdays(2100, 2, &days));
  assert(days == 28);
  printf("The number of days in year 2100, month 2, is %d\n", days);

  assert(0 == numberofdays(3000, 2, &days));
  assert(days == 28);
  printf("The number of days in year 3000, month 2, is %d\n", days);

  assert(0 == numberofdays(10000, 2, &days));
  assert(days == 29);
  printf("The number of days in year 10000, month 2, is %d\n", days);

  assert(0 == numberofdays(2023, 1, &days));
  assert(days == 31);
  printf("The number of days in year 2023, month 1, is %d\n", days);

  assert(0 == numberofdays(2023, 4, &days));
  assert(days == 30);
  printf("The number of days in year 2023, month 4, is %d\n", days);

  assert(0 == numberofdays(2023, 8, &days));
  assert(days == 31);
  printf("The number of days in year 2023, month 8, is %d\n", days);

  assert(0 == numberofdays(2023, 9, &days));
  assert(days == 30);
  printf("The number of days in year 2023, month 9, is %d\n", days);

  assert(numberofdays(-1, 1, &days) == -1);
  assert(numberofdays(2023, 0, &days) == -1);
  assert(numberofdays(-2023, 12, &days) == -1);
  assert(numberofdays(2023, -12, &days) == -1);
  assert(numberofdays(2023, 13, &days) == -1);
}
