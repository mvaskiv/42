#include "ft_ls.h"

static void	ft_find_folders(t_files *files, t_folder **folders, char *path)
{
	t_folder	*temp = NULL;
	t_folder	**start = NULL;
	t_files		*files_t;

	files_t = files;
	while (files_t->name != NULL)
	{
		start = folders;
		temp = *folders;
		ft_write_stats(&files_t, path);
		if (S_ISDIR(files_t->stats.st_mode))
		{
			temp = (t_folder*)malloc(sizeof(t_folder));
			temp->folder = NULL;
			temp->folder = files_t->name;
			temp->next = *start;
			*folders = temp;
			temp = *folders;
			temp = temp->next;
		}
		files_t = files_t->next;
	}
//	return (temp);
}

void 		ft_ls_do(t_files *the, t_flags magic, char *mother, int fucker)
{
	t_folder		*folders = NULL;

	folders = (t_folder*)malloc(sizeof(t_folder));
	folders->folder = NULL;
	folders->next = NULL;
	ft_find_folders(the, &folders, mother);
}