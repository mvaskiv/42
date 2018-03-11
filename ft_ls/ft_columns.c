/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_columns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:45 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/11 15:13:45 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_true_width(int min_width)
{
	if ((min_width % 8) == 0)
		min_width += 8;
	else
		while ((min_width % 8) != 0)
			min_width++;
	return (min_width);
}

int		ft_columns_number(int word_count, int min_width, int win_width)
{
	int		columns;

	columns = 0;
	min_width = ft_true_width(min_width);
	if (win_width > (min_width * word_count))
		columns = 0;
	else
		columns = (win_width / min_width) ? (win_width / min_width) : 1;
	return (columns);
}

void	ft_set_cols(t_files *files, t_l_out *width)
{
	t_files			*temp;
	struct group	*grp;

	temp = files;
	width->n_us = 0;
	width->n_sl = 0;
	width->n_gr = 0;
	width->n_sz = 0;
	width->blocks = 0;
	while (temp != NULL)
	{
		grp = getgrgid(temp->data->group);
		if ((int)ft_nbrlen(temp->data->link) > width->n_sl)
			width->n_sl = ft_nbrlen(temp->data->link);
		if (ft_strlen(ft_get_uname(temp->data->user)) > width->n_us)
			width->n_us = ft_strlen(ft_get_uname(temp->data->user));
		if (ft_strlen(grp->gr_name) > width->n_gr)
			width->n_gr = ft_strlen(grp->gr_name);
		if ((int)ft_nbrlen(temp->data->size) > width->n_sz)
			width->n_sz = ft_nbrlen(temp->data->size);
		width->blocks += temp->data->blocks;
		temp = temp->next;
	}
}

int		ft_high_namlen(t_files *files, int type)
{
	t_files	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = files;
	while (temp != NULL)
	{
		if (temp->data->namlen > i)
			i = temp->data->namlen;
		temp = temp->next;
		j++;
	}
	if (type == 0)
		return (i);
	else
		return (j);
}
