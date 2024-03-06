#include <stdio.h>
#include <assert.h>

int is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
      c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return 1;
  }
  return 0;
}

int vowelfree(char *in, char *out) {
  if (in == NULL || out == NULL) {
    return -1;
  }

  // Copy all non-vowel characters from in to out
  int i, j;
  for (i = 0, j = 0; in[i] != '\0'; i++) {
    if (!is_vowel(in[i])) {
      out[j] = in[i];
      j++;
    }
  }
  out[j] = '\0';

  return 0;
}

int main() {
  // Test cases
  char in[] = "Hello, World!";
  char out[100];
  assert(vowelfree(in, out) == 0);
  printf("%s\n", out);

  char in2[] = "EASY!";
  char out2[100];
  assert(vowelfree(in2, out2) == 0);
  printf("%s\n", out2);

  char in3[] = "AEIOUaeiou";
  char out3[100];
  assert(vowelfree(in3, out3) == 0);
  printf("These paranthesis should be empty: (%s)\n", out3);

  return 0;
}