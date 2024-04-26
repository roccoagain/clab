#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int encrypt(char *in, char key, char *enc) {
  if (in == NULL || enc == NULL) return -1;
  int len = strlen(in);
  for (int i = 0; i < len; i++) {
    if (in[i] >= 'a' && in[i] <= 'z') {
      enc[i] = (in[i] + key - 'a') % 26 + 'a';
    } else if (in[i] >= 'A' && in[i] <= 'Z') {
      enc[i] = (in[i] + key - 'A') % 26 + 'A';
    } else {
      enc[i] = in[i];
    }
  }
  enc[len] = '\0';
  return 0;
}

int decrypt(char *enc, char key, char *out) {
  if (enc == NULL || out == NULL) return -1;
  int len = strlen(enc);
  for (int i = 0; i < len; i++) {
    if (enc[i] >= 'a' && enc[i] <= 'z') {
      out[i] = (enc[i] - key - 'a' + 26) % 26 + 'a';
    } else if (enc[i] >= 'A' && enc[i] <= 'Z') {
      out[i] = (enc[i] - key - 'A' + 26) % 26 + 'A';
    } else {
      out[i] = enc[i];
    }
  }
  out[len] = '\0';
  return 0;
}

int main() {
  // Test cases
  char in[] = "i love elden ring, numbers! 12345";
  char enc[50];
  char out[50];
  char key = 'h' - 'a';  // Shift value

  assert(encrypt(in, key, enc) == 0);
  assert(decrypt(enc, key, out) == 0);
  assert(strcmp(in, out) == 0);  // strcmp returns 0 if both strings are equal

  printf("Original: %s\n", in);
  printf("Encrypted: %s\n", enc);
  printf("Decrypted: %s\n", out);
  return 0;
}