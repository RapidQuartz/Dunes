
NAME = fdf
INC = -I./inc -I./mlx -I./libft/
CC = @cc -g
CF = -Wall -Werror -Wextra
RM = @rm -f
LIBFT = libft.a
SRC = omni.c
# main.c \
# src/init_fdf.c \
# src/parsing/parse_mapfile.c src/parsing/create_map.c \
# src/utility/helpers.c \
# src/drawing/project_map.c \
# src/utility/error.c src/utility/check_input.c
# src/
# src/parsing/
# src/utility/
OBJ = $(SRC:.c=.o)
#	maybe include an `objects` directory to keep things neat

all:	$(NAME)
	
$(NAME): $(OBJ) libft/libft.a 
	$(CC) $(CF) $(OBJ) -L./libft -lft \
	-L./mlx -lmlx -lX11 -lXext -lm -o $(NAME)

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