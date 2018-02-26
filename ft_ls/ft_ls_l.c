
#include "ft_ls.h"

static char 	*ft_get_uname(uid_t uid)
{
	struct passwd	*passwd;

	passwd = getpwuid(uid);
	return (passwd->pw_name);
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

void			ft_read_list(struct dirent *directory, t_flags flag)
{
	struct stat		stats;
	struct group	*grp;
	struct tm		*time;

	stat(directory->d_name, &stats);
	grp = getgrgid(stats.st_gid);
	time = localtime(&stats.st_birthtimespec.tv_sec);
	ft_mini_printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
	ft_mini_printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_mini_printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
	ft_mini_printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
	ft_mini_printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_mini_printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
	ft_mini_printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
	ft_mini_printf( (stats.st_mode & S_IROTH) ? "r" : "-");
	ft_mini_printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
	ft_mini_printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
	ft_mini_printf("%*d", 4, stats.st_nlink);
	ft_mini_printf(" %s ", ft_get_uname(stats.st_uid));
	ft_mini_printf(" %s", grp->gr_name);
	ft_mini_printf("%*d", 7, stats.st_size);
	ft_mini_printf(" %s %d %d:%d", ft_month(time->tm_mon), time->tm_mday, time->tm_hour, time->tm_min);
	ft_mini_printf(" %s", directory->d_name);
	ft_putchar('\n');
}