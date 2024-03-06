#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int encrypt(char *in, char key, char *enc) {
  if (in == NULL || enc == NULL) return -1;

  // Add the key to each character of the input string
  int len = strlen(in);
  for (int i = 0; i < len; i++) {
    enc[i] = in[i] + key;
  }

  return 0;
}

int decrypt(char *enc, char key, char *out) {
  if (enc == NULL || out == NULL) return -1;

  // Subtract the key from each character of the encrypted string
  int len = strlen(enc);
  for (int i = 0; i < len; i++) {
    out[i] = enc[i] - key;
  }

  return 0;
}

int main() {
  // Test cases
  char in[] = "i love elden ring";
  char enc[50];
  char out[50];
  char key = 'h';

  assert(encrypt(in, key, enc) == 0);
  assert(decrypt(enc, key, out) == 0);
  assert(strcmp(in, out) == 0);  // strcmp returns 0 if both strings are equal
}