CC=clang
CFLAGS=-Wall -Werror -Wextra -std=c99 -pedantic
LDFLAGS=

BIN=exe
SRC=main.c \
    my_string/my_strlen.c \
    my_string/my_strcmp.c \
    my_string/my_strcpy.c \
    my_string/my_strdup.c \
    my_string/my_strcat.c \
    my_string/my_strtok.c \

BIN_FOLDER=bin
SRC_FOLDER=src
OBJ_FOLDER=obj

BIN_=$(BIN_FOLDER)/$(BIN)
OBJS=$(foreach obj, $(SRC:.c=.o), $(OBJ_FOLDER)/$(obj))

# Colors
DEF=\\033[0m
RED=\\033[31m
GRE=\\033[32m
BLU=\\033[34m
MAG=\\033[35m

.PHONY: all
all: $(BIN_)

.PHONY: tidy
tidy: $(BIN_) softclean

.PHONY: run
run: $(BIN_)
	@echo -e "$(BLU)[ EXE ] $(DEF) $<"
	@$(EXEC) ./$(BIN_)

.PHONY: leak
leak: CFLAGS += -g -ggdb3
leak: EXEC += valgrind
leak: clean run

$(BIN_): $(OBJS)
	@mkdir -p $(BIN_FOLDER)
	@$(CC) $(LDFLAGS) $(OBJS) -o $(BIN_)
	@echo -e "$(MAG)[ LD  ] $(DEF) $(BIN_)"

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p `dirname $@`
	@$(CC) $(CFLAGS) -c $< $(INCS) -o $@
	@echo -e "$(GRE)[ CXX ] $(DEF) $@"

.PHONY: clean
clean: softclean
	@rm -rf $(BIN_FOLDER)
	@echo -e "$(RED)[ RM  ] $(DEF) $(BIN_FOLDER)"

.PHONY: softclean
softclean:
	@rm -rf $(OBJ_FOLDER)
	@echo -e "$(RED)[ RM  ] $(DEF) $(OBJ_FOLDER)"
