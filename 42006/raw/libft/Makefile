# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akjoerse <akjoerse@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 18:49:04 by akjoerse          #+#    #+#              #
#    Updated: 2025/04/23 19:45:39 by akjoerse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	Makefile must account for previous `ft_printf/Makefile`
NAME = libft.a
INC = -Ilibft.h -I./ft_printf -I./get_next_line
CC = cc -g
CFLAGS = -Wall -Werror -Wextra $(INC)
all: $(NAME)
# libft vanilla
SRC = src/ft_putendl_fd.c src/ft_putnbr_fd.c \
src/ft_toupper.c src/ft_isalpha.c src/ft_isdigit.c src/ft_atoi.c \
src/ft_strjoin.c src/ft_strtrim.c src/ft_split.c src/ft_tolower.c \
src/ft_strchr.c src/ft_strrchr.c src/ft_strncmp.c src/ft_memchr.c \
src/ft_memmove.c src/ft_strnstr.c src/ft_strlcpy.c src/ft_bzero.c \
src/ft_calloc.c src/ft_striteri.c src/ft_substr.c src/ft_strlcat.c \
src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_strlen.c \
src/ft_memcmp.c src/ft_memset.c  src/ft_memcpy.c src/ft_putstr_fd.c \
src/ft_strmapi.c src/ft_putchar_fd.c src/ft_strdup.c src/ft_itoa.c
PTF = ft_printf/ft_printf.c \
ft_printf/ft_ptfuin_put.c ft_printf/ft_ptfvex.c ft_printf/ft_uitoa.c \
ft_printf/ft_ptfnumlen.c ft_printf/ft_ptfptr.c ft_printf/ft_ptfstr.c \
ft_printf/ft_ptfcha.c ft_printf/ft_ptfhex.c ft_printf/ft_ptfhex_len.c \
ft_printf/ft_ptfhex_put.c ft_printf/ft_ptfint.c ft_printf/ft_ptfint_put.c
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o) $(PTF:%.c=%.o) $(GNL:%.c=%.o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all