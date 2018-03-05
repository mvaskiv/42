#include "ft_ls.h"

void		ft_initialize(t_flags *flags)
{
	flags->one = 0;
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->R = 0;
	flags->t = 0;
	flags->folders = 0;
}


void	ft_set_stock(t_output *stock, t_files *files, int win_width)
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

void 		ft_count_folders(char **argv, int i, t_flags *flags)
{
	while (argv[i] && (argv[i++][0] != '-'))
		flags->folders++;
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
//
//char			*ft_alter_path(char **path, char *name)
//{
//	int 	i;
//	char 	*str = NULL;
//
//	i = 0;
//	if (*path)
//		i = ft_strlen(*path);
//	str = (char*)malloc(sizeof(char) * (i + ft_strlen(name)));
//	ft_memmove(str, *path, i);
//	str[i] = '/';
//	ft_strcat(str, name);
//	return (str);
//}
