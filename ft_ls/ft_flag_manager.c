
#include "ft_ls.h"

void 	ft_scan_flags(t_flags *flags, char **arg, int argc)
{
	int 	i;

	i = 0;
	while (i <= argc && arg[i][0] == '-')
	{
		flags->one = ft_strchr(arg[i], '1') ? 1 : 0;
		flags->a = ft_strchr(arg[i], 'a') ? 1 : 0;
		flags->l = ft_strchr(arg[i], 'l') ? 1 : 0;
		flags->r = ft_strchr(arg[i], 'r') ? 1 : 0;
		flags->R = ft_strchr(arg[i], 'R') ? 1 : 0;
		flags->t = ft_strchr(arg[i], 't') ? 1 : 0;
		if (arg[++i][0] != '-')
			break ;
	}
}

void 	ft_ls_core(t_flags flag, DIR *dir)
{
	struct dirent	*directory;
	t_files			*files;
	int 	i;

	i = 0;
	files = (t_files*)malloc(sizeof(t_files));
	files->name = NULL;
	files->next = NULL;
	ft_write_names(&files, dir, flag);
	ft_sort_list(&files, flag);
	if (flag.t == 1)
		ft_sort_bydate(&files, flag);
	if (flag.l == 1)
		ft_ls_l_output(files);
	closedir(dir);
}