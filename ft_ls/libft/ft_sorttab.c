
#include "includes/libft.h"

char		**ft_sorttab(char **arr)
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
			if (ft_strcmp(arr[j], arr[i]) > 0)
			{
				tmp = ft_strdup(arr[i]);
				ft_strclr(arr[i]);
				arr[i] = ft_strdup(arr[j]);
				ft_strclr(arr[j]);
				arr[j] = ft_strdup(tmp);
				ft_strdel(&tmp);
			}
			j++;
		}
		i++;
	}
	return (arr);
}
