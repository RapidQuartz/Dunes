NAME = libftprintf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I./LIB
LIBFT = LIBFT/ 
SRCS = SRC/ft_printf.c SRC/ft_ptfcha.c SRC/ft_ptfhex_put.c SRC/ft_ptfhex.c \
	SRC/ft_ptfint_put.c SRC/ft_ptfint.c SRC/ft_ptfptr.c SRC/ft_ptfstr.c \
	SRC/ft_ptfuin_put.c SRC/ft_ptfhex_len.c SRC/ft_ptfnumlen.c \
	SRC/ft_ptfvex.c SRC/ft_uitoa.c
OBJS = $(SRCS:%.c=%.o)

NOCOLOR = \033[0m
REDCOLOR = \033[0;31m
GREENCOLOR = \033[0;32m
YELLOWCOLOR = \033[0;33m
BLUECOLOR = \033[0;34m

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS) ../libft.a
		@echo "$(GREENCOLOR)ft_printf compiled$(NOCOLOR)"

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@
		@echo "$(BLUECOLOR)compiling...$(NOCOLOR)"

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C ./LIBFT
		@echo "$(REDCOLOR)removed ft_printf object files$(NOCOLOR)"
	

fclean:	clean
		$(RM) $(NAME)
		$(RM) libft.a
		$(MAKE) fclean -C ./LIBFT
		@echo "$(YELLOWCOLOR)removed ft_printf executable files$(NOCOLOR)"

re:	fclean all

.PHONY:	all clean re fclean
#@echo "$(NOCOLOR)"