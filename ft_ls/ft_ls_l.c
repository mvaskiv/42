/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:28:08 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 16:42:25 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_month(int month_n)
{
	if (month_n == 0)
		return ("Jan");
	if (month_n == 1)
		return ("Feb");
	if (month_n == 2)
		return ("Mar");
	if (month_n == 3)
		return ("Apr");
	if (month_n == 4)
		return ("May");
	if (month_n == 5)
		return ("Jun");
	if (month_n == 6)
		return ("Jul");
	if (month_n == 7)
		return ("Aug");
	if (month_n == 8)
		return ("Sep");
	if (month_n == 9)
		return ("Oct");
	if (month_n == 10)
		return ("Nov");
	if (month_n == 11)
		return ("Dec");
	return (0);
}

void	ft_print_time(struct tm *tm, time_t file)
{
	time_t			now;

	time(&now);
	if ((now - file) < 15778463)
	{
		ft_mini_printf(" %s %2i ", ft_month(tm->tm_mon), tm->tm_mday);
		ft_mini_printf("%02i:%02i", tm->tm_hour, tm->tm_min);
	}
	else
	{
		ft_mini_printf(" %s %2i ", ft_month(tm->tm_mon), tm->tm_mday);
		ft_mini_printf("%5i", (1900 + tm->tm_year));
	}
}

void	ft_read_list(t_files *files, t_l_out width)
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
	ft_mini_printf("%-*s", (width.n_us + 2), ft_get_uname(files->data->user));
	ft_mini_printf("%-*s", (width.n_gr + 1), gr->gr_name);
	ft_mini_printf("%*d", (width.n_sz + 1), files->data->size);
	ft_print_time(tm, files->data->time);
	ft_mini_printf(" %s", files->name);
	ft_read_link(files);
	ft_putchar('\n');
}

void	ft_write_l_stats(t_files **files, char *path_a)
{
	t_files		*temp;
	char		*path;
	struct stat	stats;

	temp = *files;
	path = path_a;
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
}

void	ft_ls_l_output(t_files *temp, char *path)
{
	t_l_out		widths;
	struct stat	stats;
	t_files		*files;

	lstat(path, &stats);
	if ((S_ISLNK(stats.st_mode)))
	{
		ft_l_link(path);
		return ;
	}
	files = temp;
	ft_set_cols(files, &widths);
	ft_mini_printf("total %d\n", widths.blocks);
	while (files != NULL)
	{
		ft_read_list(files, widths);
		files = files->next;
	}
}
