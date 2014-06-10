#include "main.h"

int main(void) {
  char*   tmp   = NULL;
  char**  tab   = NULL;

  CATEGORY(my_strlen);
  ASSERT(my_strlen("") == 0);
  ASSERT(my_strlen("abcd") == 4);
  ASSERT(my_strlen("a\0b") == 1);

  CATEGORY(my_strcmp);
  ASSERT(my_strcmp("", "") == 0);
  ASSERT(my_strcmp("a", "a") == 0);
  ASSERT(my_strcmp("a\0b", "a") == 0);
  ASSERT(my_strcmp("a", "a\0b") == 0);
  ASSERT(my_strcmp("a", "c") == -2);
  ASSERT(my_strcmp("c", "a") == 2);
  ASSERT(my_strcmp("c\0b", "a") == 2);
  ASSERT(my_strcmp("c", "a\0b") == 2);
  ASSERT(my_strcmp("ab", "a") == 'b');
  ASSERT(my_strcmp("a", "ab") == -'b');

  CATEGORY(my_strncmp);
  ASSERT(my_strncmp("abcd", "abce", 4) == -1);
  ASSERT(my_strncmp("abcd", "abed", 4) == -2);
  ASSERT(my_strncmp("abc", "abe", 2) == 0);
  ASSERT(my_strncmp("a", "b", 0) == 0);
  ASSERT(my_strncmp("abc", "abc", 10) == 0);
  ASSERT(my_strncmp("aba", "abc", 10) == -2);

  CATEGORY(my_strcpy);
  ASSERT((tmp = malloc(4)) && (tmp = my_strcpy(tmp, "abc")) && my_strcmp(tmp, "abc") == 0); free(tmp);
  ASSERT((tmp = malloc(6)) && (tmp = my_strcpy(tmp, "abc\0a")) && my_strcmp(tmp, "abc") == 0); free(tmp);

  CATEGORY(my_strncpy);
  ASSERT((tmp = malloc(6)) && (tmp = my_strncpy(tmp, "abc\0a", 6)) && my_strcmp(tmp, "abc") == 0); free(tmp);
  ASSERT((tmp = malloc(6)) && (tmp = my_strncpy(tmp, "abc\0a", 6)) && "abc\0a"[4] == 'a' && tmp[4] == '\0'); free(tmp);
  ASSERT((tmp = malloc(4)) && (tmp = my_strncpy(tmp, "abcd", 3)) && tmp[2] != '\0'); free(tmp);

  CATEGORY(my_strdup);
  ASSERT((tmp = my_strdup("abc")) && my_strlen(tmp) == my_strlen("abc")); free(tmp);
  ASSERT((tmp = my_strdup("abc\0a")) && my_strlen(tmp) == my_strlen("abc\0a")); free(tmp);
  ASSERT((tmp = my_strdup("abc")) && my_strcmp("abc", tmp) == 0); free(tmp);
  ASSERT((tmp = my_strdup("abc\0a")) && my_strcmp("abc", tmp) == 0); free(tmp);
  ASSERT((tmp = my_strdup("abc")) && my_strcmp("abc\0a", tmp) == 0); free(tmp);

  CATEGORY(my_strcat);
  ASSERT((tmp = malloc(1)) && ((tmp[0] = '\0') || 1) && my_strcat(tmp, "") && my_strcmp(tmp, "") == 0); free(tmp);
  ASSERT((tmp = malloc(5)) && (tmp[0] = 'a') && ((tmp[1] = '\0') || 1) && my_strcat(tmp, "bcd") && my_strcmp(tmp, "abcd") == 0); free(tmp);
  ASSERT((tmp = malloc(5)) && (tmp[0] = 'a') && ((tmp[1] = '\0') || 1) && (tmp = my_strcat(tmp, "bcd")) && my_strcmp(tmp, "abcd") == 0); free(tmp);
  ASSERT((tmp = malloc(6)) && (tmp[0] = 'a') && ((tmp[1] = '\0') || 1) && my_strcat(tmp, "bcd") && my_strcmp(tmp, "abcd") == 0); free(tmp);

  CATEGORY(my_newstrcat);
  ASSERT((tmp = my_newstrcat("", "")) && my_strcmp(tmp, "") == 0); free(tmp);
  ASSERT((tmp = my_newstrcat("a", "bcd")) && my_strcmp(tmp, "abcd") == 0); free(tmp);
  ASSERT((tmp = my_newstrcat("a\0e", "bcd\0f")) && my_strcmp(tmp, "abcd") == 0); free(tmp);

  CATEGORY(my_strtok);
  ASSERT((tab = my_strtok("a,b,c", ",")) && my_strcmp(tab[0], "a") == 0 && my_strcmp(tab[1], "b") == 0 && my_strcmp(tab[2], "c") == 0 && tab[3] == NULL); my_freek(tab);
  ASSERT((tab = my_strtok("a,,b,,c", ",,")) && my_strcmp(tab[0], "a") == 0 && my_strcmp(tab[1], "b") == 0 && my_strcmp(tab[2], "c") == 0 && tab[3] == NULL); my_freek(tab);
  ASSERT((tab = my_strtok(",,,,", ",,")) && my_strcmp(tab[0], "") == 0 && my_strcmp(tab[1], "") == 0 && my_strcmp(tab[2], "") == 0 && tab[3] == NULL); my_freek(tab);

  return 0;
}
