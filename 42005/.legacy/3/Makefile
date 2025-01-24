# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:56:13 by akjoerse          #+#    #+#              #
#    Updated: 2025/01/21 16:01:57 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
INC = -I push_swap.h
CC = cc -g
#-Wall -Werror -Wextra
SRC = algorithm.c do_ops.c main.c navigator.c operations.c push.c push_swap.c \
sort.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)


$(OBJ): %.o: %.c
	$(CC) -c $^ -o $@ $(INC)


clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re