
#include "ft_ls.h"

char		**ft_list_to_arr(t_files *files, t_output stock)
{
	char 	**arr = NULL;
	int 	i;

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
	int 	i;
	int 	q;
	char 	**table = NULL;

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
		if (i >=  stock.word_count)
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

void		ft_ls_output(t_files *files, t_flags *flag, int win_width)
{
	t_output	stock;

	ft_set_stock(&stock, files, win_width);
	if (stock.columns == 0)
	{
		while (files != NULL)
		{
			ft_mini_printf("%-*s", stock.true_width, files->name);
			files = files->next;
		}
		if (flag->R == 1)
		{
			if (files != NULL)
				ft_putchar('\n');
		}
		else
			ft_putchar('\n');
	}
	if (stock.columns == 1)
	{
		while (files != NULL)
		{
			ft_mini_printf("%s\n", files->name);
			files = files->next;
		}
	}
	if (stock.columns > 1)
	{
		ft_output_columns(files, stock);
		ft_putchar('\n');
	}
}