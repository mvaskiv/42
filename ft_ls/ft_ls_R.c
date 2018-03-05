#include "ft_ls.h"

static int	ft_find_folders(t_files *files, t_files **folders, char *path)
{
	t_files	*temp = NULL;
	t_files	**start = NULL;
	t_files		*files_t;
	int 		i;

	i = 0;
	files_t = files;
	while (files_t->name != NULL)
	{
		start = folders;
		temp = *folders;
		ft_write_stats(&files_t, path);
		if (S_ISDIR(files_t->data->mode))
		{
			temp = (t_files*)malloc(sizeof(t_files));
			temp->name = NULL;
			temp->name = files_t->name;
			i++;
			temp->next = *start;
			*folders = temp;
			temp = *folders;
			temp = temp->next;
		}
		files_t = files_t->next;
	}
	return (i);
}

void 		ft_ls_do(t_files *the, t_flags *magic, char *mother, int fucker)
{
	t_files			*folders = NULL;
	char 			*path = NULL;
	DIR				*dir;

	folders = (t_files*)malloc(sizeof(t_files));
	folders->name = NULL;
	folders->next = NULL;
	magic->folders = 1;
	magic->folders += ft_find_folders(the, &folders, mother);
	ft_sort_list(&folders, *magic);
	while (folders->name != NULL)
	{
		path = ft_get_path(folders->name, mother);
		if ((dir = opendir(path)))
			ft_ls_core(magic, dir, fucker, path);
		ft_strdel(&path);
		folders = folders->next;
	}
}