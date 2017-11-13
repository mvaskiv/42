
#include "libft.h"

char		*ft_strncat(char *dest, const char *src, unsigned int n)
{
		unsigned int	i;
		unsigned int	j;

		j = 0;
		i = 0;
		while (dest[j])
			j++;
		while (src[i] && i < n)
		{
			dest[j + i] = src[i];
			i++;
		}
		dest[j + i] = '\0';
		return (dest);
}
