
#include "get_next_line.h"

static char	*ft_overwrite(char *buff, char *tmp)
{
	unsigned long i;
	unsigned long j;
	char			*str;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tmp)
		j = ft_strlen(tmp);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	ft_memcpy(str, buff, i);
	ft_memcpy(str + i, tmp, j);
	str[i + j] = '\0';
	if (buff)
		ft_bzero(buff, ft_strlen(buff));
	ft_bzero(tmp, BUFF_SIZE + 1);
	return (str);
}

static int	ft_endl(char *buff)
{
	int		i;

	i = 0;
	while ((buff[i] != '\n') && buff[i])
		i++;
	if (buff[i] == '\n')
	{
		buff[i] = '\0';
		return (i + 1);
	}
	else
		return (-1);
}

static int	ft_check(char **buff, char **tmp, char **line)
{
	int		final;

	*buff = ft_overwrite(*buff, *tmp);
	final = ft_endl(*buff);
	if (final > -1)
	{
		*line = ft_strdup(*buff);
		*buff = ft_strdup(*buff + final);
		return (1);
	}
	return (0);
}

static char		**ft_setthings(char **buff, int fd, char **tmp)
{
	*tmp = ft_strnew(BUFF_SIZE);
	if (!buff)
		buff = (char**)malloc(sizeof(int) * fd * 100);
	return (buff);
}

int			get_next_line(const int fd, char **line)
{
	static char **buff;
	char			*tmp;
	int				ret;
	int				output;

	buff = ft_setthings(buff, fd, &tmp);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		output = ft_check(&buff[fd], &tmp, line);
		ft_bzero(tmp, BUFF_SIZE + 1);
		if (output == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((output = ft_check(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 1)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (output);
}

/* main */

#include <stdio.h>
int		main(int argc, char **argv)
{
	int fd;
	int ret;
	char a = 'a';
	char *line;
	int fd2 = open(argv[2], O_RDONLY);

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d %c -> %s\n", ret, a++, line);
	}
	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("%d %c -> %s\n", ret, a++, line);
	}
	close(fd);
	return (0);
}
