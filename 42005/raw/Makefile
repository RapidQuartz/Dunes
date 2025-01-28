# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:56:13 by akjoerse          #+#    #+#              #
#    Updated: 2025/01/26 16:21:02 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
LIB = /Users/akjoerse/Code/4_github/42001/libft
LIBFT = libft.a
SRC = algorithm.c do_ops.c main.c navigator.c operations.c push.c push_swap.c \
sort.c newgo.c error_handling.c init.c stack.c stack_utils.c util.c
OBJ = $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(GREEN)making the libft library\n$(RESET)"
	make -C $(LIB)

$(NAME): $(OBJ)
	@echo "$(BLUE)compiling\n$(RESET)"
	$(CC) $^ -L$(LIB) -lft -o $(NAME)


$(OBJ): %.o: %.c
	@echo "$(GREEN)making the object files\n$(RESET)"
	$(CC) -c $^ -o $@


clean:
	@echo "$(YELLOW)removing object files\n$(RESET)"
	rm -f $(OBJ)
	make -C $(LIB) clean	

fclean: clean
	@echo "$(YELLOW)removing the program files\n$(RESET)"
	rm -f $(NAME)
	make -C $(LIB) fclean	

re: fclean all
	@echo "$(GREEN)remaking the project$(RESET)"

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RESET  = \033[0m

.PHONY: all clean fclean re
