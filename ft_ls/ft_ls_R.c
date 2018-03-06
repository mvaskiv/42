#include "ft_ls.h"
//
//t_files		**ft_insert_folder(t_files **folders_o, t_files *file)
//{
//	t_files		*temp = NULL;
//	t_files		*folders;
////	temp = *files;
//	folders = *folders_o;
//	if (folders == NULL)
//	{
//		folders = (t_files*)malloc(sizeof(t_files));
//		folders->name = file->name;
//		folders->path = file->path;
//		folders->data = file->data;
//		return (folders_o);
////		folders->next = NULL;
//	}
//	else
//	{
//		while (folders->next != NULL)
//			folders = folders->next;
//		folders->next = (t_files*)malloc(sizeof(t_files));
//		folders = folders->next;
//		folders->name = file->name;
//		folders->path = file->path;
//		folders->data = file->data;
//		return (folders_o);
//	}
//}

t_files		*ft_find_folders(t_files *files, t_files **folders_o, char *path)
{
	int 		i;
	t_files		*folders = NULL;
	t_files		*start = NULL;

	i = 0;
	folders = (t_files *)malloc(sizeof(t_files));
	start = folders;
	while (files != NULL)
	{
		if (S_ISDIR(files->data->mode))
		{
			folders = (t_files *)malloc(sizeof(t_files));
			folders->data = (t_data*)malloc(sizeof(t_data));
			folders->name = files->name;
			folders->path = files->path;
			folders->data = files->data;
			folders->next = NULL;
			folders = folders->next;
			i++;
		}
		files = files->next;
	}
	return (folders);
}

void 		ft_ls_do(t_files *the, t_flags *magic, char *mother, int fucker)
{
	t_files			*folders = NULL;
	char 			*path = NULL;
	DIR				*dir;

//	magic->folders = 1;
	folders = ft_find_folders(the, &folders, mother);
//	ft_sort_list(&folders, *magic);
	while (folders != NULL)
	{
		path = ft_get_path(folders->name, mother);
		ft_putchar('\n');
		if ((dir = opendir(path)))
			ft_ls_core(magic, dir, fucker, path);
		ft_strdel(&path);
		magic->folders--;
		folders = folders->next;
	}
}