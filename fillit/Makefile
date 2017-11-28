NAME = fillit

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC =	main.c\
			read_me.c\
			check_me.c\
			validate_me.c\
			help_me.c\
			solve_me.c\
			ft_putendl.c\
			ft_strncpy.c\
			ft_strsub.c\
			ft_memdel.c\

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	$(CC) $(FLAG) $(SRC) -c
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -I ./includes

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
