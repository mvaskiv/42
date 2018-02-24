
#include "ft_ls.h"

static void 	ft_scan_flags(t_flags *flags, char *arg)
{
	int 	i;

	i = 0;
	while (arg[i++])
	{
		flags->a = ft_strchr(arg, 'a') ? 1 : 0;
		flags->l = ft_strchr(arg, 'l') ? 1 : 0;
		flags->r = ft_strchr(arg, 'r') ? 1 : 0;
		flags->R = ft_strchr(arg, 'R') ? 1 : 0;
		flags->t = ft_strchr(arg, 't') ? 1 : 0;
	}
}

void 	ft_flag_manager(t_flags flag, DIR *dir, char **argv, int argc)
{
	struct dirent	*directory;
	int 	i;

	i = 1;
	while (i <= argc)
		ft_scan_flags(&flag, argv[i++]);
	if (flag.l == 1)
		while ((directory = readdir(dir)))
			ft_read_list(directory, flag);

}