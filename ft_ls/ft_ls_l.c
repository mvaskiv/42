
#include "ft_ls.h"

char 	*ft_get_uname(uid_t uid)
{
	struct passwd	*passwd;

	passwd = getpwuid(uid);
	if (passwd != NULL)
		return (passwd->pw_name);
	else
		return (NULL);
}

char 	*ft_month(int month_n)
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

void			ft_print_type(t_files *files)
{
	if (files->data->mode & S_IFIFO)
		ft_putchar('p');
	else if (S_ISDIR(files->data->mode))
		ft_putchar('d');
//	if (files->data->stats.st_mode & S_IFBLK)
//		ft_putchar('b');
	else if (S_ISLNK(files->data->mode))
		ft_putchar('l');
	else if (S_ISCHR(files->data->mode))
		ft_putchar('c');
	else if (S_ISSOCK(files->data->mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void			ft_read_list(t_files *files, char *path, t_l_out width)
{
//	ft_write_stats(&files, path);
	ft_print_type(files);
	ft_mini_printf( (files->data->mode & S_IRUSR) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWUSR) ? "w" : "-");
	ft_mini_printf( (files->data->mode & S_IXUSR) ? "x" : "-");
	ft_mini_printf( (files->data->mode & S_IRGRP) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWGRP) ? "w" : "-");
	ft_mini_printf( (files->data->mode & S_IXGRP) ? "x" : "-");
	ft_mini_printf( (files->data->mode & S_IROTH) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWOTH) ? "w" : "-");
	ft_mini_printf( (files->data->mode & S_IXOTH) ? "x" : "-");
	ft_read_ext_perm(path);
	ft_mini_printf("%*d ", width.n_sl, files->data->link);
	ft_mini_printf("%-*s", (width.n_us + 2), ft_get_uname(files->data->user));
//	ft_mini_printf("%-*s", (width.n_gr + 1), files->data->group.gr_name);
	ft_mini_printf("%*d", (width.n_sz + 1), files->data->size);
//	ft_mini_printf(" %s %2i %02i:%02i", ft_month(files->data->time->tm_mon), files->data->time->tm_mday, files->data->time->tm_hour, files->data->time->tm_min);
	ft_mini_printf(" %s", files->name);
	ft_read_link(files, path);
	ft_putchar('\n');
}

void	ft_ls_l_output(t_files *files, char *path)
{
	t_l_out		widths;
	struct stat	stats;

	lstat(path, &stats);
	if ((S_ISLNK(stats.st_mode)))
	{
		files->name = path;
		files->next->name = NULL;
		ft_set_cols(files, &widths, path);
		ft_read_list(files, NULL, widths);
		return ;
	}
	ft_set_cols(files, &widths, path);
	ft_mini_printf("total %d\n", widths.blocks);
	while (files->name != NULL)
	{
		ft_read_list(files, path, widths);
		files = files->next;
	}
}