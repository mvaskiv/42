/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:39:38 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/12 12:16:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_initialize(t_flags *flags)
{
	flags->one = 0;
	flags->a = 0;
	flags->l = 0;
	flags->f = 0;
	flags->g = 0;
	flags->gh = 0;
	flags->r = 0;
	flags->rh = 0;
	flags->t = 0;
	flags->folders = 0;
}

void		ft_set_stock(t_output *stock, t_files *files, int win_width)
{
	int		i;
	int		j;

	stock->rows = 1;
	stock->words = 0;
	stock->word_count = 0;
	stock->min_width = ft_high_namlen(files, 0);
	stock->true_width = ft_true_width(stock->min_width);
	stock->word_count = ft_high_namlen(files, 1);
	i = stock->word_count;
	j = stock->min_width;
	stock->columns = ft_columns_number(i, j, win_width);
	stock->order = stock->word_count;
	if (stock->columns > 1)
		while (stock->order % stock->columns)
			stock->order++;
}

int			ft_count_folders(char **argv, int i,
	int argc, char **files)
{
	struct stat	stat;
	int			f;
	int			n;

	n = 0;
	f = 0;
	while (argv[i] && (argv[i][0] != '-') && i < argc)
	{
		if ((lstat(argv[i], &stat)) < 0)
		{
			ft_mini_printf("ft_ls: %s: No such file or directory\n", argv[i]);
			n++;
		}
		else
		{
			if (S_ISDIR(stat.st_mode))
				n++;
			else if (S_ISREG(stat.st_mode))
				files[f++] = argv[i];
		}
		i++;
	}
	files[f] = NULL;
	return (n);
}

void		ft_free_lst(t_files **files)
{
	t_files		*temp;
	t_files		*rem;

	temp = *files;
	rem = temp;
	while (rem)
	{
		temp = rem;
		rem = temp->next;
		if (temp->name != NULL)
		{
			ft_strdel(&temp->name);
			ft_strdel(&temp->path);
			free(temp->data);
		}
		free(temp);
	}
}

t_files		*ft_new_node(struct dirent *directory, char *path)
{
	t_files		*new;

	new = (t_files *)malloc(sizeof(t_files));
	new->data = (t_data*)malloc(sizeof(t_data));
	new->name = ft_strdup(directory->d_name);
	new->data->namlen = directory->d_namlen;
	ft_write_stats(&new, path);
	new->next = NULL;
	return (new);
}
