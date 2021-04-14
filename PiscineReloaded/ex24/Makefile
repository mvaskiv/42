CC = gcc
NAME = libft.a
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_swap.c srcs/ft_strlen.c
OFILE = ft_putchar.o ft_putstr.o ft_strcmp.o ft_swap.o ft_strlen.o
HEAD = includes
FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -I $(HEAD)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
