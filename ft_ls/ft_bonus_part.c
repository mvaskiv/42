/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:25:19 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 20:21:36 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_insert_unsorted(t_files **folders, t_files *new)
{
	t_files		*temp;

	if ((*folders) == NULL)
	{
		(*folders) = new;
		(*folders)->next = NULL;
	}
	else
	{
		temp = *folders;
		while ((*folders)->next != NULL)
			(*folders) = (*folders)->next;
		(*folders)->next = new;
		*folders = temp;
	}
}

void		ft_write_dont_sort(t_files **files, DIR *dir, t_flags *flag,
							char *path)
{
	struct dirent	*directory;
	t_files			**start;

	start = files;
	while ((directory = readdir(dir)))
	{
		while (flag->a != 1 && directory->d_name[0] == '.')
		{
			directory = readdir(dir);
			if (directory == NULL)
				return ;
		}
		ft_insert_unsorted(start, ft_new_node(directory, path));
	}
}

void		ft_read_list_g(t_files *files, t_l_out width)
{
	struct group	*gr;
	struct tm		*tm;

	tm = localtime(&files->data->time);
	gr = getgrgid(files->data->group);
	ft_print_type(files);
	ft_mini_printf((files->data->mode & S_IRUSR) ? "r" : "-");
	ft_mini_printf((files->data->mode & S_IWUSR) ? "w" : "-");
	ft_set_uid(files);
	ft_mini_printf((files->data->mode & S_IRGRP) ? "r" : "-");
	ft_mini_printf((files->data->mode & S_IWGRP) ? "w" : "-");
	ft_mini_printf((files->data->mode & S_IXGRP) ? "x" : "-");
	ft_mini_printf((files->data->mode & S_IROTH) ? "r" : "-");
	ft_mini_printf((files->data->mode & S_IWOTH) ? "w" : "-");
	ft_sticky_bit(files);
	ft_read_ext_perm(files->path);
	ft_mini_printf("%*d ", width.n_sl, files->data->link);
	ft_mini_printf("%-*s", (width.n_gr + 1), gr->gr_name);
	ft_mini_printf("%*d", (width.n_sz + 1), files->data->size);
	ft_print_time(tm, files->data->time);
	ft_mini_printf(" %s", files->name);
	ft_read_link(files);
	ft_putchar('\n');
}

void		ft_write_color(t_files *files)
{
	if (S_ISDIR(files->data->mode))
	{
		ft_mini_printf(CYN);
		ft_mini_printf("%s\n", files->name);
		ft_mini_printf(NRM);
	}
	else if (S_ISLNK(files->data->mode))
	{
		ft_mini_printf(YEL);
		ft_mini_printf("%s\n", files->name);
		ft_mini_printf(NRM);
	}
	else if (files->data->mode & S_IEXEC)
	{
		ft_mini_printf(RED);
		ft_mini_printf("%s\n", files->name);
		ft_mini_printf(NRM);
	}
	else
		ft_mini_printf("%s\n", files->name);
}