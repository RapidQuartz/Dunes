NAME = libftprintf.a
LIBFT = ./LIBFT/libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./LIB/ -I./LIBFT/
DIR = $(SRC) $(UTL)
INC = $(LIB)
SRC = $(_SRC)
UTL = $(_UTL)
LIB = $(_LIB)
OBJ = $(DIR:%.c=%.o)
_SRC = SRC/ft_printf.c SRC/ft_ptfcha.c SRC/ft_ptfhex_put.c SRC/ft_ptfhex.c \
	SRC/ft_ptfint_put.c SRC/ft_ptfint.c SRC/ft_ptfptr.c SRC/ft_ptfstr.c \
	SRC/ft_ptfuin.c
_LIB = LIB/ft_printf.h \
		LIBFT/libft.h
_UTL = UTL/ft_ptfhex_len.c UTL/ft_ptfnumlen.c UTL/ft_ptfvex.c UTL/ft_uitoa.c

all: $(NAME)

$(LIBFT):
	make -C LIBFT

$(NAME): $(LIBFT) $(OBJ) $(LIB)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./LIBFT

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./LIBFT

re: fclean all

.PHONY: all clean re fclean