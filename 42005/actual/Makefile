NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
SRC = main.c \
init.c \
array.c \
turk.c \
push_swap.c \
rotate.c \
reverse.c \
cost.c \
check.c \
find.c \
util.c \
error.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

RED	= \033[1;31m
GRN	= \033[1;32m
YLW	= \033[1;33m
BLU	= \033[1;34m
DEF	= \033[0m

.PHONY: all clean fclean re