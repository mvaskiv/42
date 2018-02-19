
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

//static void	ft_print_columns(char **table, int word_count, int min_width, int columns)
//{
//	int		rows;
//	int 	order;
//	int 	words;
//	int 	i;
//	int 	q;
//
//	i = 0;
//	q = 0;
//	rows = 1;
//	words = 0;
//}

static void	ft_output_columns(char **table, int word_count,
								 int min_width, int columns)
{
	int		rows;
	int 	order;
	int 	words;
	int 	i;
	int 	q;

	i = 0;
	q = 0;
	rows = 1;
	words = 0;
	order = word_count;
	min_width = ft_true_width(min_width);
	while (order++ % columns);
	while (table[i])
	{
		if (table[i])
		{
			ft_mini_printf("%-*s", min_width, table[i]);
			words++;
		}
		i += (order / columns);
		if (!table[i])
			q = columns;
		if (++q >= columns)
		{
			if (words == word_count)
				break ;
			ft_mini_printf("\r\n");
			i = rows++;
			q = 0;
		}
	}
}


void		ft_ls_output(char *string, int win_width)
{
	char 	**table = NULL;
	int 	word_count;
	int 	min_width;
	int 	columns;
	int 	i = 0;

//	win_width = 82;

	table = ft_sorttab(ft_strsplit(string, '\t'));
	min_width = ft_longest_tab(table);
	word_count = 0;
	while (table[++word_count]);
	columns = ft_columns_number(word_count, min_width, win_width);
	if (columns == 0)
		while (table[i])
			ft_mini_printf("%-*s", ft_true_width(min_width), table[i++]);
	if (columns == 1)
		while (table[i])
			ft_mini_printf("%-*s\n", ft_true_width(min_width), table[i++]);
	if (columns > 1)
		ft_output_columns(table, word_count,
	min_width, columns);
//	ft_mini_printf("\n");
}