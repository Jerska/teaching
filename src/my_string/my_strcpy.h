#ifndef MY_STRCPY_H_
# define MY_STRCPY_H_

# include <stdlib.h>
# include "my_strlen.h"

char* my_strcpy(char* dest, const char* src);
char* my_strncpy(char* dest, const char* src, const unsigned int n);

#endif // MY_STRCPY_H_
