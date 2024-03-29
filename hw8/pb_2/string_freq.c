#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_THRESHOLD 32

// Threshold for large strings
int threshold = MAX_THRESHOLD;
// Array to store the counts of words of each length
int lengthCounts[MAX_THRESHOLD] = {0};
// Buffer to store the current word
char word[MAX_WORD_LENGTH];
int trials = 0;

// Print the distribution of the lengths of the words with percent bars
void print_distribution(int *lengthCounts, int threshold, int trials) {
  for (int i = 0; i < threshold; i++) {
    int percent = (lengthCounts[i] * 100) / trials;
    printf("%2d %2d ", i, percent);
    for (int j = 0; j < percent; ++j) {
      printf("*");
    }
    printf("\n");
  }
}

void print_usage() {
  printf("Usage: string_freq [-h] [-s n]\n");
  printf("Options:\n");
  printf("  -h     Display this help message and exit.\n");
  printf(
      "  -s n   Set the threshold for large strings to n (1 <= n <= "
      "32).\n");
}

int main(int argc, char *argv[]) {
  // Command-line options
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      // Arg -h, Print Help
      print_usage();
      return 0;
    } else if (strcmp(argv[i], "-s") == 0) {
      // Arg -s, Set the threshold passed as an argument
      if (i + 1 < argc) {  // Ensure '-s' has an argument
        threshold = atoi(argv[++i]);
        if (threshold < 1 || threshold > MAX_THRESHOLD) {
          fprintf(stderr, "Threshold must be between 1 and 32.\n");
          return 1;
        }
      } else {
        fprintf(stderr, "Missing argument.\n");
        return 1;
      }
    } else {
      fprintf(stderr, "Unknown option: %s\n", argv[i]);
      return 1;
    }
  }

  // Get input and count the lengths of the words
  while (scanf("%s", word) != EOF) {
    int length = strlen(word);
    if (length >= threshold) {
      lengthCounts[threshold - 1]++;
    } else {
      lengthCounts[length - 1]++;
    }
    trials++;
  }

  // Print the distribution
  print_distribution(lengthCounts, threshold, trials);

  return 0;
}
