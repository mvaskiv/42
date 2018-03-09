
#include "ft_ls.h"

static t_files		*ft_new_node(struct dirent *directory, char *path)
{
	t_files		*new = NULL;

	new = (t_files *)malloc(sizeof(t_files));
	new->data = (t_data*)malloc(sizeof(t_data));
	new->name = ft_strdup(directory->d_name);
	new->data->namlen = directory->d_namlen;
	ft_write_stats(&new, path);
	new->next = NULL;
	return (new);
}

void		ft_insert_file_by_date(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp = NULL;

	if (*files == NULL || (flag->r == 0 ?
		((*files)->data->moddate < new->data->moddate) :
						  ((*files)->data->moddate > new->data->moddate)))
	{
		new->next = *files;
		*files = new;
	}
	else
	{
		temp = *files;
		while (temp->next != NULL && (flag->r == 0 ?
			(temp->data->moddate > new->data->moddate) :
				(temp->data->moddate < new->data->moddate)))
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
}

void		ft_insert_file(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp = NULL;

	if (*files == NULL || (flag->r == 0 ?
		(ft_strcmp((*files)->name, new->name) > 0) :
			ft_strcmp((*files)->name, new->name) < 0))
	{
		new->next = *files;
		*files = new;
	}
	else
	{
		temp = *files;
		while (temp->next != NULL && (flag->r == 0 ?
			(ft_strcmp(temp->next->name, new->name) < 0) :
				ft_strcmp(temp->next->name, new->name) > 0))
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
}

void		ft_write_n_sort(t_files **files, DIR *dir, t_flags *flag, char *path)
{
	struct dirent	*directory = NULL;
	t_files			**start = NULL;

	start = files;
	while ((directory = readdir(dir)))
	{
		while (flag->a != 1 && directory->d_name[0] == '.')
		{
			directory = readdir(dir);
			if (directory == NULL)
				return;
		}
		(flag->t == 0) ? ft_insert_file(start, ft_new_node(directory, path), flag) :
		ft_insert_file_by_date(start, ft_new_node(directory, path), flag);
	}
}