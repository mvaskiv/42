
#include "includes/libft.h"

char		**ft_sortrtab(char **arr)
{
	int 	i;
	int 	j;
	char 	*tmp = NULL;

	j = 0;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if (ft_strcmp(arr[j], arr[i]) < 0)
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
	arr[i] = NULL;
	return (arr);
}
