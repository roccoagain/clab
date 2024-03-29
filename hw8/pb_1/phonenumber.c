#include <regex.h>
#include <stdio.h>
#include <string.h>

int main() {
  char phone[15];
  regex_t regex;

  fgets(phone, 15, stdin);

  // Remove newline if present
  if (phone[strlen(phone) - 1] == '\n') {
    phone[strlen(phone) - 1] = '\0';
  }

  // Compile regex for (XXX) XXX-XXXX or XXX-XXX-XXXX
  regcomp(&regex, "^(\\([0-9]{3}\\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$",
          REG_EXTENDED);

  // Return 1 for invalid phone number
  if (regexec(&regex, phone, 0, NULL, 0) != 0) {
    printf("Invalid phone number\n");
    return 1;
  }

  printf("Valid phone number\n");
  return 0;
}