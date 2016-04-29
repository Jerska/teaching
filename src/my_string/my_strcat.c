#include "my_strcat.h"

char* my_strcat(char* dest, const char* src) {
  my_strcpy(dest + my_strlen(dest), src);
  return dest;
}

char* my_newstrcat(const char* s1, const char* s2) {
  unsigned int s1_len = my_strlen(s1);
  char* res = malloc(sizeof (char) * (s1_len + my_strlen(s2) + 1));

  my_strncpy(res, s1, s1_len);
  my_strcpy(res + s1_len, s2);

  return res;
}
