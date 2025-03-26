# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 16:30:29 by akjoerse          #+#    #+#              #
#    Updated: 2025/03/26 12:35:56 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# CC = cc -g -v
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
# LIB = /Users/akjoerse/Code/4_github/42001/libft
LIB = /home/akjoerse/42/999_GitHub/42001/libft/
LIBFT = libft.a
SRC = main.c push_swap.c \
arg.c arr.c init.c \
check.c cost.c sort.c push.c\
stack_nav.c \
util/debug.c util/utility.c turk.c
OBJ = $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB)

$(NAME): $(OBJ)
	$(CC) $^ -L/home/akjoerse/42/999_GitHub/42001/libft -lft -o $(NAME)


$(OBJ): %.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIB) clean	

fclean: clean
	rm -f $(NAME)
	make -C $(LIB) fclean	

re: fclean all

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RESET  = \033[0m

.PHONY: all clean fclean re
