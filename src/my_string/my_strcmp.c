#include "my_strcmp.h"

int my_strcmp(const char* s1, const char* s2) {
  return my_strncmp(s1, s2, -1);
}

int my_strncmp(const char* s1, const char* s2, const unsigned int lim) {
  unsigned int i = 0;

  while (
      i < lim &&
      s1[i] &&
      s2[i] &&
      s1[i] == s2[i]
  ) {
    ++i;
  }

  return i == lim ? 0 : s1[i] - s2[i];
}
