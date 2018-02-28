
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

static int	ft_true_width(int min_width)
{
	if ((min_width % 8) == 0)
		min_width += 8;
	else
		while ((min_width % 8) != 0)
			min_width++;
	return (min_width);
}

static int	ft_columns_number(int word_count, int min_width, int win_width)
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
		if (temp->namlen > i)
			i = temp->namlen;
		temp = temp->next;
		j++;
	}
	if (type == 0)
		return (i);
	else
		return (j);
}

static void	ft_set_stock(t_output *stock, t_files *files, int win_width)
{
	stock->rows = 1;
	stock->words = 0;
	stock->word_count = 0;
	stock->min_width = ft_high_namlen(files, 0);
	stock->true_width = ft_true_width(stock->min_width);
	stock->word_count = ft_high_namlen(files, 1) - 1;
	stock->columns = ft_columns_number(stock->word_count, stock->min_width, win_width);
	stock->order = stock->word_count;
	if (stock->columns > 1)
		while (stock->order++ % stock->columns);
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
//	arr[i + 1] = '\0';
	return (arr);
}

void		ft_ls_output(t_files *files, int win_width)
{
	t_output	stock;
	int 		i;

	i = 0;
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