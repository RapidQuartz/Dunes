# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:56:13 by akjoerse          #+#    #+#              #
#    Updated: 2025/02/28 12:33:34 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Werror -Wextra
# LIB = /Users/akjoerse/Code/4_github/42001/libft #for mac
LIB = /home/akjoerse/42/999_GitHub/42001/libft/ #for linux
LIBFT = libft.a
SRC = main.c \
sort/push_swap.c \
args/arg_inspector.c args/arg_array.c \
check/sort_checker.c \
ops/push.c ops/rotate.c ops/swap.c \
stack/stack_indexer.c stack/stack_inspector.c \
stack/stack_maker.c \
stack/stack_navigator.c \
cost/stack_assay.c sort/stack_sorter.c \
util/utilities.c util/error_handling.c util/memory_utils.c
OBJ = $(SRC:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(GREEN)\n\n\n\n\t\t\tmaking the libft library\n$(RESET)"
	# @sleep 2
	make -C $(LIB)

$(NAME): $(OBJ)
	@echo "$(BLUE)\n\n\n\n\t\t\tcompiling\n$(RESET)"
	# @sleep 2
	$(CC) $^ -L/home/akjoerse/42/999_GitHub/42001/libft -lft -o $(NAME)


$(OBJ): %.o: %.c
	@echo "$(GREEN)\n\n\n\n\t\t\tmaking the object files\n$(RESET)"
	$(CC) -c $^ -o $@


clean:
	@echo "$(YELLOW)\n\n\n\n\t\t\tremoving object files\n$(RESET)"
	# @sleep 2
	rm -f $(OBJ)
	make -C $(LIB) clean	

fclean: clean
	@echo "$(YELLOW)\n\n\n\n\t\t\tremoving the program files\n$(RESET)"
	# @sleep 2
	rm -f $(NAME)
	make -C $(LIB) fclean	

re: fclean all
	@echo "$(GREEN)\n\n\n\n\t\t\tremaking the project$(RESET)"
	# @sleep 2

RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RESET  = \033[0m

.PHONY: all clean fclean re
