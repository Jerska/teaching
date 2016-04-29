#include "my_strdup.h"

char* my_strdup(const char* s) {
  unsigned int len = my_strlen(s) + 1;
  char* res = malloc(sizeof (char) * len);
  return my_strncpy(res, s, len);
}
