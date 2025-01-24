NAME = skeleton
SRC = arms.c bones.c legs.c skull.c spine.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	cc $^ -o $(NAME)


$(OBJ): %.o: %.c
	cc -c $^ -o $@


clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re