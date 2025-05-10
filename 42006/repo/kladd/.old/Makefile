# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 14:08:49 by akjoerse          #+#    #+#              #
#    Updated: 2025/05/10 16:37:33 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
INC = -I. -I./mlx -I./libft/
CC = @cc -g
CF = -Wall -Werror -Wextra
RM = @rm -f
LIBFT = libft.a
SRC = main.c \
src/arg_processing.c src/init_mlx.c src/map_matrix.c src/parse_map.c \
src/read_map.c src/fdf_util.c src/draw_map.c
#src/scratch_map.c
MLX = 
OBJ = $(SRC:.c=.o)

all:	$(NAME)
	
# ONE RING APPROACH::COMBO PTF AND GNL INTO LIBFT
# $(NAME): $(OBJ) $(LIBFT) 
# 	$(CC) $(CF)
$(NAME): $(OBJ) libft/libft.a 
	$(CC) $(CF) $(OBJ) -L. -lft \
	-lmlx -lX11 -lXext -lm -o $(NAME)

libft/libft.a:
	@make -sC libft/
	@cp libft/libft.a ./

%.o: %.c
	$(CC) $(CF) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -sC libft/

fclean: clean
	$(RM) $(NAME)
	@make fclean -sC libft/
	@rm libft.a
	
re: fclean all

RED	= \033[1;31m
GRN	= \033[1;32m
YLW	= \033[1;33m
BLU	= \033[1;34m
DEF	= \033[0m

.PHONY: all clean fclean re