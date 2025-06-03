
NAME = fdf

CC = gcc -g 

SRC = ./src($SRCS)

SRCS = main.c

INC = ../resources/minilibx-linux($INCS)

INCS = 

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

