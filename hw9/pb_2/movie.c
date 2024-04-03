#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************
 * API
 *********************************************************************/

typedef struct _movie movie;

/* Creates a new Movie with the specified title, release_year (in the range
1900- 2030), lead actor and lead actress. The total number of ratings and the
average audience rating is initialized to zero. Function returns NULL if any of
the pointer parameters are NULL or if release_year is not in the correct
format/range. */
movie *newMovie(char *title, int release_year, char *lead_actor,
                char *lead_actress);

/* Update the total number of ratings and average audience rating based on the
parameter "rating" (which is an integer from 1 to 10) for the movie "mov".
Returns 0 if successful and -1 for malformed input */
int updateRating(
    movie *mov,
    int rating);  // user submits rating from 1-10, avg can still be float

/*Returns 1 if mov1 has higher audience rating, 2 is mov2 has higher
audience rating and 0 if both have same audience rating. Returns -1 for
malformed input.*/
int whichMovieShouldIWatch(movie *mov1, movie *mov2);

/*Prints out a one line summary of the movie (similar to the first line on the
wikipedia page for any movie) that includes all the info contained in the
structure. Returns 0 if successful or -1 if input is malformed. */
int printSummary(movie *mov);

/* Deletes the movie pointed to by mov. Returns 0 if successful or -1 if input
malformed */
int deleteMovie(movie *mov);

/**********************************************************************
 * Application
 *********************************************************************/

// Test creating and deleting a movie
void testBasic();

// Test updating a movie rating
void testUpdateRating();

// Test comparing the ratings of two movies
void testWhichMovieShouldIWatch();

// Test printing a movie's summary
void testPrintSummary();

int main() {
  testBasic();
  testUpdateRating();
  testWhichMovieShouldIWatch();
  testPrintSummary();
}

void testBasic() {
  movie *mov;
  // Test invalid date
  mov = newMovie("Dune: Part Two", 2031, "Timothée Chalomet", "Zendaya");
  assert(mov == NULL);

  // Test Missing Parameters
  mov = newMovie(NULL, 2024, "Timothée Chalomet", NULL);
  assert(mov == NULL);

  // Test valid movie and deleting it
  mov = newMovie("Dune: Part Two", 2024, "Timothée Chalomet", "Zendaya");
  assert(mov != NULL);
  assert(deleteMovie(mov) == 0);
}

void testUpdateRating() {
  movie *mov = newMovie("Dune: Part Two", 2024, "Timothée Chalomet", "Zendaya");

  assert(updateRating(mov, 10) == 0);
  assert(updateRating(mov, 1) == 0);

  // Returns -1 for invalid rating
  assert(updateRating(mov, 11) == -1);

  deleteMovie(mov);
}

void testWhichMovieShouldIWatch() {
  movie *mov1 =
      newMovie("Dune: Part Two", 2024, "Timothée Chalomet", "Zendaya");
  movie *mov2 = newMovie("Romeo and Juliet", 2022, "Romeo", "Juliet");

  // Test equal ratings
  assert(whichMovieShouldIWatch(mov1, mov2) == 0);

  // Test mov1 has higher rating
  updateRating(mov1, 10);
  updateRating(mov2, 1);
  assert(whichMovieShouldIWatch(mov1, mov2) == 1);

  // Test mov2 has higher rating
  updateRating(mov1, 1);
  updateRating(mov2, 10);
  updateRating(mov2, 10);
  assert(whichMovieShouldIWatch(mov1, mov2) == 2);

  deleteMovie(mov1);
  deleteMovie(mov2);
}

void testPrintSummary() {
  movie *mov = newMovie("Dune: Part Two", 2024, "Timothée Chalomet", "Zendaya");

  updateRating(mov, 10);
  updateRating(mov, 1);

  assert(printSummary(mov) == 0);

  deleteMovie(mov);
}

/**********************************************************************
 * Library implementation
 *********************************************************************/

struct _movie {
  char *title;
  int release_year;
  char *lead_actor;
  char *lead_actress;
  int num_ratings;
  double average_rating;
};

movie *newMovie(char *title, int release_year, char *lead_actor,
                char *lead_actress) {
  if (title == NULL || lead_actor == NULL || lead_actress == NULL) {
    return NULL;
  }
  // Check that year format is valid
  if (release_year < 1900 || release_year > 2030) {
    return NULL;
  }
  // Create new movie
  movie *mov = (movie *)malloc(sizeof(movie));
  mov->title = title;
  mov->release_year = release_year;
  mov->lead_actor = lead_actor;
  mov->lead_actress = lead_actress;
  mov->num_ratings = 0;
  mov->average_rating = 0.0;
  return mov;
}

int updateRating(movie *mov, int rating) {
  if (mov == NULL || rating < 1 || rating > 10) {
    return -1;
  }
  // Update rating
  mov->average_rating = (mov->average_rating * mov->num_ratings + rating) /
                        (mov->num_ratings + 1);
  // Update raing count
  mov->num_ratings++;
  return 0;
}

int whichMovieShouldIWatch(movie *mov1, movie *mov2) {
  if (mov1 == NULL || mov2 == NULL) {
    return -1;
  }
  // Compare ratings
  if (mov1->average_rating > mov2->average_rating) {
    return 1;
  } else if (mov1->average_rating < mov2->average_rating) {
    return 2;
  } else {
    return 0;
  }
}

int printSummary(movie *mov) {
  if (mov == NULL) {
    return -1;
  }
  // Print summary
  printf("%s (%d) starring %s and %s.\n", mov->title, mov->release_year,
         mov->lead_actor, mov->lead_actress);
  // Print fancy rating bar graph
  printf("Rating: %.2lf/10 [", mov->average_rating);
  for (int i = 0; i < (int)mov->average_rating; i++) {
    printf("*");
  }
  for (int i = 0; i < 10 - (int)mov->average_rating; i++) {
    printf("-");
  }
  printf("]\n");
  return 0;
}

int deleteMovie(movie *mov) {
  if (mov == NULL) {
    return -1;
  }
  free(mov);
  return 0;
}
