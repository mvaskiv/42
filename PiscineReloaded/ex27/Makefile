CC = gcc
NAME = ft_display_file
FILES = main.c help_me.c
OFILE = $(FILES:.c=.o)
FLAG = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(CC) $(FLAG) $(FILES)
	$(CC) $(OFILE) -o $(NAME)

clean:
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

