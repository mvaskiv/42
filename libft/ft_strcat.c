
#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
		unsigned int	i;
		unsigned int	j;

		j = 0;
		i = 0;
		while (dest[j])
			j++;
		while (src[i])
		{
			dest[j + i] = src[i];
			i++;
		}
		dest[j + i] = '\0';
		return (dest);
}
