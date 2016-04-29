#include "my_strcpy.h"

char* my_strcpy(char* dest, const char* src) {
  return my_strncpy(dest, src, my_strlen(src) + 1);
}

char* my_strncpy(char* dest, const char* src, const unsigned int n) {
  unsigned int i = 0;
  unsigned char over = 0;

  while (i < n) {
    dest[i] = over ? '\0' : src[i];
    if (!over && !src[i]) {
      over = 1;
    }
    ++i;
  }

  return dest;
}
