# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 14:08:49 by akjoerse          #+#    #+#              #
#    Updated: 2025/04/23 17:30:10 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
CC = cc -g
CF = -Wall -Werror -Wextra
RM = rm -f
LIBFT = libft.a
SRC = src
DIR_LIBFT = libft
LIB = $(DIR_LFT)/$(LIBFT)
OBJ = $(SRC:.c=.o)

all:	$(NAME)
	
# ONE RING APPROACH::COMBO PTF AND GNL INTO LIBFT
# $(NAME): $(OBJ) $(LIBFT) 
# 	$(CC) $(CF)
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CF) $(OBJ) -L$(DIR_LIBFT) -lft \
	-lftprinft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	@make -C $(DIR_LFT)

%.o: %.c
	$(CC) $(CF) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(DIR_LFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(DIR_LFT)
	
	
re: fclean all

RED	= \033[1;31m
GRN	= \033[1;32m
YLW	= \033[1;33m
BLU	= \033[1;34m
DEF	= \033[0m

.PHONY: all clean fclean re