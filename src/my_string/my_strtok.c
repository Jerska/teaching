#include "my_strtok.h"

char** my_strtok(const char* s, const char* delim) {
  unsigned int str_len = 0;
  unsigned int delim_len = my_strlen(delim);
  unsigned int nb_substrs = 0;
  unsigned int i = 0;
  char *tmp = NULL;
  char **res = NULL;

  if (delim_len == 0) {
    str_len = my_strlen(s);
    if (str_len != 0) {
      tmp = malloc(sizeof (char) * str_len * 2);
      while (i < str_len) {
        tmp[i * 2] = s[i];
        tmp[i * 2 + 1] = '\0';
        nb_substrs += 1;
        ++i;
      }
    }
    delim_len = 1;
  } else {
    tmp = my_strdup(s);
    nb_substrs = 1;
    while (tmp[i]) {
      if (my_strncmp(tmp + i, delim, delim_len) == 0) {
        tmp[i] = '\0';
        ++nb_substrs;
        i += delim_len;
      } else {
        ++i;
      }
    }
  }

  res = malloc(sizeof (char*) * (nb_substrs + 1));

  i = 0;
  while (i < nb_substrs) {
    res[i++] = tmp;
    tmp += my_strlen(tmp) + delim_len;
  }
  res[i] = NULL;

  return res;
}

void my_freek(char** a) {
  if (a[0] != NULL) {
    free(a[0]);
  }
  free(a);
}
