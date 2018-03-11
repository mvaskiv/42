/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:48:27 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 14:48:27 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_help_by_date(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp;

	temp = *files;
	if (((flag->r == 0 ?
		(ft_strcmp((*files)->name, new->name) < 0) :
			(ft_strcmp((*files)->name, new->name) > 0)) &&
				(new->data->time == (*files)->data->time)))
	{
		new->next = temp->next;
		temp->next = new;
	}
	else
	{
		while ((temp->next != NULL) && (new->data->time != temp->next->data->time))
			temp = temp->next;
		while (temp->next != NULL &&
			(temp->next->data->time == new->data->time) && (flag->r == 0 ?
				(ft_strcmp(temp->next->name, new->name) < 0) :
					ft_strcmp(temp->next->name, new->name) > 0))
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
}

int			ft_check_same_time(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp;

	temp = *files;
	while (temp != NULL)
	{
		if (new->data->time == temp->data->time)
		{
			ft_help_by_date(files, new, flag);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void		ft_insert_file_by_date(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp;

	if (*files != NULL)
	{
		if ((ft_check_same_time(files, new, flag)))
			return ;
	}
	if (*files == NULL || ((flag->r == 0 ?
		((*files)->data->time < new->data->time) :
			((*files)->data->time > new->data->time))))
	{
		new->next = *files;
		*files = new;
	}
	else
	{
		temp = *files;
		while (temp->next != NULL && ((flag->r == 0 ?
			(temp->next->data->time > new->data->time) :
				(temp->next->data->time < new->data->time))))
			temp = temp->next;
		new->next = temp->next;
		temp->next = new;
	}
}

void		ft_insert_file(t_files **files, t_files *new, t_flags *flag)
{
	t_files		*temp;

	if (*files == NULL || (flag->r == 0 ?
		(ft_strcmp((*files)->name, new->name) > 0) :
			(ft_strcmp((*files)->name, new->name) < 0)))
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
	struct dirent	*directory;
	t_files			**start;

	start = files;
	while ((directory = readdir(dir)))
	{
		while (flag->a != 1 && directory->d_name[0] == '.')
		{
			directory = readdir(dir);
			if (directory == NULL)
				return ;
		}
		(flag->t == 0) ? ft_insert_file(start, ft_new_node(directory, path), flag) :
		ft_insert_file_by_date(start, ft_new_node(directory, path), flag);
	}
}
