#include "ft_ls.h"

void		ft_insert_folder(t_files **folders, t_files *files)
{
	t_files		*temp = NULL;
	t_files		*new = NULL;

	new = (t_files*)malloc(sizeof(t_files));
	new->name = ft_strdup(files->name);
	new->path = ft_strdup(files->path);
	new->data = files->data;
	new->next = NULL;
	if ((*folders) == NULL)
	{
		(*folders) = new;
		(*folders)->next = NULL;
	}
	else
	{
		temp = *folders;
		while ((*folders)->next != NULL)
			(*folders) = (*folders)->next;
		(*folders)->next = new;
		*folders = temp;
	}
}

t_files		*ft_find_folders(t_files *files, char *path, t_flags *flag)
{
	int 		i;
	t_files		*folders = NULL;;

	i = 0;
	while (files != NULL)
	{
		while ((files->name[0] == '.' && files->name[1] == '\0') ||
				(files->name[0] == '.' && files->name[1] == '.'))
		{
			files = files->next;
			if (files == NULL)
				break ;
		}
		if (files == NULL)
			break ;
		if (S_ISDIR(files->data->mode))
		{
			ft_insert_folder(&folders, files);
			i++;
		}
		files = files->next;
	}
	flag->folders += i;
	return (folders);
}

//void		ft_free_node(t_files **files)
//{
//	t_files		*temp;
//	t_files		*rem;
//
//	temp = *files;
//	rem = temp;
//	rem = temp->next;
//	if (temp->name != NULL)
//	{
//		ft_strdel(&temp->name);
//		ft_strdel(&temp->path);
//		free(temp->data);
//	}
//	free(temp);
//	temp = rem;
//}

void 		ft_ls_do(t_files *the, t_flags *magic, char *mother, int fucker)
{
	t_files			*folders = NULL;
	DIR				*dir = NULL;

	if (!(folders = ft_find_folders(the, mother, magic)))
		return ;
	while (folders != NULL)
	{
		ft_putchar('\n');
		if ((dir = opendir(folders->path)))
			ft_ls_core(magic, dir, fucker, folders->path);
		magic->folders--;
		ft_strdel(&folders->name);
		ft_strdel(&folders->path);
//		free(folders->data);
		free (folders);
		folders = folders->next;
	}
	free(folders);
	folders = NULL;
}