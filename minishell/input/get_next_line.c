/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:57:24 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/22 18:41:05 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int			ft_endl(char *string)
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

static t_storage	*ft_find_file(t_storage **storage, int fd, char **tmp)
{
	t_storage		*temp;
	t_storage		**start;

	*tmp = ft_strnew(BUFF_SIZE + 1);
	start = storage;
	temp = *storage;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = (t_storage*)malloc(sizeof(t_storage));
	temp->content = NULL;
	temp->fd = fd;
	temp->next = *start;
	*storage = temp;
	temp = *storage;
	return (temp);
}

static char			*ft_read_n_write(char *string, char *tmp, int ret)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (ret && tmp)
		tmp[ret] = '\0';
	if (string != NULL)
		i = ft_strlen(string);
	if (tmp != NULL)
		j = ft_strlen(tmp);
	str = (char *)malloc(sizeof(char*) * (i + j + 1));
	ft_memmove(str, string, i);
	ft_memmove(str + i, tmp, j);
	str[i + j] = '\0';
	if (string != NULL)
		free(string);
	if (tmp != NULL)
		ft_strclr(tmp);
	return (str);
}

static int			ft_check_endl(t_storage *storage, char **tmp,
									char **line, int ret)
{
	int		endl;
	char	*to_keep;

	endl = 0;
	to_keep = NULL;
	storage->content = ft_read_n_write(storage->content, *tmp, ret);
	endl = ft_endl(storage->content);
	if (endl > -1)
	{
		*line = ft_strdup(storage->content);
		to_keep = ft_strdup(storage->content + endl);
		ft_strdel(&storage->content);
		storage->content = ft_strdup(to_keep);
		ft_strdel(&to_keep);
		ft_strdel(tmp);
		return (1);
	}
	ft_strdel(tmp);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_storage	*storage_s;
	char				*tmp;
	int					output;
	int					ret;
	t_storage			*storage;

	storage = ft_find_file(&storage_s, fd, &tmp);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = (int)read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if ((output = ft_check_endl(storage, &tmp, line, ret)) == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE + 1);
	}
	if ((output = ft_check_endl(storage, &tmp, line, ret)))
		return (1);
	else if (ft_strlen(storage->content) > 1)
	{
		*line = ft_strdup(storage->content);
		ft_strdel(&storage->content);
		return (1);
	}
	storage_s = storage;
	return (output);
}
