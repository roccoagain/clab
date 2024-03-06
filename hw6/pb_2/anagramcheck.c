#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void clean(char *string) {
  // Remove spaces and convert to lowercase
  int len = strlen(string);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (string[i] != ' ') {
      string[j] = tolower(string[i]);
      j++;
    }
  }
  string[j] = '\0';
}

int anagramcheck(char *string1, char *string2) {
  if (string1 == NULL || string2 == NULL) return -1;

  // Remove spaces and convert to lowercase
  clean(string1);
  clean(string2);

  // Get length of strings
  int len1 = strlen(string1);
  int len2 = strlen(string2);

  // Create an array to store the count of each character, 1 bin for each letter
  // of the alphabet
  int counts[26] = {0};

  // Increment counts for each character in string1
  for (int i = 0; i < len1; i++) {
    counts[string1[i] - 'a']++;
  }

  // Decrement counts for each character in string2
  for (int i = 0; i < len2; i++) {
    counts[string2[i] - 'a']--;
  }

  // If any counts are not 0, the strings are not anagrams
  for (int i = 0; i < 26; i++) {
    if (counts[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  // Test cases
  char string1[] = "listen";
  char string2[] = "silent";
  assert(anagramcheck(string1, string2) == 1);

  char string3[] = "abcdefg";
  char string4[] = "gfedcBa";
  assert(anagramcheck(string3, string4) == 1);

  char string5[] = "Yas";
  char string6[] = "SAY";
  assert(anagramcheck(string5, string6) == 1);

  char string7[] = "Tom Marvolo Riddle";
  char string8[] = "I am Lord Voldemort";
  assert(anagramcheck(string7, string8) == 1);

  char string9[] = "ASDF";
  char string10[] = "QWER";
  assert(anagramcheck(string9, string10) == 0);

  char string11[] = "Helloooooo";
  char string12[] = "Helloo";
  assert(anagramcheck(string11, string12) == 0);

  return 0;
}