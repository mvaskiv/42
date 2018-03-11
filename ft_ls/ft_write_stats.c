/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:11:02 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 15:11:43 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_scan_flags(t_flags *flags, char **arg, int argc)
{
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (arg[i])
		{
			if (arg[i][0] != '-')
				break ;
			else
			{
				if ((ft_flag_error(arg[i])))
					return (0);
				flags->one = ft_strchr(arg[i], '1') ? 1 : flags->one;
				flags->a = ft_strchr(arg[i], 'a') ? 1 : flags->a;
				flags->l = ft_strchr(arg[i], 'l') ? 1 : flags->l;
				flags->r = ft_strchr(arg[i], 'r') ? 1 : flags->r;
				flags->rh = ft_strchr(arg[i], 'R') ? 1 : flags->rh;
				flags->t = ft_strchr(arg[i], 't') ? 1 : flags->t;
			}
			i++;
		}
	}
	return (1);
}

char		*ft_get_path(char *name, char *path)
{
	char	*fullname;
	int		i;

	fullname = (char*)malloc(sizeof(char) * 1024);
	i = 0;
	if (path[0] == '/' && path[1] == '\0')
	{
		i = 1;
		fullname[0] = '/';
		while (*name)
			fullname[i++] = *name++;
		fullname[i] = '\0';
	}
	else
	{
		while (*path)
			fullname[i++] = *path++;
		if (fullname[i - 1] != '/' && name[0] != '/')
			fullname[i++] = '/';
		while (*name)
			fullname[i++] = *name++;
		fullname[i] = '\0';
	}
	return (fullname);
}

void		ft_write_stats(t_files **files, char *path_a)
{
	t_files		*temp;
	char		*path;
	struct stat	stats;

	temp = *files;
	path = ft_get_path(temp->name, path_a);
	lstat(path, &stats);
	temp->path = ft_strdup(path);
	temp->data->dev = stats.st_dev;
	temp->data->group = stats.st_gid;
	temp->data->link = stats.st_nlink;
	temp->data->moddate = stats.st_mtimespec.tv_sec;
	temp->data->mode = stats.st_mode;
	temp->data->user = stats.st_uid;
	temp->data->size = stats.st_size;
	temp->data->blocks = stats.st_blocks;
	temp->data->time = stats.st_mtimespec.tv_sec;
	ft_strdel(&path);
}
