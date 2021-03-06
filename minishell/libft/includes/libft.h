/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:43:03 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/12 12:16:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"
# define BBLK "\033[1m\033[30m"
# define BRED "\033[1m\033[31m"
# define BGRN "\033[1m\033[32m"
# define BYEL "\033[1m\033[33m"
# define BBLU "\033[1m\033[34m"
# define BMAG "\033[1m\033[35m"
# define BCYN "\033[1m\033[36m"
# define BWHT "\033[1m\033[37m"

typedef struct			s_list
{
	char				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_conv
{
	int					c;
	int					s;
	int					d;
	int					i;
	int					o;
	int					u;
	int					x;
	int					xh;
}						t_conv;

typedef struct			s_mini
{
	char				*string;
	int					width;
	int					type;
	int					sign;
	struct s_conv		conv;
}						t_mini;

size_t					ft_strlcat(char *dest, char const *src, unsigned int n);

void					ft_putchar(char c);
void					ft_putnbr(int n);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_bzero(void *s, unsigned int n);
void					*ft_memset(void *s, int c, unsigned int n);
void					*ft_memccpy(void *dest, const void *src, int c,
	unsigned int n);
void					*ft_memcpy(void *dest, const void *src,
	size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int,
	char *));
void					*ft_memmove(void *dest, const void *src,
	size_t n);
void					*ft_memchr(const void *s, int c, unsigned int n);

void					ft_lstdelone(t_list **alst, void (*del)(void *,
	size_t));
void					ft_lstdel(t_list **alst,
	void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_arrclr(char **arr);
void					*ft_return_to(char *string, char c);

char					*ft_strncpy(char *dest, const char *src,
	unsigned int n);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *s);
char					*ft_strncat(char *dest, const char *src,
	unsigned int n);
char					*ft_addchar(char **string, char c);
char					*ft_string_of_spaces(int size);
char					*ft_string_of_zeros(int size);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *haystack,
	const char *needle);
char					*ft_itoa(long long int n);
char					*ft_strrev(char *string);
char					*ft_dec_to_hex(int number, char c);
char					**ft_strsplit(char const *s, char c);
char					*ft_strtrim(char const *s);
char					*ft_strjoin(char *s1, char const *s2);
char					*ft_strnew(int size);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
	unsigned int len);
char					*ft_strnstr(char const *haystack,
	char const *needle,
	unsigned int n);

int						ft_mini_printf(const char *format, ...);
void					ft_convert(va_list arg, t_mini *mini);
int						ft_set_size(const char *format, va_list arg,
	char **string, t_mini width);
int						ft_memcmp(const void *s1, const void *s2,
	unsigned int n);
int						ft_strnequ(char const *s1, char const *s2,
	unsigned int n);
int						ft_strequ(char const *s1, char const *s2);
int						ft_atoi(const char *nptr);
int						ft_strncmp(const char *s1, const char *s2,
	unsigned int n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strlen(const char *s);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_intpositive(int i);
int						ft_longest_tab(char **arr);
unsigned int			ft_nbrlen(long long int n);
unsigned int			ft_int_base(int number, int base);
long long int			ft_longatoi(const char *nptr);
char					**ft_sorttab(char **arr);
char					**ft_sortrtab(char **arr);

#endif
