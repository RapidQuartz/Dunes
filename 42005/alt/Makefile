# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:56:13 by akjoerse          #+#    #+#              #
#    Updated: 2025/02/17 11:06:17 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
# LIB = /Users/akjoerse/Code/4_github/42001/libft
LIB = /home/akjoerse/42/999_GitHub/42001/libft/
LIBFT = libft.a
SRC = \
introduction.c \
push_swap.c \
check/arg_inspector.c check/sort_checker.c \
cost/cost.c \
operations/push.c operations/rotate.c operations/swap.c \
sort/sort3.c \
stack/stack_indexer.c stack/stack_inspector.c \
stack/stack_maker.c stack/stack_navigator.c \
utility/utilities.c utility/error_handling.c
OBJ = $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(GREEN)making the libft library\n$(RESET)"
	# @sleep 2
	make -C $(LIB)

$(NAME): $(OBJ)
	@echo "$(BLUE)compiling\n$(RESET)"
	# @sleep 2
	$(CC) $^ -L/home/akjoerse/42/999_GitHub/42001/libft -lft -o $(NAME)


$(OBJ): %.o: %.c
	@echo "$(GREEN)making the object files\n$(RESET)"
	$(CC) -c $^ -o $@


clean:
	@echo "$(YELLOW)removing object files\n$(RESET)"
	# @sleep 2
	rm -f $(OBJ)
	make -C $(LIB) clean	

fclean: clean
	@echo "$(YELLOW)removing the program files\n$(RESET)"
	# @sleep 2
	rm -f $(NAME)
	make -C $(LIB) fclean	

re: fclean all
	@echo "$(GREEN)remaking the project$(RESET)"
	# @sleep 2

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RESET  = \033[0m

.PHONY: all clean fclean re
