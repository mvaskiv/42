/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:43:03 by mvaskiv           #+#    #+#             */
/*   Updated: 2017/11/21 13:31:49 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list
{
	char				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

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
char				 	*ft_addchar(char *string, unsigned char c);
char 					*ft_string_of_spaces(unsigned int size);
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
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strnew(unsigned int size);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
	char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
	unsigned int len);
char					*ft_strnstr(char const *haystack,
	char const *needle,
	unsigned int n);

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
int 					ft_intpositive(int i);
unsigned int			ft_nbrlen(long long int n);
unsigned int			ft_int_base(int number, int base);
long long int			ft_longatoi(const char *nptr);

#endif
