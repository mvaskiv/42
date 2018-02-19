
#include "includes/libft.h"

int 	ft_longest_tab(char **arr)
{
	int 	i;
	int		j;

	j = 0;
	i = 0;
	while (arr[j])
	{
		if (ft_strlen(arr[j]) > i)
			i = ft_strlen(arr[j]);
		j++;
	}
	return (i);
}
