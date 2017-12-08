#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	ft_putendl(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

void		ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
			*s++ = '\0';
	}
}
char		*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char			*ft_strsub(char const *s, unsigned int start, unsigned int len)
{
	char				*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strncpy(str, &(s[start]), len);
	str[len] = '\0';
	return (str);
}


int		find_new_line(char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			j;
	static char		c[BUFF_SIZE];
	char *str;
	int		file;
	int i = 0;

	ft_strclr(*line);
	file = read(fd, c, BUFF_SIZE);
	j = 0;
	str = *line;
	while (file)
	{
		if (BUFF_SIZE == 1)
			while (*c != '\n')
			{
				str[j++] = *c;
				file = read(fd, c, BUFF_SIZE);
			}
		else
		{
				if (find_new_line(c, i + 1))
				{
					while (c[i] != '\n')
					{
						str[j++] = c[i++];
					}
					ft_strncpy(c, ft_strsub(c, i, BUFF_SIZE - i), BUFF_SIZE - i);
					i = 0;
					j = 0;
				}
		}
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char *line;
	int fd;
	int	fdq;
	int res;
	int i = 0;

	fd = open(argv[1], O_RDONLY);
		fdq = open(argv[2], O_RDONLY);
	ft_putendl("opened");
	line = (char *)malloc(sizeof(char) * 100);
	ft_putendl("malloced");
	res = get_next_line(fd, &line);
	ft_putendl(line);
		res = get_next_line(fdq, &line);
		ft_putendl(line);
			res = get_next_line(fd, &line);
			ft_putendl(line);
					res = get_next_line(fdq, &line);
					ft_putendl(line);
						res = get_next_line(fd, &line);
						ft_putendl(line);
							res = get_next_line(fd, &line);
							ft_putendl(line);
	free(line);
	return (res);
}
