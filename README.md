## Introduction

This project is kinda an assignment where the goal is to develop a project
leaded by tests.

We use `unsigned int` in place of `size_t` during the whole project.

## Makefile

    make

Compiles the project in the bin folder (`BIN_FOLDER` variable in `Makefile`),
and objects in the object folder (`OBJ_FOLDER` variable).

    make tidy

As the default make, but cleans the object folder.

    make run

Compiles and execute the software.

    make leak

Compiles the project adding debugging options (`-g -ggdb3`) and launches the
software with `valgrind` to trace leaks and bad memory accesses.

## String functions

1. `my_strlen`

       unsigned int my_strlen(const char* s)

    Counts the number of letters in the string until the first '\0'.

2. `my_strcmp` and `my_strncmp`

       int my_strcmp(const char* s1, const char* s2)

   Compares the two strings.
   Return values is `s1[i] - s2[i]` with `i` being the index of either the
   first mismatching char or the end of the strings.

       int my_strncmp(const char* s1, const char* s2, const unsigned int lim)

   Does exactly the same as `my_strcmp`, but takes as its last argument a
   limit of characters to compare.

3. `my_strcpy` and `my_strncpy`

       char* my_strcpy(char* dest, const char* src)

   Copies the integrality of `src` in `dest` including terminating '\0'.
   Please note the necessity of `dest` to be larger than `src`.

       char* my_strncpy(char* dest, const char* src, const unsigned int n)

   Does the same as `my_strcpy`, but copies `n` characters of `src`.
   If there is no `0` in the `n` first bytes of `src`, the string
   in `dest` isn't terminated.
   If `n` is greater than the length of `src`, it fills the remaining with
   '\0'.

4. `my_strdup`

       char* my_strdup(const char* s)

   Creates a copy of the string `s` and returns it.

5. `my_strcat` and `my_newstrcat`

       char* my_strcat(char* dest, const char* src);

   Appends the content of `src` into dest, replacing the initial `\0`
   and appending one at the end.
   Please note the necessity of `dest` to be larger than `dest + src`.

       char* my_newstrcat(const char* s1, const char* s2)

   Takes two strings as parameter and combines them, returning a new one.

6. `my_strtok` and `free_keys`

       char** my_strtok(const char* s, const char* delim)

   This is not the standard behaviour of strtok, but allows for more
   flexibility.
   This function takes a string `s` and a delimiter `delim`, and splits `s`
   in an array of substrings, e.g. `my_strtok("a-b-c", "-")` gives
   `["a", "b", "c"]`

       void my_freek(char** a)

   This function is made to clear the array returned by `my_strtok`.
