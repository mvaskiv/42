
#include "ft_ls.h"

static void	ft_output_columns(char **table, t_output stock)
{
	int 	i;
	int 	q;

	i = 0;
	q = 0;
	while (table[i])
	{
		if (table[i])
		{
			ft_mini_printf("%-*s", stock.true_width, table[i]);
			stock.words++;
		}
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
}

char		**ft_list_to_arr(t_files *files, t_output stock)
{
	char 	**arr;
	int 	i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * stock.word_count + 1);
	while (files)
	{
		arr[i] = ft_strdup(files->name);
		files = files->next;
		i++;
	}
	arr[i + 1] = NULL;
	return (arr);
}

void		ft_ls_output(t_flags *flag, t_files *files, int win_width)
{
	t_output	stock;
	int 		i;

	i = 0;

//	win_width = 82;

	ft_set_stock(&stock, files, win_width);
	if (stock.columns == 0)
	{
		while (files->name != NULL)
		{
			ft_mini_printf("%-*s", stock.true_width, files->name);
			files = files->next;
		}
		ft_putchar('\n');
	}
	if (stock.columns == 1)
	{
		while (files->name != NULL)
		{
			ft_mini_printf("%s\n", files->name);
			files = files->next;
		}
	}
	if (stock.columns > 1)
	{
		ft_output_columns(ft_list_to_arr(files, stock), stock);
		ft_putchar('\n');
	}
}