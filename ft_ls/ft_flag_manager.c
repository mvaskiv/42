
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

void		ft_write_stats(t_files **files, char *path_a)
{
	t_files		*temp = NULL;
	char 		*path = NULL;

	temp = *files;
	path = ft_strdup(path_a);
	ft_strdel(&path_a);
	path = ft_alter_path(&path, temp->name);
	lstat(path, &temp->stats);
	temp->time = localtime(&temp->stats.st_mtimespec.tv_sec);
	temp->grp = getgrgid(temp->stats.st_gid);
}

void		ft_free_lst(t_files **files)
{
	t_files		*temp;
	t_files		*rem;

	temp = *files;
	rem = temp;
	while (rem)
	{
		temp = rem;
		rem = temp->next;
		if (temp->name != NULL)
			ft_strdel(&temp->name);
		free(temp);
	}
}

void 	ft_ls_core(t_flags *flag, DIR *dir, int winsize, char *path)
{
	t_files			*files;

	files = (t_files*)malloc(sizeof(t_files));
	files->name = NULL;
	files->next = NULL;
	if (flag->r == 1)
		files->moddate = 9999999999;
	else
		files->moddate = 0;
	ft_write_names(&files, dir, *flag);
	ft_sort_list(&files, *flag);
	if (flag->folders-- > 1)
		ft_mini_printf("%s:\n", ((ft_strstr(path, getenv("PWD")) > 0 ? ft_strjoin(".", path + ft_strlen(getenv("PWD"))) : path)));
	if (flag->t == 1)
		ft_sort_bydate(&files, *flag);
	if (flag->l == 1)
		ft_ls_l_output(files, path);
	if ((flag->l != 1))
		ft_ls_output(files, (flag->one == 1 ? 0 : winsize));
	ft_mini_printf( ((flag->folders > 0 || flag->R == 1) ? "\n" : "%c"), '\0');
	if (flag->R == 1)
		ft_ls_do(files, flag, path, winsize);
	closedir(dir);
	ft_free_lst(&files);
}