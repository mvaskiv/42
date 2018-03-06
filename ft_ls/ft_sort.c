#include "ft_ls.h"

void		ft_sort_bydate(t_files **files, t_flags flag)
{
	t_files			*temp = NULL;
	t_files			**start = NULL;
	t_data			*swap_d = NULL;
	char 			*swap_n = NULL;
	char 			*swap_p = NULL;

	start = files;
	temp = *files;
	while (temp->name != NULL && temp->next->name != NULL)
	{
		if ((flag.r == 0 ? (temp->data->moddate < temp->next->data->moddate) :
			 (temp->data->moddate > temp->next->data->moddate)))
		{
			swap_d = temp->data;
			swap_n = temp->name;
			swap_p = temp->path;
			temp->data = temp->next->data;
			temp->name = temp->next->name;
			temp->path = temp->next->path;
			temp->next->name = swap_n;
			temp->next->path = swap_p;
			temp->next->data = swap_d;
			ft_sort_bydate(start, flag);
		}
		temp = temp->next;
	}
}

void		ft_sort_list(t_files **files, t_flags flag)
{
	t_files			*temp = NULL;
	t_files			**start = NULL;
	t_data			*swap_d = NULL;
	char 			*swap_n = NULL;
	char 			*swap_p = NULL;
	int 			i;

	i = 0;
	start = files;
	temp = *files;
	while ((temp->name != NULL) && (temp->next->name != NULL))
	{
		if ((flag.r == 0 ? (ft_strcmp(temp->name, temp->next->name) > 0) :
			 (ft_strcmp(temp->name, temp->next->name) < 0)))
		{
			swap_d = temp->data;
			swap_n = temp->name;
			swap_p = temp->path;
			temp->data = temp->next->data;
			temp->name = temp->next->name;
			temp->path = temp->next->path;
			temp->next->name = swap_n;
			temp->next->path = swap_p;
			temp->next->data = swap_d;
			i++;
			ft_sort_list(start, flag);
		}
		temp = temp->next;
	}
}