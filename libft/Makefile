# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 15:48:00 by mvaskiv           #+#    #+#              #
#    Updated: 2017/11/17 17:53:38 by mvaskiv          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = libft.h

SRC = ft_atoi.c\
      ft_strlen.c\
      ft_tolower.c\
      ft_toupper.c\
      ft_strdup.c\
      ft_strcpy.c\
      ft_strcmp.c\
      ft_strncpy.c\
      ft_memchr.c\
      ft_bzero.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_memccpy.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_strchr.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strstr.c\
      ft_strrchr.c\
      ft_strlcat.c\
      ft_strcat.c\
      ft_strncat.c\
      ft_strncpy.c\
      ft_memalloc.c\
      ft_memdel.c\
      ft_strnew.c\
      ft_strdel.c\
      ft_strclr.c\
      ft_striter.c\
      ft_striteri.c\
      ft_strmap.c\
      ft_strmapi.c\
      ft_strequ.c\
      ft_strnequ.c\
      ft_strsub.c\
      ft_strjoin.c\
      ft_strtrim.c\
      ft_strsplit.c\
      ft_itoa.c\
      ft_putchar.c\
      ft_putstr.c\
      ft_putendl.c\
      ft_putnbr.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_nbrlen.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Wextra -Werror

all:    $(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAG) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean  all
