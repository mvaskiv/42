# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:48:00 by mvaskiv           #+#    #+#              #
#    Updated: 2017/11/21 14:11:42 by mvaskiv          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = includes/libft.h

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
    $(MAKE) -C libft
	$(CC) $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean  all
