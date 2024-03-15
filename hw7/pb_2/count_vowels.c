#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Returns 0 for 'a', 1 for 'e', 2 for 'i', 3 for 'o', 4 for 'u', -1 for
// non-vowel
int return_vowel(char ch) {
  ch = tolower(ch);

  switch (ch) {
    case 'a':
      return 0;
    case 'e':
      return 1;
    case 'i':
      return 2;
    case 'o':
      return 3;
    case 'u':
      return 4;
    default: {
      return -1;
    }
  }
}

int main() {
  char line[1024];
  char c;
  int vowels[5] = {0, 0, 0, 0, 0};

  while (scanf("%c", &c) == 1) {
    // Identify the vowel
    int index = return_vowel(c);

    // If it is a vowel, increment its bin
    if (index != -1) {
      vowels[index]++;
    }
  }

  // Print count of each vowel bin
  printf("a: %d\n", vowels[0]);
  printf("e: %d\n", vowels[1]);
  printf("i: %d\n", vowels[2]);
  printf("o: %d\n", vowels[3]);
  printf("u: %d\n", vowels[4]);

  return 0;
}
