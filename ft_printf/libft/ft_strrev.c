
#include "includes/libft.h"

char		*ft_strrev(char *string)
{
	int 	i;
	int		j;
	char 	*output;

	i = 0;
	j = 0;
	output = ft_strnew(3);
	while (string[i] != '\0')
		string[i++];
	i--;
	while (i >= 0)
	{
		output[j] = (char)string[i];
		j++;
		i--;
	}
	output[j] = '\0';
	free(string);
	return (output);
}
