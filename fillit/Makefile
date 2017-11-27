NAME = fillit

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC =

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I ./includes

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
