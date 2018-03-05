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
	path = ft_alter_path(&path_a, temp->data->name);
	lstat(path, &temp->data->stats);
	temp->data->time = localtime(&temp->data->stats.st_mtimespec.tv_sec);
	temp->data->grp = getgrgid(temp->data->stats.st_gid);
}

void		ft_write_names(t_files **files, DIR *dir, t_flags flag)
{
	t_files			*temp;
	t_files			**start;
	struct dirent	*directory;

	while ((directory = readdir(dir)))
	{
		start = files;
		temp = *files;
		temp = (t_files *)malloc(sizeof(t_files));
		temp->data = (t_data*)malloc(sizeof(t_data));
		while (flag.a != 1 && (char)directory->d_name[0] == '.')
		{
			directory = readdir(dir);
			if (directory == NULL)
				return ;
		}
		temp->data->name = ft_strdup(directory->d_name);
		lstat(directory->d_name, &temp->data->stats);
		temp->data->moddate = temp->data->stats.st_mtimespec.tv_sec; // or maybe st_mtimespec ???
		temp->data->time = localtime(&temp->data->stats.st_mtimespec.tv_sec);
		temp->data->namlen = directory->d_namlen;
		temp->data->grp = getgrgid(temp->data->stats.st_gid);
		temp->next = *start;
		*files = temp;
		temp = *files;
	}
}

void		ft_read_link(t_files *files, char *path)
{
	char 	*name;
	ssize_t	i;

	i = 0;
	if ((S_ISLNK(files->data->stats.st_mode)))
	{
		name = (char*) malloc(sizeof(char) * 100);
		i = readlink(path, name, 100);
		name[i] = '\0';
		ft_mini_printf(" -> %s", name);
		ft_strdel(&name);
	}
}

void 	ft_read_ext_perm(char *path)
{
	if ((listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0)
		ft_mini_printf("@ ");
	else if ((acl_get_link_np(path, ACL_TYPE_EXTENDED)) > 0)
		ft_mini_printf("+ ");
	else
		ft_mini_printf("  ");
}
