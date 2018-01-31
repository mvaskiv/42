#include <stdio.h>


#include "get_next_line.h"

static void			ft_write(t_storage *storage, char *tmp)
{
	char			*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (storage->content)
		i = ft_strlen(storage->content);
	if (tmp)
		j = ft_strlen(tmp);
	// str = (char*)malloc(sizeof(char) * (i + j + 1));
	str = ft_strjoin(storage->content, tmp);
	// str[i + j] = '\0';
	ft_bzero(storage->content, i);
	ft_bzero(tmp, BUFF_SIZE + 1);
	storage->content = ft_strdup(str);
	free(str);
}

static int			ft_check_endl(char *storage)
{
		int			i;

		i = 0;
		while (storage[i] && (storage[i] != '\n'))
			i++;
		if (storage[i] == '\n')
		{
			storage[i] = '\0';
			return (i + 1);
		}
		else
			return (-1);
}

static int			ft_read_n_write(char **line, t_storage **storage, char **tmp)
{
		t_storage		*temp_storage;
		char			*to_keep;
		int				endl;

		temp_storage = *storage;
		ft_write(temp_storage, *tmp);
		endl = ft_check_endl(temp_storage->content);
		if (endl > -1)
		{
			*line = ft_strdup(temp_storage->content);
			to_keep = ft_strdup(temp_storage->content + endl);
			ft_strdel(&temp_storage->content);
			temp_storage->content = ft_strdup(to_keep);
			ft_strdel(&to_keep);
			free(to_keep);
			free(temp_storage);
			return (1);
		}
		return (0);
}

static t_storage		*ft_find_file(t_storage **storage, int fd)
{
	t_storage		*temp;

	temp = *storage;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_storage*)malloc(sizeof(t_storage));
	temp->fd = fd;
	return (temp);
}

int			get_next_line(const int fd, char **line)
{
		static t_storage		*storage;
		char				*tmp;
		int				output;
		int				ret;

		storage = ft_find_file(&storage, fd);
		tmp = ft_strnew(BUFF_SIZE + 1);
		while ((ret = read(fd, tmp, BUFF_SIZE) > 0))
		{
			output = ft_read_n_write(line, &storage, &tmp);
		}
}

int			main(int argc, char **argv)
{
	int fd0 = open(argv[1], O_RDONLY);
	int fd1 = open(argv[2], O_RDONLY);
	int ret = 0;
	char a = 'a';
	char *line;
	int q = argc;
	q = 0;

	while ((ret = get_next_line(fd0, &line)))
	{
		printf("%d %c ---> %s\n", ret, a++, line);
		ft_strdel(&line);
	}
	while ((ret = get_next_line(fd1, &line))){
		printf("%d %c ---> %s\n", ret, a++, line);
		ft_strdel(&line);
	}
	free(line);
	close(fd0);
	close(fd1);
	return (0);
}
