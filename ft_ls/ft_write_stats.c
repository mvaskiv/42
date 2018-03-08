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

char 		*ft_get_path(char *name, char *path)
{
	char	*fullname;
	int 	i;

	fullname = (char*)malloc(sizeof(char) * 1024);
	i = 0;
	if (path[0] == '/' && path[1] == '\0')
	{
		i = 1;
		fullname[0] = '/';
		while (*name)
			fullname[i++] = *name++;
		fullname[i] = '\0';
	}
	else
	{
		while (*path)
			fullname[i++] = *path++;
		if (fullname[i - 1] != '/')
			fullname[i++] = '/';
		while (*name)
			fullname[i++] = *name++;
		fullname[i] = '\0';
	}
	return (fullname);
}

void		ft_write_stats(t_files **files, char *path_a)
{
	t_files		*temp = NULL;
	char 		*path;
	struct stat	stats;

	temp = *files;
	path = ft_get_path(temp->name, path_a);
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
	ft_strdel(&path);
}

void		ft_write_names(t_files **files, DIR *dir, t_flags flag, char *path)
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
		temp->name = ft_strdup(directory->d_name);
		temp->data->namlen = directory->d_namlen;
		ft_write_stats(&temp, path);
		temp->next = *start;
		*files = temp;
		temp = *files;
	}
}

void		ft_read_link(t_files *files, char *path)
{
	char 	*name = NULL;
	ssize_t	i;

	i = 0;
	if ((S_ISLNK(files->data->mode)))
	{
		name = (char*) malloc(sizeof(char) * 100);
		i = readlink(files->path, name, 100);
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
