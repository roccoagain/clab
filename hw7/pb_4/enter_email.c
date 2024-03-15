#include <regex.h>
#include <stdio.h>

int main() {
  char email[254];

  regex_t regex;  // RegEx Object

  // Get email with scanf
  scanf("%253s", email);

  // Compile the regex
  regcomp(&regex, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}$",
          REG_EXTENDED);

  // Return 0 if email is valid, 1 if invalid
  if (regexec(&regex, email, 0, NULL, 0)) {
    printf("Invalid Email\n");
    printf("Correct format: user@example.com\n");
    return 1;
  } else {
    printf("Valid Email\n");
    printf("%s\n", email);
    return 0;
  }
}
