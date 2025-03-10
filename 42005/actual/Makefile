# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 11:41:01 by akjoerse          #+#    #+#              #
#    Updated: 2025/03/10 12:10:36 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g -v
CFLAGS = -Wall -Werror -Wextra
# LIB = /Users/akjoerse/Code/4_github/42001/libft
LIB = /home/akjoerse/42/999_GitHub/42001/libft/
LIBFT = libft.a
SRC = main.c push_swap.c \
branch/new_branch.c \
check/check_sort.c \
cost/cost.c \
init/arg_init.c \
util/utilities.c util/error.c
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
