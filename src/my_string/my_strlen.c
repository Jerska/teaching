#include "my_strlen.h"

unsigned int my_strlen(const char* s) {
  unsigned int i = 0;

  while (s[i])
    ++i;

  return i;
}
