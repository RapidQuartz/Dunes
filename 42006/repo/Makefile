# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 14:08:49 by akjoerse          #+#    #+#              #
#    Updated: 2025/05/12 13:27:58 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INC = -I. -I./mlx -I./libft/
CC = @cc -g
CF = -Wall -Werror -Wextra
RM = @rm -f
LIBFT = libft.a
SRC = main.c \
src/init_fdf.c \
src/drawing/draw_hline.c src/drawing/draw_map.c src/drawing/draw_vline.c \
src/parsing/create_map.c src/parsing/parse_mapfile.c \
src/utility/get_dimensions.c src/utility/line_end.c src/utility/line_start.c \
src/utility/check_input.c src/utility/error_handling.c src/utility/debug.c \
src/utility/helpers.c
OBJ = $(SRC:.c=.o)
#	maybe include an `objects` directory to keep things neat

all:	$(NAME)
	
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
	@if [ -e "libft.a" ]; then rm libft.a; fi
	
re: fclean all

RED	= \033[1;31m
GRN	= \033[1;32m
YLW	= \033[1;33m
BLU	= \033[1;34m
DEF	= \033[0m

.PHONY: all clean fclean re