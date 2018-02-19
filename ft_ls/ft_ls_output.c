
#include "ft_ls.h"
//
//void		ft_output(char *string, int win_width) {
//	int c;
//	int i;
//	int j;
//	int jj = 0;
//	int n;
//	int r;
//	int q = 0;
//	int w = 0;
//	char **arr;
//
//	i = 0;
//	r = 1;
//	n = 0;
//	j = 0;
//	c = 1;
//	arr = ft_strsplit(string, '\t');
//	arr = ft_sorttab(arr);
//	while (arr[j] != NULL) {
//		if (ft_strlen(arr[j]) > i)
//			i = ft_strlen(arr[j]);
//		j++;
//	}
//	j = 0;
//	while (arr[j])
//		j++;
//	if ((i % 8) == 0)
//		i += 8;
//	else
//		while ((i % 8) != 0)
//			i++;
//	if (win_width > (i * j))
//		c = 0;
//	else {
//		c = (win_width / (i)) ? (win_width / (i)) : 1;
//	}
////	c = 2;
//	jj = j;
//	if (c != 0)
//		while (jj % c)
//			jj++;
//	if (c == 0)
//		while (arr[n])
//			ft_mini_printf("%-*s", i, arr[n++]);
//	while (arr[n])
//	{
//		if (arr[n]) {
//			ft_mini_printf("%-*s", i, arr[n]);
//			w++;
//		}
//		n += (jj / c);
//		if (!arr[n])
//			q = (c - 1);
//		q++;
//		if (q >= c) {
//			if (w == j)
//				break ;
//			ft_mini_printf("\r\n");
//			n = r++;
//			q = 0;
//		}
//	}
//	ft_mini_printf("\n");
//}

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


static void	ft_output_columns(char **table, t_output stock)
{
	int 	i;
	int 	q;

	i = 0;
	q = 0;
	while (table[i])
	{
		if (stock.words == stock.word_count)
			break ;
		if (table[i])
		{
			ft_mini_printf("%-*s", stock.true_width, table[i]);
			stock.words++;
		}
		i += (stock.order / stock.columns);
		if (!table[i])
			q = (stock.columns - 1);
		if (++q >= stock.columns)
		{
			ft_mini_printf("\r\n");
			i = stock.rows++;
			q = 0;
		}
	}
}

static void	ft_set_stock(t_output *stock, char **table, int win_width)
{
	stock->rows = 1;
	stock->words = 0;
	stock->word_count = 0;
	stock->min_width = ft_longest_tab(table);
	stock->true_width = ft_true_width(stock->min_width);
	while (table[++stock->word_count]);
	stock->columns = ft_columns_number(stock->word_count, stock->min_width, win_width);
	stock->order = stock->word_count;
	if (stock->columns > 1)
		while (stock->order++ % stock->columns);
}

void		ft_ls_output(char *string, int win_width)
{
	t_output	stock;
	char 		**table = NULL;
	int 		i;

	i = 0;
	table = ft_sorttab(ft_strsplit(string, '\t'));
	ft_set_stock(&stock, table, win_width);
	if (stock.columns == 0)
		while (table[i])
			ft_mini_printf("%-*s", stock.true_width, table[i++]);
	if (stock.columns == 1)
		while (table[i])
			ft_mini_printf("%-*s\n", stock.true_width, table[i++]);
	if (stock.columns > 1)
		ft_output_columns(table, stock);
//	ft_mini_printf("\n");
}