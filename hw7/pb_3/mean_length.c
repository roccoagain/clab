#include <stdio.h>
#include <string.h>

int main() {
  char str[50];
  int words = 0;
  int characters = 0;

  while (scanf("%49s", str) == 1) {
    // Count words and characters
    words++;
    characters += strlen(str);
  }

  // Calculate mean length
  if (words > 0) {
    int mean = characters / words;
    printf("Mean length: %d\n", mean);
  } else {
    printf("error\n");
  }

  return 0;
}
