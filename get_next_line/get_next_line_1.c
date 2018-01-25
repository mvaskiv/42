/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:57:24 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/01/18 18:36:30 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // - to delete --------------------> !!!
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */



#include "get_next_line.h"

/* BEGINNING*/

/* ft_endl to find the end of the line and replace it with \0
to ease my life and particularly the process of the output
using the ft_strdup function or whatever*/

static int		ft_endl(char *buff)
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

/* ft_find_fd to get the righ file */

static t_storage		*ft_find_fd(t_storage *buff, int fd)
{
	t_storage	*to_read = buff;

	printf("inside find_fd\n");
	while (to_read != NULL)
	{
		if (to_read->fd == fd)
		{
			printf("found\n");
			return (to_read);
		}
		printf(GREEN "%i\n", RESET, to_read->fd);
		to_read = to_read->next;
	}
		buff = to_read;
		buff = (t_storage *)malloc(sizeof(t_storage));
		buff->fd = fd;
	return (ft_find_fd(buff, fd));
}

/* ft_read_lines */

static int		ft_read_lines(t_storage *buff, int fd, char *tmp, char **line)
{
	int			endl;
	char		*temp;
	t_storage	*to_read = buff;

	endl = ft_endl(to_read->content);
	if (endl > -1)//																		ALL OKAY
	{
		*line = ft_strdup(to_read->content);
		temp = to_read->content;
		temp += endl;
		ft_bzero(to_read->content, ft_strlen(to_read->content) + 1);
		to_read->content = ft_strdup(temp);
		printf(RED "%s\n" RESET, to_read->content);
		return (1);
	}
	return (0);
}

/* get_next_line body */

int			get_next_line(const int fd, char **line)
{
	static t_storage		*buff;
	t_storage			*temp;
	char				*tmp;
	int				output;
	int				ret;

	tmp = ft_strnew(BUFF_SIZE);
	// buff = (t_storage *)malloc(sizeof(t_storage));
	temp = ft_find_fd(buff, fd);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		output = ft_read_lines(temp, fd, tmp, line);
		free(tmp);
		if (output == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if (output = ft_read_lines(temp, fd, tmp, line))
		return (1);
	else if (temp->content && ft_strlen(temp->content) > 1)
	{
		*line = ft_strdup(temp->content);
		ft_strdel(&temp->content);
		return (1);
	}
	return (output);
}

/* THE END */

/* main to test this motherfucker */

int			main(int argc, char **argv)
{
	int fd0 = open(argv[1], O_RDONLY);
	int fd1 = open(argv[2], O_RDONLY);
	int ret = 0;
	char a = 'a';
	char *line;

	while ((ret = get_next_line(fd0, &line)))
		printf("%d %c ---> %s\n", ret, a++, line);
	while ((ret = get_next_line(fd1, &line)))
		printf("%d %c ---> %s\n", ret, a++, line);
	free(line);
	close(fd0);
	close(fd1);
	return (0);
}
