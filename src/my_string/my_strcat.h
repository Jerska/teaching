#ifndef MY_STRCAT_H_
# define MY_STRCAT_H_

# include <stdlib.h>
# include "my_strlen.h"
# include "my_strcpy.h"

char* my_strcat(char* dest, const char* src);
char* my_newstrcat(const char* s1, const char* s2);

#endif // MY_STRCAT_H_
