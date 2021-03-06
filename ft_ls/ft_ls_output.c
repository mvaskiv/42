/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaskiv <mvaskiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:52:58 by mvaskiv           #+#    #+#             */
/*   Updated: 2018/03/12 12:16:14 by mvaskiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_list_to_arr(t_files *files, t_output stock)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * stock.word_count + 1);
	while (files)
	{
		arr[i] = files->name;
		files = files->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

static void	ft_output_columns(t_files *files, t_output stock)
{
	int		i;
	int		q;
	char	**table;

	table = ft_list_to_arr(files, stock);
	i = 0;
	q = 0;
	while (table[i])
	{
		if (table[i] && ++stock.words)
			ft_mini_printf("%-*s", stock.true_width, table[i]);
		if (stock.words >= stock.word_count)
			break ;
		i += (stock.order / stock.columns);
		if (i >= stock.word_count)
			q = (stock.columns - 1);
		if (++q >= stock.columns)
		{
			ft_mini_printf("\r\n");
			i = stock.rows++;
			q = 0;
		}
	}
	free(table);
}

void		ft_single_col(t_output stock, t_files *files, t_flags *flags)
{
	if (stock.columns == 0)
	{
		while (files != NULL)
		{
			ft_mini_printf("%-*s", stock.true_width, files->name);
			files = files->next;
		}
		ft_putchar('\n');
	}
	if (stock.columns == 1)
	{
		while (files != NULL)
		{
			flags->gh == 1 ?
			ft_write_color(files) :
			ft_mini_printf("%s\n", files->name);
			files = files->next;
		}
	}
}

void		ft_ls_output(t_files *files, int win_width, t_flags *flag)
{
	t_output	stock;

	if (files == NULL)
		return ;
	ft_set_stock(&stock, files, win_width);
	if (stock.columns <= 1)
		ft_single_col(stock, files, flag);
	else if (stock.columns > 1)
	{
		ft_output_columns(files, stock);
		ft_putchar('\n');
	}
	flag->folders--;
}
