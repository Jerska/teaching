#ifndef MY_STRTOK_H_
# define MY_STRTOK_H_

# include <unistd.h>
# include "my_strlen.h"
# include "my_strcmp.h"
# include "my_strdup.h"

char**  my_strtok(const char* s, const char* delim);
void    my_freek(char** a);

#endif // MY_STRTOK_H_
