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

#include "get_next_line.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if (!(list = (t_list *)malloc(sizeof(*list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

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

t_list		*ft_find_fd(t_list **buff, int fd)
{
	t_list	*to_read = *buff;

	while (to_read)
	{
		ft_putendl("while");
		if (to_read->content_size == (size_t)fd)
			return (to_read);
		to_read = to_read->next;
	}
	to_read = ft_lstnew("\0", fd);
	ft_lstadd(buff, to_read);
	to_read = *buff;
	return (to_read);
}

/* ft_read_lines */

static int		ft_read_lines(t_list *buff, int fd, char *tmp, char **line)
{
	int			endl;
	char		*temp;
	t_list	*to_read = buff;

	if (to_read && to_read->content_size == (size_t)fd && tmp)
	{
				ft_putendl("second if");
		to_read->content = ft_strcat(to_read->content, tmp);
	}
	else if (!to_read)
	{
		ft_putendl("else");
		to_read = (t_list *)malloc(sizeof(t_list));
		// to_read = to_read->next;
		to_read->content_size = (size_t)fd;
		to_read->content = ft_strdup(tmp);
	}
	ft_putendl("in between");
	endl = ft_endl(to_read->content);
	if (endl > -1)//																		ALL OKAY
	{
		ft_putendl("final if");
		*line = ft_strdup(to_read->content);
		temp = to_read->content;
		temp += endl;
		ft_bzero(to_read->content, ft_strlen(to_read->content) + 1);
		to_read->content = ft_strdup(temp);
		return (1);
	}
	return (0);
}

/* get_next_line body */

int			get_next_line(const int fd, char **line)
{
	static t_list		*buff;
	t_list			*temp;
	char				*tmp;
	int				output;
	int				ret;

	tmp = ft_strnew(BUFF_SIZE);
	// buff = (t_list *)malloc(sizeof(t_list));
	temp = ft_find_fd(&buff, fd);
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
	else if (temp && ft_strlen(temp->content) > 1)
	{
		*line = ft_strdup(temp->content);
		ft_strdel(&temp->content);
		return (1);
	}
	return (output);
}

/* main to test this motherfucker */

#include <stdio.h>
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
