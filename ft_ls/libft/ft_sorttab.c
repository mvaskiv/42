
#include "includes/libft.h"

char		**ft_sorttab(char **arr_s)
{
	int 	i;
	int 	j;
	char 	*tmp = NULL;
	char 	**arr;

	j = 0;
	i = 0;
	arr = arr_s;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (ft_strcmp(arr[j], arr[i]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
//				ft_strdel(&tmp);
			}
			j++;
		}
		i++;
	}
	return (arr);
}
