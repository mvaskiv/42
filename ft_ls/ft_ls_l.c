
#include "ft_ls.h"

char 	*ft_get_uname(uid_t uid)
{
	struct passwd	*passwd = NULL;

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

void 			ft_sticky_bit(t_files *files)
{
	if (files->data->mode & S_ISVTX)
		ft_mini_printf("t");
	else if (files->data->mode & S_IXOTH)
		ft_mini_printf("x");
	else
		ft_mini_printf("-");
}

void			ft_read_list(t_files *files, char *path, t_l_out width)
{
	struct group		*gr = NULL;
	struct tm		*tm = NULL;

	tm = localtime(&files->data->time);
	gr = getgrgid(files->data->group);
	ft_print_type(files);
	ft_mini_printf( (files->data->mode & S_IRUSR) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWUSR) ? "w" : "-");
	ft_mini_printf( (files->data->mode & S_IXUSR) ? "x" : "-");
	ft_mini_printf( (files->data->mode & S_IRGRP) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWGRP) ? "w" : "-");
	ft_mini_printf( (files->data->mode & S_IXGRP) ? "x" : "-");
	ft_mini_printf( (files->data->mode & S_IROTH) ? "r" : "-");
	ft_mini_printf( (files->data->mode & S_IWOTH) ? "w" : "-");
	ft_sticky_bit(files);
	ft_read_ext_perm(files->path);
	ft_mini_printf("%*d ", width.n_sl, files->data->link);
	ft_mini_printf("%-*s", (width.n_us + 2), ft_get_uname(files->data->user));
	ft_mini_printf("%-*s", (width.n_gr + 1), gr->gr_name);
	ft_mini_printf("%*d", (width.n_sz + 1), files->data->size);
	ft_mini_printf(" %s %2i %02i:%02i", ft_month(tm->tm_mon), tm->tm_mday, tm->tm_hour, tm->tm_min);
	ft_mini_printf(" %s", files->name);
	ft_read_link(files);
	ft_putchar('\n');
}

void		ft_write_l_stats(t_files **files, char *path_a)
{
	t_files		*temp = NULL;
	char 		*path = NULL;
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
//	ft_strdel(&path);
}

void	ft_ls_l_output(t_files *temp, char *path)
{
	t_l_out		widths;
	struct stat	stats;
	t_files		*one_for_link = NULL;
	t_files		*files= temp;

	lstat(path, &stats);
	if ((S_ISLNK(stats.st_mode)))
	{
		one_for_link = (t_files *)malloc(sizeof(t_files));
		one_for_link->data = (t_data *)malloc(sizeof(t_data));
		one_for_link->name = path;
		ft_write_l_stats(&one_for_link, path);
		ft_set_cols(one_for_link, &widths);
		ft_read_list(one_for_link, NULL, widths);
		free(one_for_link->data);
		free(one_for_link->path);
		free(one_for_link);
		one_for_link = NULL;
		return ;
	}
	ft_set_cols(files, &widths);
	ft_mini_printf("total %d\n", widths.blocks);
	while (files != NULL)
	{
		ft_read_list(files, path, widths);
		files = files->next;
	}
}