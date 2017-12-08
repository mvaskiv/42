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

int		get_next_line(const int fd, char **line)
{
	int			j;
	char		c;
	char *str;
	int		file;

	ft_strclr(*line);
	file = read(fd, &c, BUFF_SIZE);
	j = 0;
	str = *line;
	while (file)
	{
			str[j++] = c;
			file = read(fd, &c, BUFF_SIZE);
			if (c == '\n')
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
