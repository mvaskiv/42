#include "includes/libft.h"

char 	*ft_string_of_zeros(char * string, int precision)
{
	int		i;

	i = 0;
	while (i < precision && !(ft_isalnum(string[i])))
		((char *)string)[i++] = (char)'0';
	return (string);
}