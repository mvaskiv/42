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
	int 	columns;

	columns = 0;
	min_width = ft_true_width(min_width);
	if (win_width > (min_width * word_count))
		columns = 0;
	else
		columns = (win_width / min_width) ? (win_width / min_width) : 1;
	return (columns);
}

void			ft_set_cols(t_files *files, t_l_out *width, char *path)
{
	t_files			*temp;

	temp = files;
	width->n_us = 0;
	width->n_sl = 0;
	width->n_gr = 0;
	width->n_sz = 0;
	width->blocks = 0;
	while (temp->data->name != NULL)
	{
//		grp = getgrgid(temp->data->stats.st_gid);
		ft_write_stats(&temp, path);
		if ((int)ft_nbrlen(temp->data->stats.st_nlink) > width->n_sl)
			width->n_sl = ft_nbrlen(temp->data->stats.st_nlink);
		if (ft_strlen(ft_get_uname(temp->data->stats.st_uid)) > width->n_us)
			width->n_us = ft_strlen(ft_get_uname(temp->data->stats.st_uid));
		if (ft_strlen(temp->data->grp->gr_name) > width->n_gr)
			width->n_gr = ft_strlen(temp->data->grp->gr_name);
		if ((int)ft_nbrlen(temp->data->stats.st_size) > width->n_sz)
			width->n_sz = ft_nbrlen(temp->data->stats.st_size);
		width->blocks += temp->data->stats.st_blocks;
		temp = temp->next;
	}
}


int 		ft_high_namlen(t_files *files, int type)
{
	t_files		*temp;
	int			i;
	int 		j;

	i = 0;
	j = 0;
	temp = files;
	while (temp)
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
