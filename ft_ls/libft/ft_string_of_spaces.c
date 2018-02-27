#include "includes/libft.h"

char 	*ft_string_of_spaces(int size)
{
	char	*str = NULL;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		((char *)str)[i++] = (char)' ';
	str[i] = '\0';
	return (str);
}
