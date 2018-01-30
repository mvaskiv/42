/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:57:24 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/01/30 18:11:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // - to delete --------------------> !!!
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

// ---------------------------------------------------> !!!

#include "get_next_line.h"

/* BEGINNING*/

/* ft_endl to find the end of the line and replace it with \0
to ease my life and particularly the process of the output
using the ft_strdup function or whatever */

static int		ft_endl(char *string)
{
	int		i;

	i = 0;
	while ((string[i] != '\n') && string[i])
		i++;
	if (string[i] == '\n')
	{
		string[i] = '\0';
		return (i + 1);
	}
	else
		return (-1);
}

/*	ft_find_file to find the correct file in the storage list */

static t_storage		*ft_find_file(t_storage *storage, int fd)
{
	while (storage)
	{
		if (storage->fd == fd)
			return (storage);
		storage = storage->next;
	}
	// free(storage);
	storage = (t_storage*)malloc(sizeof(t_storage));
	storage->fd = fd;
	return (ft_find_file(storage, fd));
}

/* ft_read_n_write to read tmp, overwrite the existing data */

static char		*ft_read_n_write(char *string, char *tmp)
{
	int		i;
	int		j;
	char	*str = NULL;

	i = 0;
	j = 0;
	if (string != NULL)
		i = ft_strlen(string);
	if (tmp != NULL)
		j = ft_strlen(tmp);
	str = (char *)malloc(sizeof(char*) * (i + j) + 1);
	ft_memmove(str, string, i);
	ft_memmove(str + i, tmp, j);
	str[i + j] = '\0';
	if (string != NULL)
		free(string);
	if (tmp != NULL)
		ft_bzero(tmp, BUFF_SIZE + 1);
	return (str);
}

/* ft_check_endl to check for the /n in the storage->content and write **line accordingly */

static int		ft_check_endl(t_storage *storage, char *tmp, char **line)
{
	int		endl;
	char	*to_keep = NULL;

	storage->content = ft_read_n_write(storage->content, tmp);
	endl = ft_endl(storage->content);
	if (endl > -1)
	{
		*line = ft_strdup(storage->content);
		to_keep = storage->content;
		storage->content = ft_strdup(to_keep + endl);
		if (to_keep)
			ft_strdel(&to_keep);
		return (1);
	}
	return (0);
}

/* get_next_line body */

int		get_next_line(const int fd, char **line)
{
	static t_storage		*storage = NULL;
	char				*tmp;
	int				output;
	int				ret;

	tmp = ft_strnew(BUFF_SIZE + 1);
	storage = ft_find_file(storage, fd);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		output = ft_check_endl(storage, tmp, line);
		free(tmp);
		if (output == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE + 1);
	}
	if ((output = ft_check_endl(storage, tmp, line)))
	{
		free(tmp);
		return (1);
	}
	else if (ft_strlen(storage->content) > 1)
	{
		*line = ft_strdup(storage->content);
		printf(RED "%s\n - leftover" RESET, storage->content);
		free(storage);
		return (1);
	}
	free(tmp);
	// free(storage);
	sleep(3);


	return (output);
}

/* THE END */


int			main(int argc, char **argv)
{
	int fd0 = open(argv[1], O_RDONLY);
	int fd1 = open(argv[2], O_RDONLY);
	int ret = 0;
	char a = 'a';
	char *line = NULL;
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
