# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:48:00 by mvaskiv           #+#    #+#              #
#    Updated: 2018/02/18 18:48:50 by mvaskiv          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.a

SRC = ft_get_details.c\
      ft_set_width.c\
      main.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ) libft/libft.a
	ranlib $(NAME)

%.o: %.c $(HEAD)
	$(MAKE) -C libft/
	$(CC) $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
