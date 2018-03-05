#include "ft_ls.h"

void		ft_sort_bydate(t_files **files, t_flags flag)
{
	t_files		*temp = NULL;
	t_data		*swap_d = NULL;
	t_files		**start = NULL;

	start = files;
	temp = *files;
	while (temp->next)
	{
		if ((flag.r == 0 ? (temp->data->moddate < temp->next->data->moddate) :
			 (temp->data->moddate > temp->next->data->moddate)))
		{
			swap_d = temp->data;
			temp->data = temp->next->data;
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

	start = files;
	temp = *files;
	while (temp->data->name != NULL && temp->next->data)
	{
		if ((flag.r == 0 ? (ft_strcmp(temp->data->name, temp->next->data->name) > 0) :
			 (ft_strcmp(temp->data->name, temp->next->data->name) < 0)))
		{
			swap_d = temp->data;
			temp->data = temp->next->data;
			temp->next->data = swap_d;
			ft_sort_list(start, flag);
		}
		temp = temp->next;
	}
}