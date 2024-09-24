#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Strips spaces from both the front and back of a string,
 * leaving any internal spaces alone.
 */
char* strip(char const *str) {
  int size = strlen(str);

  // This counts the number of leading and trailing spaces
  // so we can figure out how big the result array should be.
  int first_non_space = 0;
  while (first_non_space < size && str[first_non_space] == ' ') {
    ++first_non_space;
  }

  int last_non_space = size - 1;
  while (last_non_space >= 0 && str[last_non_space] == ' ') {
    --last_non_space;
  }

  // If the string consists of nothing but spaces, return an empty string.
  if (first_non_space > last_non_space) {
    char* result = (char*) calloc(1, sizeof(char));
    result[0] = '\0';
    return result;
  }

  // Allocate a slot for all the "saved" characters
  // plus one extra for the null terminator.
  int new_size = last_non_space - first_non_space + 1;
  char* result = (char*) calloc(new_size + 1, sizeof(char));

  // Copy in the "saved" characters.
  strncpy(result, str + first_non_space, new_size);
  result[new_size] = '\0';

  return result;
}

/*
 * Return true (1) if the given string is "clean", i.e., has
 * no spaces at the front or the back of the string.
 */
int is_clean(char const *str) {
  // We check if it's clean by calling strip and seeing if the
  // result is the same as the original string.
  char* cleaned = strip(str);

  // strcmp compares two strings, returning a negative value if
  // the first is less than the second (in alphabetical order),
  // 0 if they're equal, and a positive value if the first is
  // greater than the second.
  int result = strcmp(str, cleaned);

  // Free the memory allocated by strip
  free(cleaned);

  return result == 0;
}