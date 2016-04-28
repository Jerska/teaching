#ifndef MACROS_H_
# define MACROS_H_

#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)

#define _WRITE(s, stream)                                                       \
  do {                                                                          \
    write(STD ## stream ## _FILENO, s, my_strlen(s));                           \
  } while (0)

#define WRITE(s)                                                                \
  _WRITE(s, OUT)

#define WRITE_ERR(s)                                                            \
  _WRITE(s, ERR)

#define ASSERT(cond)                                                            \
  do {                                                                          \
    if (cond) {                                                                 \
      WRITE("\033[32m\t\t[ OK ] \033[0m");                                      \
      WRITE(STRINGIZE(cond));                                                   \
      WRITE("\n");                                                              \
    }                                                                           \
    else {                                                                      \
      WRITE_ERR("\033[31m\t\t[ KO ] \033[0m");                                  \
      WRITE_ERR(STRINGIZE(cond));                                               \
      WRITE_ERR("\n");                                                          \
    }                                                                           \
  } while (0)

#define CATEGORY(cat)                                                           \
  do {                                                                          \
    WRITE("\n");                                                                \
    WRITE("\033[33m\t[ CAT ] \033[0m");                                         \
    WRITE(STRINGIZE(cat));                                                      \
    WRITE("\n");                                                                \
  } while (0)

#endif // MAIN_H_
