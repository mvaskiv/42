#include "get_next_line.h"

static char	*ft_cat(char *buff, char *tab)
{
	unsigned long	i;
	unsigned long	j;
	char	*str;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	str = (char *)malloc(sizeof(*str) * (i + j + 1));
	ft_memcpy(str, buff, i);
	ft_memcpy(str + i, tab, j);
	str[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (str);
}

static int	ft_endl(char *buff)
{
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i] == '\n')
	{
		buff[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

static int	ft_check(char **buff, char **tab, char **line)
{
	char	*str;
	int		final;

	*buff = ft_cat(*buff, *tab);
	final = ft_endl(*buff);
	if (final > -1)
	{
		*line = ft_strdup(*buff);
		str = *buff;
		*buff = ft_strdup(*buff + final + 1);
		free(str);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char *buff[12000];
	char		*tmp;
	int			ret;
	int			o;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		o = ft_check(&buff[fd], &tmp, line);
		free(tmp);
		if (o == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((o = ft_check(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (o);
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
	line = (char *)malloc(sizeof(char) * 100);
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
