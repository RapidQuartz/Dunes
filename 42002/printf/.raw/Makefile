NAME = libftprintf.a
CC = cc
CFLAGS = CFLAGS = -Wall -Werror -Wextra $(INC)
DIR = .
SRC = $(_SRC)
OBJ = $(SRC:.c=.o)
INC = -I$(_INC)

_SRC = ft_printf.c 
_INC = libft/libft.h ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -c ./libft
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) clean -c ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -c ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean