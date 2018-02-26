
#include "ft_ls.h"

void 	ft_scan_flags(t_flags *flags, char **arg, int argc)
{
	int 	i;

	i = 1;
	if (argc > 1)
	{
		while (arg[i])
		{
			if (arg[i][0] != '-')
				break;
			else
			{
				flags->one = ft_strchr(arg[i], '1') ? 1 : flags->one;
				flags->a = ft_strchr(arg[i], 'a') ? 1 : flags->a;
				flags->l = ft_strchr(arg[i], 'l') ? 1 : flags->l;
				flags->r = ft_strchr(arg[i], 'r') ? 1 : flags->r;
				flags->R = ft_strchr(arg[i], 'R') ? 1 : flags->R;
				flags->t = ft_strchr(arg[i], 't') ? 1 : flags->t;
			}
			i++;
		}
	}
}

void 	ft_ls_core(t_flags flag, DIR *dir, int winsize)
{
	struct dirent	*directory;
	t_files			*files;
	int 	i;

	i = 0;
	files = (t_files*)malloc(sizeof(t_files));
	files->name = NULL;
	files->next = NULL;
	if (flag.r == 1)
		files->moddate = 9999999999;
	else
		files->moddate = 0;
	ft_write_names(&files, dir, flag);
	ft_sort_list(&files, flag);
	if (flag.t == 1)
		ft_sort_bydate(&files, flag);
	//if (flag.R == 1)
	//	do magic ;
//	if (flag.l == 1)
//		ft_ls_l_output(files);
	if ((flag.l != 1) && (flag.R != 1))
		ft_ls_output(files, (flag.one == 1 ? 0 : winsize));
	closedir(dir);
}