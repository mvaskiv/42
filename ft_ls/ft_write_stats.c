/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_stats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:11:02 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 20:00:16 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_write_flags(t_flags *flags, char *arg)
{
	flags->one = ft_strchr(arg, '1') ? 1 : flags->one;
	flags->l = ft_strchr(arg, 'l') ? 1 : flags->l;
	flags->a = ft_strchr(arg, 'a') ? 1 : flags->a;
	flags->f = ft_strchr(arg, 'f') ? 1 : flags->f;
	flags->g = ft_strchr(arg, 'g') ? 1 : flags->g;
	flags->gh = ft_strchr(arg, 'G') ? 1 : flags->gh;
	flags->r = ft_strchr(arg, 'r') ? 1 : flags->r;
	flags->rh = ft_strchr(arg, 'R') ? 1 : flags->rh;
	flags->t = ft_strchr(arg, 't') ? 1 : flags->t;
	if (flags->l == 1 && flags->one == 1)
	{
		if (ft_strlen(ft_strrchr(arg, '1')) < ft_strlen(ft_strrchr(arg, 'l')))
			flags->l= 0;
		else if (ft_strlen(ft_strrchr(arg, '1')) > ft_strlen(ft_strrchr(arg, 'l')))
			flags->one = 0;
	}
}

void		ft_alter_flags(t_flags *flags)
{
	if (flags->f == 1)
	{
		flags->a = 1;
		flags->t = 0;
		flags->r = 0;
	}
	if (flags->g == 1)
		flags->l = 1;
}

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
				ft_write_flags(flags, arg[i]);
			}
			i++;
		}
	}
	ft_alter_flags(flags);
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
