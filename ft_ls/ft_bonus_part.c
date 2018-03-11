/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:25:19 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 19:25:19 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_insert_unsorted(t_files **folders, t_files *new)
{
	t_files		*temp;

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

void		ft_write_dont_sort(t_files **files, DIR *dir, t_flags *flag,
							char *path)
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
		ft_insert_unsorted(start, ft_new_node(directory, path));
	}
}