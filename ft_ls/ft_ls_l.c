
#include "ft_ls.h"

static char 	*ft_get_uname(uid_t uid)
{
	struct passwd	*passwd;

	passwd = getpwuid(uid);
	if (passwd != NULL)
		return (passwd->pw_name);
	else
		return (NULL);
}

//static char	*ft_time_convert(time_t timestamp)
//{
//	char		*buf;
//	struct tm	*time;
//
//	buf = (char*)malloc(sizeof(char) * 80);
//	time = localtime(&timestamp);
//	strftime(buf, 80, "%m %d %H:%M", time);
//	return (buf);
//}

//static int	ft_get_nlinks(struct dirent *directory)
//{
//	struct stat		stats;
//	int 			i;
//
//	i = 0;
//	while ()
//}

static char 	*ft_month(int month_n)
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
}

void			ft_set_cols(t_files *files, t_l_out *width, char *path)
{
	t_files			*temp;
	struct group	*grp;

	temp = files;
	width->n_us = 0;
	width->n_sl = 0;
	width->n_gr = 0;
	width->n_sz = 0;
	width->blocks = 0;
	while (temp->name != NULL)
	{
//		grp = getgrgid(temp->stats.st_gid);
		ft_write_stats(&temp, path);
		if (ft_nbrlen(temp->stats.st_nlink) > width->n_sl)
			width->n_sl = ft_nbrlen(temp->stats.st_nlink);
		if (ft_strlen(ft_get_uname(temp->stats.st_uid)) > width->n_us)
			width->n_us = ft_strlen(ft_get_uname(temp->stats.st_uid));
		if (ft_strlen(files->grp->gr_name) > width->n_gr)
			width->n_gr = ft_strlen(files->grp->gr_name);
		if (ft_nbrlen(temp->stats.st_size) > width->n_sz)
			width->n_sz = ft_nbrlen(temp->stats.st_size);
		width->blocks += temp->stats.st_blocks;
		temp = temp->next;
	}
}

static void			ft_print_type(t_files *files)
{
	if (files->stats.st_mode & S_IFIFO)
		ft_putchar('p');
	else if (S_ISDIR(files->stats.st_mode))
		ft_putchar('d');
//	if (files->stats.st_mode & S_IFBLK)
//		ft_putchar('b');
	else if (S_ISLNK(files->stats.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(files->stats.st_mode))
		ft_putchar('c');
	else if (S_ISSOCK(files->stats.st_mode))
		ft_putchar('s');
	else
		ft_putchar('-');
}

void			ft_read_list(t_files *files, char *path, t_l_out width)
{
	ft_write_stats(&files, path);
	path = ft_addchar(path, '/');
	path = ft_strjoin(path, files->name);
	ft_print_type(files);
	ft_mini_printf( (files->stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IWUSR) ? "w" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IXUSR) ? "x" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IWGRP) ? "w" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IXGRP) ? "x" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IROTH) ? "r" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IWOTH) ? "w" : "-");
	ft_mini_printf( (files->stats.st_mode & S_IXOTH) ? "x" : "-");
	ft_mini_printf( ((listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0) ? "@" : " ");
	ft_mini_printf(" ");
	ft_mini_printf("%*d ", width.n_sl, files->stats.st_nlink);
	ft_mini_printf("%-*s", (width.n_us + 1), ft_get_uname(files->stats.st_uid));
	ft_mini_printf("%*s", (width.n_gr + 1), files->grp->gr_name);
	ft_mini_printf("%*d", (width.n_sz + 2), files->stats.st_size);
	ft_mini_printf(" %s %i %02i:%02i", ft_month(files->time->tm_mon), files->time->tm_mday, files->time->tm_hour, files->time->tm_min);
	ft_mini_printf(" %s", files->name);
	ft_putchar('\n');
}

void	ft_ls_l_output(t_files *files, char *path)
{
	t_l_out		widths;

	ft_set_cols(files, &widths, path);
	ft_mini_printf("total %d\n", widths.blocks);
	while (files->name != NULL)
	{
		ft_read_list(files, path, widths);
		files = files->next;
	}
}